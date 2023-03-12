#include "QtCppBasic.h"

QtCppBasic::QtCppBasic(QWidget* parent)
	: QWidget(parent), ui(new Ui::QtCppBasicClass())
{
	ui->setupUi(this);
}

QtCppBasic::~QtCppBasic()
{
	delete ui;
}
