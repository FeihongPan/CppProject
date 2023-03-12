#include "QtCppBasic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QtCppBasic w;
  w.show();
  return a.exec();
}
