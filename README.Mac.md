# Readme for Mac users with M chip

It seems I could get the repo built with Mac Arm/M chip, so I made a fork that include some
changes to make it work for me, also will check in the built files in the repo.

I had to change some code to make it compile for me, also needed to specify the libusb location
in some makefiles and the bdmstuff.pro file.

I have not tested yet whether this will eventually work on Mac, though.


Some info about build can be seen here:
https://github.com/ChristianIvarsson/bdmtoy/issues/1

## Preparation

```sh
# For getting arm-none-eabi-gcc target so to be able to compile firmware.bin/hex for STM32 chips
brew install --cask gcc-arm-embedded

# Getting libusb for compiling cli or GUI tool
brew install libusb

brew list libusb
# /opt/homebrew/Cellar/libusb/1.0.28/include/libusb-1.0/libusb.h
# /opt/homebrew/Cellar/libusb/1.0.28/lib/libusb-1.0.0.dylib

# Then use the version number above, such as 1.0.28 to clone libusb code in this location:
cd bdmtoy/host
git clone --recursive --single-branch -b "v1.0.28" https://github.com/libusb/libusb

# Get QT on Mac for building GUI tool
brew install qt
```

## To build Gui tool:

```sh
cd bdmtoy/host/gui/nix/bdmstuff
qmake
make

# Then executable file is here, run it to use the GUI tool "bdmstuff"
./bdmstuff.app/Contents/MacOS/bdmstuff

## To build cli tool:
cd bdmtoy/host/cli/both
make


## To build firmware:
cd bdmtoy/firmware
make
```

## References

* https://stackoverflow.com/questions/59861085/how-to-install-gcc-arm-none-eabi-on-mojave-macos
* https://superuser.com/questions/256232/how-can-i-get-qmake-on-mac-os-x