/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugwindow
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QVBoxLayout *regLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReadReg;
    QPushButton *btnWriteReg;
    QLineEdit *dataEdit;

    void setupUi(QDialog *debugwindow)
    {
        if (debugwindow->objectName().isEmpty())
            debugwindow->setObjectName("debugwindow");
        debugwindow->resize(342, 300);
        widget = new QWidget(debugwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 564, 46));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 0, 0, 0);
        regLayout = new QVBoxLayout();
        regLayout->setSpacing(8);
        regLayout->setObjectName("regLayout");
        regLayout->setSizeConstraint(QLayout::SetNoConstraint);

        formLayout->setLayout(0, QFormLayout::ItemRole::LabelRole, regLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        btnReadReg = new QPushButton(widget);
        btnReadReg->setObjectName("btnReadReg");

        horizontalLayout->addWidget(btnReadReg);

        btnWriteReg = new QPushButton(widget);
        btnWriteReg->setObjectName("btnWriteReg");

        horizontalLayout->addWidget(btnWriteReg);

        dataEdit = new QLineEdit(widget);
        dataEdit->setObjectName("dataEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataEdit->sizePolicy().hasHeightForWidth());
        dataEdit->setSizePolicy(sizePolicy);
        dataEdit->setMinimumSize(QSize(160, 20));

        horizontalLayout->addWidget(dataEdit);


        formLayout->setLayout(1, QFormLayout::ItemRole::LabelRole, horizontalLayout);


        retranslateUi(debugwindow);

        QMetaObject::connectSlotsByName(debugwindow);
    } // setupUi

    void retranslateUi(QDialog *debugwindow)
    {
        debugwindow->setWindowTitle(QCoreApplication::translate("debugwindow", "Dialog", nullptr));
        btnReadReg->setText(QCoreApplication::translate("debugwindow", "Read", nullptr));
        btnWriteReg->setText(QCoreApplication::translate("debugwindow", "Write", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debugwindow: public Ui_debugwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
