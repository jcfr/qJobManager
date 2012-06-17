
#ifndef __qJob_h
#define __qJob_h

// Qt includes
#include <QObject>
#include <QMetaType>
#include <QProcess>
#include <QThread>

//-----------------------------------------------------------------------------
Q_DECLARE_METATYPE(QProcess::ExitStatus)

//-----------------------------------------------------------------------------
class qJob : public QThread
{
  Q_OBJECT
public:
  typedef QThread Superclass;
  qJob(const QString& path, QObject * parent = 0);
  virtual ~qJob();

protected slots:
  void applicationStarted();
  void applicationFinished(int exitCode, QProcess::ExitStatus exitStatus);

protected:
  virtual void run();

private:
  QString Path;
  QProcess * Process;
};

#endif
