#ifndef RTSPTHREAD_H
#define RTSPTHREAD_H

#include <QThread>
#include "qffmpeg.h"
#include <QDebug>

class RtspThread : public QThread
{
    Q_OBJECT
public:
    explicit RtspThread(QObject *parent = 0);

    void run();
    void stop();
    void setffmpeg(QFFmpeg *f){ffmpeg=f;}

private:    
    QFFmpeg * ffmpeg;
    bool stopFlag;

signals:

public slots:

};

#endif // RTSPTHREAD_H
