
// Qt includes
#include <QDebug>
#include <QFile>

// qJob includes
#include "qJob.h"

//-----------------------------------------------------------------------------
qJob::qJob(const QString& path, QObject *parent):Superclass(parent), Path(path)
{
  qRegisterMetaType<QProcess::ExitStatus>();
}

//-----------------------------------------------------------------------------
qJob::~qJob()
{

}

//-----------------------------------------------------------------------------
void qJob::applicationStarted()
{
  qDebug() << "Thread" << this->currentThreadId() << "process started";
}

//-----------------------------------------------------------------------------
void qJob::applicationFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
  Q_UNUSED(exitStatus);
  qDebug() << "Thread" << this->currentThreadId()
           << "process finished with exitCode" << exitCode;
}

//-----------------------------------------------------------------------------
void qJob::run()
{
  if (!QFile::exists(this->Path))
    {
    qCritical() << "Failed to start job" << this->currentThreadId()
                << " - JobPath set to a nonexistent file:" << this->Path;
    return;
    }
  this->Process = new QProcess();
  connect(this->Process, SIGNAL(finished(int, QProcess::ExitStatus)),
          this, SLOT(applicationFinished(int, QProcess::ExitStatus)));
  connect(this->Process, SIGNAL(started()), this, SLOT(applicationStarted()));

  this->Process->start(this->Path);
  qDebug() << "Starting thread" << this->currentThreadId();
  exec();
}
