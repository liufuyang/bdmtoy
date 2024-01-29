#ifndef __REQUESTS_H__
#define __REQUESTS_H__

#include <cstdio>
#include <cstdint>
#include <cstdlib>

#include "bdmstuff.h"

enum enDataSz : uint32_t {
    sizeByte     = 1,
    sizeWord     = 2,
    sizeDword    = 4,   // <-- Default size.       CPU32 targets currently rely on this being the default
    sizeQword    = 8
};

/*
Virtual requests:

uint16_t *readRegister     ( uint32_t Register,                   enDataSz Size   = sizeDword )
uint16_t *writeRegister    ( uint32_t Register,  uint64_t  Data,  enDataSz Size   = sizeDword )

uint16_t *readMemory       ( uint32_t Address ,                   uint32_t Length = sizeDword )
uint16_t *writeMemory      ( uint32_t Address ,  uint64_t  Data,  uint32_t Length = sizeDword )
uint16_t *writeArrayMemory ( uint32_t Address ,  uint16_t *Data,  uint32_t Length = sizeDword )

*/

class requests
    : public iTarget {

    uint16_t buf[ 4096 ];

    // "payload"[[cmd], [cmd + data len, words], [data (if present)]]
public:
    explicit requests( bdmstuff & m )
        : iTarget( m ) { }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Setup and toys

    // This request has been changed since earlier firmwares. Sorry about that but it had to be done for future adapters
    // [cmd][cmd + data len, words][type][cfg mask][speed]
    uint16_t *setInterface(TAP_Config_host_t config)
    {
        buf[0] = TAP_DO_SETINTERFACE;
        buf[1] = TAP_Config_sz;
        buf[2] = config.Type;
        buf[3] = (config.cfgmask.Endian & 1) << 15;

        *(uint32_t *)&buf[4] = config.Frequency;
        return buf;
    }

    // [cmd][cmd + data len, words]
    uint16_t *initPort()
    {
        buf[0] = TAP_DO_TARGETINITPORT;
        buf[1] = 2;
        return buf;
    }

    // [cmd][cmd + data len, words]
    uint16_t *targetReady()
    {
        buf[0] = TAP_DO_TARGETREADY;
        buf[1] = 2;
        return buf;
    }

    // [cmd][cmd + data len, words]
    uint16_t *targetReset()
    {
        buf[0] = TAP_DO_TARGETRESET;
        buf[1] = 2;
        return buf;
    }

    uint16_t *targetStart()
    {
        buf[0] = TAP_DO_TARGETSTART;
        buf[1] = 2;
        return buf;
    }

    uint16_t *targetRelease()
    {
        buf[0] = TAP_DO_ReleaseTarg;
        buf[1] = 2;
        return buf;
    }


    // uint32_t runDamnit() { return wrk_sendOneshot( TAP_TargetRelease() ); }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Register commands

    virtual uint16_t *readRegister( uint32_t Register, enDataSz Size = sizeDword )
    {
        buf[0] = TAP_DO_READREGISTER;
        buf[1] = TAP_ReadReg_sz;
        buf[2] = (uint16_t)Register;
        buf[3] = (uint16_t)Size;
        return buf;
    }

    virtual uint16_t *writeRegister( uint32_t Register, uint64_t Data, enDataSz Size = sizeDword )
    {
        buf[0] = TAP_DO_WRITEREGISTER;
        buf[1] = 4 + ((Size + 1) / 2);
        buf[2] = (uint16_t)Register;
        buf[3] = (uint16_t)Size;
        // Little endian so this works no matter the size (clean this in the future)
        *(uint64_t *)&buf[4] = Data;
        return buf;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Read / Write - Small access

    virtual uint16_t *readMemory( uint32_t Address, uint32_t Length = sizeDword )
    {
        TAP_ReadCMD_t *CMD = (TAP_ReadCMD_t *)&buf[2];
        buf[0] = TAP_DO_READMEMORY;
        buf[1] = TAP_ReadCMD_sz;
        CMD->Address = Address;
        CMD->Length  = Length;
        return buf;
    }

    virtual uint16_t *writeMemory( uint32_t Address, uint64_t Data, uint32_t Length = sizeDword )
    {
        buf[0] = TAP_DO_WRITEMEMORY;
        buf[1] = TAP_ReadCMD_sz + ((Length + 1) / 2);
        *(uint32_t *)&buf[2] = Address;
        *(uint32_t *)&buf[4] = Length;
        // Little endian so this works no matter the size (clean this in the future)
        *(uint64_t *)&buf[6] = Data;
        return buf;
    }

    virtual uint16_t *writeArrayMemory( uint32_t Address, uint16_t *Data, uint32_t Length = sizeDword )
    {
        buf[0] = TAP_DO_WRITEMEMORY;
        buf[1] = TAP_ReadCMD_sz + ((Length + 1) / 2);
        *(uint32_t *)&buf[2] = Address;
        *(uint32_t *)&buf[4] = Length;
        memcpy( &buf[6], Data, (size_t)Length );
        return buf;
    }

    /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    // Memory; Write requests

/*
    // [no. cmd][tot len]
    // [[cmd], [cmd + data len, words]], [addr][addr],[len][len], [data]++
    uint32_t TAP_FillDataBE2(uint32_t Addr, uint32_t Len, const uint16_t *dataptr)
    {
        uint32_t lenPad = (Len & 1);
        uint8_t *dataIn = (uint8_t *)dataptr;
        uint8_t *dataOut = malloc(ADAPTER_BUFzIN);
        uint32_t retval = RET_OK;
        uint32_t i, actToSend;
        uint8_t *cpPtr;

        if (!dataOut)
            return wrk_faultShortcut(RET_MALLOC);

        *(uint16_t *)&dataOut[0] = TAP_DO_FILLMEM;

        while (Len && retval == RET_OK)
        {
            cpPtr = (uint8_t *)&dataOut[12];
            actToSend = Len + lenPad;

            // Sorry about this voodoo.. We have to take two headers into account
            if (actToSend > (ADAPTER_BUFzIN - 16))
                actToSend = (ADAPTER_BUFzIN - 16) - ((ADAPTER_BUFzIN - 16) % 2);

            if (actToSend <= Len)
            {
                for (i = 0; i < actToSend; i++)
                    cpPtr[(1 - (i & 1)) + (i & 0xfffffffe)] = *dataIn++;

                cpPtr += Len;
                Len -= actToSend;
            }
            else
            {
                for (i = 0; i < Len; i++)
                {
                    if (i < Len)
                        cpPtr[(1 - (i & 1)) + (i & 0xfffffffe)] = *dataIn++;
                    else
                        cpPtr[(1 - (i & 1)) + (i & 0xfffffffe)] = 0;
                }
                Len = 0;
            }

            // Send package..
            *(uint16_t *)&dataOut[2] = TAP_ReadCMD_sz + (actToSend / 2);
            *(uint32_t *)&dataOut[4] = Addr;
            *(uint32_t *)&dataOut[8] = actToSend;
            Addr += actToSend;

            retval = wrk_sendOneshot(dataOut);
        }

        free(dataOut);

        return retval;
    }
*/

    // This mess needs a clean!
    bool fillDataBE4( uint32_t Addr, const uint8_t *dataptr, size_t Len )
    {
        uint32_t lenPad = (Len & 3) ? (4 - (Len % 4)) : 0;
        uint8_t *dataIn = (uint8_t *)dataptr;
        uint8_t *dataOut = (uint8_t*)malloc( ADAPTER_BUFzIN );
        bool retval = true;
        uint32_t i, actToSend;
        uint8_t *cpPtr;

        if ( dataOut == nullptr ) {
            core.castMessage("Error: fillDataBE4 - Could not malloc buffer");
            return core.flagStatus(RET_MALLOC);
        }

        *(uint16_t *)&dataOut[0] = TAP_DO_FILLMEM;

        while ( Len > 0 && retval == true )
        {
            cpPtr = (uint8_t *)&dataOut[12];
            actToSend = Len + lenPad;

            // Sorry about this voodoo.. We have to take two headers into account
            if (actToSend > (ADAPTER_BUFzIN - 16))
                actToSend = (ADAPTER_BUFzIN - 16) - ((ADAPTER_BUFzIN - 16) % 4);

            if (actToSend <= Len)
            {
                for (i = 0; i < actToSend; i++)
                    cpPtr[(3 - (i & 3)) + (i & 0xfffffffc)] = *dataIn++;

                cpPtr += Len;
                Len -= actToSend;
            }
            else
            {
                for (i = 0; i < Len; i++)
                {
                    if (i < Len)
                        cpPtr[(3 - (i & 3)) + (i & 0xfffffffc)] = *dataIn++;
                    else
                        cpPtr[(3 - (i & 3)) + (i & 0xfffffffc)] = 0;
                }
                Len = 0;
            }

            // Send package..
            *(uint16_t *)&dataOut[2] = TAP_ReadCMD_sz + (actToSend / 2);
            *(uint32_t *)&dataOut[4] = Addr;
            *(uint32_t *)&dataOut[8] = actToSend;
            Addr += actToSend;

            retval = core.queue.send( (uint16_t*)dataOut );
        }

        free( dataOut );

        return retval;
    }

    uint16_t *assistFlash(uint32_t Addr, uint32_t Len,
                          uint32_t DriverStart,
                          uint32_t BufferStart, uint32_t BufferLen)
    {
        buf[0] = TAP_DO_ASSISTFLASH;
        buf[1] = TAP_AssistCMD_sz;

        *(uint32_t *)&buf[2]  = Addr;
        *(uint32_t *)&buf[4]  = Len;
        *(uint32_t *)&buf[6]  = DriverStart;
        *(uint32_t *)&buf[8]  = BufferStart;
        *(uint32_t *)&buf[10] = BufferLen;

        // wrk_ResetflashDone();

        return buf;
    }

    /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    // Memory; Read requests

    uint16_t *assistDump( uint32_t Address, uint32_t Length )
    {
        TAP_ReadCMD_t *CMD = (TAP_ReadCMD_t *)&buf[2];
        buf[0] = TAP_DO_DUMPMEM;
        buf[1] = TAP_ReadCMD_sz;
        CMD->Address = Address;
        CMD->Length = Length;
        return buf;
    }


    // 2+:
    // [ 0 ][sizeB][instruction]             : Just execute this instruction, no returned data.
    // [ 1 ][sizeB][instruction][sizeB][data]: Execute instruction and send data to target.
    // [ 2 ][sizeB][instruction][sizeB]      : Execute instruction and read back data.
    // [ 3 ][sizeB][instruction][sizeB][data]: Execute instruction with sent data, return received data.
    /*
    uint16_t *TAP_Execute(uint64_t Ins, uint32_t iSz)
    {
        static uint16_t data[8];

        if (iSz > 8 || !iSz)
        {
            *(uint32_t *)&data[0] = 0;
            core_castText("TAP_Execute(): Out of bounds");
            return &data[0];
        }

        data[0] = TAP_DO_ExecuteIns;
        data[1] = 4 + ((iSz + (iSz & 1)) / 2);
        data[2] = 0;

        data[3] = iSz;
        *(uint64_t *)&data[4] = Ins;

        return buf;
    }*/
/*
    uint16_t *TAP_Execute_wSentData(uint64_t Ins, uint32_t iSz, uint64_t Dat, uint32_t dSz)
    {
        static uint16_t data[13];

        if (iSz > 8 || dSz > 8 || !iSz || !dSz)
        {
            *(uint32_t *)&data[0] = 0;
            core_castText("TAP_Execute_wSentData(): Out of bounds");
            return &data[0];
        }

        data[0] = TAP_DO_ExecuteIns;
        data[1] = 4 + (((iSz + (iSz & 1)) + (dSz + (dSz & 1))) / 2);
        data[2] = 1;

        data[3] = iSz;
        *(uint64_t *)&data[4] = Ins;

        data[4 + ((iSz + (iSz & 1)) / 2)] = dSz;
        *(uint64_t *)&data[5 + ((iSz + (iSz & 1)) / 2)] = Dat;

        return buf;
    }*/

    // [ 0 ] [[sizeB][instruction]] [[sizeB][PC]]                   : Just execute this instruction, no returned data.
    // [ 2 ] [[sizeB][instruction]] [[sizeB retdata]] [[sizeB][PC]] : Execute instruction and read back data.
    /*
    uint16_t *TAP_ExecutePC(uint64_t Ins, uint32_t iSz, uint64_t PC, uint32_t pSz)
    {
        static uint16_t data[13];

        if (iSz > 8 || pSz > 8 || !iSz || !pSz)
        {
            *(uint32_t *)&data[0] = 0;
            core_castText("TAP_ExecutePC(): Out of bounds");
            return &data[0];
        }

        data[0] = TAP_DO_ExecuteIns;
        data[1] = 5 + (((iSz + (iSz & 1)) + (pSz + (pSz & 1))) / 2);
        data[2] = 0;

        data[3] = iSz;
        *(uint64_t *)&data[4] = Ins;

        data[4 + ((iSz + (iSz & 1)) / 2)] = pSz;
        *(uint64_t *)&data[5 + ((iSz + (iSz & 1)) / 2)] = PC;

        return &data[0];
    }*/

    // [ 0 ] [[sizeB][instruction]..] [[sizeB][PC]..]                   : Just execute this instruction, no returned data.
    // [ 2 ] [[sizeB][instruction]..] [[sizeB retdata]] [[sizeB][PC]..] : Execute instruction and read back data.
    /*
    uint16_t *TAP_ExecutePC_wRecData(uint64_t Ins, uint32_t iSz, uint16_t dSz, uint64_t PC, uint32_t pSz)
    {
        static uint16_t data[14];

        if (iSz > 8 || pSz > 8 || dSz > 8 || !iSz || !pSz || !dSz)
        {
            *(uint32_t *)&data[0] = 0;
            core_castText("TAP_ExecutePC_wRecData(): Out of bounds");
            return &data[0];
        }

        data[0] = TAP_DO_ExecuteIns;
        data[1] = 6 + (((iSz + (iSz & 1)) + (pSz + (pSz & 1))) / 2);
        data[2] = 2;

        data[3] = iSz;
        *(uint64_t *)&data[4] = Ins;

        data[4 + ((iSz + (iSz & 1)) / 2)] = dSz;

        data[5 + ((iSz + (iSz & 1)) / 2)] = pSz;
        *(uint64_t *)&data[6 + ((iSz + (iSz & 1)) / 2)] = PC;

        return &data[0];
    }*/
};

#endif
