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
    stoped();
    qDebug()<<"thread has stoped";
}

void RtspThread::stop()
{
    stopFlag=true;
    qDebug()<<"thread start stop...";
}
