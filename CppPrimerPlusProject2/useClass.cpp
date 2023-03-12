#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

#include "Worker.h"
int UseWorker()
{
  const int LIM = 4;

  Waiter* wa1 = new Waiter("wa1", 314L, 5);
  Singer* si1 = new Singer("si1", 522L, 3);
  Waiter w_temp;
  Singer s_temp;

  // Object Array
  Worker* pw1[LIM] = { wa1, si1, &w_temp, &s_temp }; // Pointer Array
  QVector<Worker*> pw2 = { wa1, si1, &w_temp, &s_temp }; // QVector 
  double pw3[] = { 1.,2.,3.,4. };
  double* pw4[] = { &pw3[0], &pw3[1], &pw3[2], &pw3[3]};

  for (int i = 2; i < LIM; i++)
    pw1[i]->set();
  for (int i = 0; i < LIM; i++)
    pw2[i]->Show();

  return 0;
}



