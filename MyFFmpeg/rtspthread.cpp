#include "rtspthread.h"

RtspThread::RtspThread(QObject *parent) :
    QThread(parent)
{
    stopFlag=false;
    qDebug()<<"stopFlag="<<stopFlag;
}

void  RtspThread::run()
{
    while(stopFlag==false)
    {
        ffmpeg->Play();
    }
}

void RtspThread::stop()
{
    stopFlag=true;
    qDebug()<<"stop";
}
