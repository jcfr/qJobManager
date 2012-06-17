
// Qt includes
#include <QCoreApplication>
#include <QTimer>

// qJob includes
#include "qJobManager.h"

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);

  qJobManager manager;
  manager.setJobPath("/usr/bin/xcalc");
  QTimer::singleShot(0, &manager, SLOT(startJobs()));

  return app.exec();
}
