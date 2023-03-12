#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtCppBasic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtCppBasicClass; };
QT_END_NAMESPACE

class QtCppBasic : public QWidget
{
    Q_OBJECT

public:
    QtCppBasic(QWidget *parent = nullptr);
    ~QtCppBasic();

private:
    Ui::QtCppBasicClass *ui;
};
