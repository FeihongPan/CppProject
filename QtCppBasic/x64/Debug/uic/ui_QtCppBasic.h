/********************************************************************************
** Form generated from reading UI file 'QtCppBasic.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCPPBASIC_H
#define UI_QTCPPBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCppBasicClass
{
public:

    void setupUi(QWidget *QtCppBasicClass)
    {
        if (QtCppBasicClass->objectName().isEmpty())
            QtCppBasicClass->setObjectName(QString::fromUtf8("QtCppBasicClass"));
        QtCppBasicClass->resize(600, 400);

        retranslateUi(QtCppBasicClass);

        QMetaObject::connectSlotsByName(QtCppBasicClass);
    } // setupUi

    void retranslateUi(QWidget *QtCppBasicClass)
    {
        QtCppBasicClass->setWindowTitle(QCoreApplication::translate("QtCppBasicClass", "QtCppBasic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtCppBasicClass: public Ui_QtCppBasicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCPPBASIC_H
