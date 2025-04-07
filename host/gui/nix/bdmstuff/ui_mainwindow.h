/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *textBrowser;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lblFlash;
    QPushButton *btnFlash;
    QPushButton *btnDump;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblEep;
    QPushButton *btnWriteEEP;
    QPushButton *btnReadEEP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblDebug;
    QPushButton *btnDebug;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1033, 440);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName("textBrowser");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(400, 20));
        textBrowser->setAcceptDrops(false);
        textBrowser->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(textBrowser);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMinimumSize(QSize(292, 30));
        comboBox->setMaximumSize(QSize(292, 30));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        lblFlash = new QLabel(layoutWidget);
        lblFlash->setObjectName("lblFlash");
        lblFlash->setMinimumSize(QSize(80, 0));
        lblFlash->setMaximumSize(QSize(80, 16777215));
        lblFlash->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(lblFlash);

        btnFlash = new QPushButton(layoutWidget);
        btnFlash->setObjectName("btnFlash");
        btnFlash->setMinimumSize(QSize(100, 40));
        btnFlash->setMaximumSize(QSize(100, 16777215));
        btnFlash->setFlat(false);

        horizontalLayout->addWidget(btnFlash);

        btnDump = new QPushButton(layoutWidget);
        btnDump->setObjectName("btnDump");
        btnDump->setMinimumSize(QSize(100, 40));
        btnDump->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(btnDump);


        formLayout->setLayout(1, QFormLayout::ItemRole::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblEep = new QLabel(layoutWidget);
        lblEep->setObjectName("lblEep");
        lblEep->setMinimumSize(QSize(80, 0));
        lblEep->setMaximumSize(QSize(80, 16777215));
        lblEep->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(lblEep);

        btnWriteEEP = new QPushButton(layoutWidget);
        btnWriteEEP->setObjectName("btnWriteEEP");
        btnWriteEEP->setMinimumSize(QSize(100, 40));
        btnWriteEEP->setMaximumSize(QSize(100, 16777215));
        btnWriteEEP->setFlat(false);

        horizontalLayout_2->addWidget(btnWriteEEP);

        btnReadEEP = new QPushButton(layoutWidget);
        btnReadEEP->setObjectName("btnReadEEP");
        btnReadEEP->setMinimumSize(QSize(100, 40));
        btnReadEEP->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(btnReadEEP);


        formLayout->setLayout(2, QFormLayout::ItemRole::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lblDebug = new QLabel(layoutWidget);
        lblDebug->setObjectName("lblDebug");
        lblDebug->setMinimumSize(QSize(80, 0));
        lblDebug->setMaximumSize(QSize(80, 16777215));
        lblDebug->setFrameShape(QFrame::NoFrame);

        horizontalLayout_3->addWidget(lblDebug);

        btnDebug = new QPushButton(layoutWidget);
        btnDebug->setObjectName("btnDebug");
        btnDebug->setMinimumSize(QSize(100, 40));
        btnDebug->setMaximumSize(QSize(100, 16777215));
        btnDebug->setFlat(false);

        horizontalLayout_3->addWidget(btnDebug);


        formLayout->setLayout(3, QFormLayout::ItemRole::LabelRole, horizontalLayout_3);

        splitter->addWidget(layoutWidget);
        progressBar = new QProgressBar(splitter);
        progressBar->setObjectName("progressBar");
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMinimumSize(QSize(292, 20));
        progressBar->setMaximumSize(QSize(292, 20));
        QPalette palette;
        QBrush brush(QColor(0, 149, 0, 170));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush);
        QBrush brush1(QColor(31, 117, 204, 170));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Highlight, brush1);
        progressBar->setPalette(palette);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        progressBar->setTextVisible(false);
        splitter->addWidget(progressBar);

        horizontalLayout_4->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "bdmstuff", nullptr));
        textBrowser->setPlaceholderText(QCoreApplication::translate("MainWindow", "Clear Me", nullptr));
        lblFlash->setText(QCoreApplication::translate("MainWindow", "FLASH", nullptr));
        btnFlash->setText(QCoreApplication::translate("MainWindow", "Flash", nullptr));
        btnDump->setText(QCoreApplication::translate("MainWindow", "Dump", nullptr));
        lblEep->setText(QCoreApplication::translate("MainWindow", "EEPROM", nullptr));
        btnWriteEEP->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        btnReadEEP->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        lblDebug->setText(QCoreApplication::translate("MainWindow", "FUN STUFF", nullptr));
        btnDebug->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
