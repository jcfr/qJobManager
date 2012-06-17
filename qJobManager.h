
#ifndef __qJobManager_h
#define __qJobManager_h

// Qt includes
#include <QObject>
#include <QSharedPointer>

// qJob includes
#include "qJob.h"

//-----------------------------------------------------------------------------
class qJobManager : public QObject
{
  Q_OBJECT
public:
  typedef QObject Superclass;
  qJobManager();
  virtual ~qJobManager();

  void setJobPath(const QString& jobPath);

public slots:
  void startJobs();

private:
  QString                       JobPath;
  QList< QSharedPointer<qJob> > Jobs;
};

#endif
