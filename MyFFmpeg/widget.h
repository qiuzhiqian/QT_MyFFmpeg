#ifndef WIDGET_H
#define WIDGET_H

#include "qffmpeg.h"
#include "rtspthread.h"
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

//#ifndef INT64_C
//#define INT64_C
//#define UINT64_C
//#endif

//引入ffmpeg头文件
//extern "C"
//{
//#include "ffmpeg/include/libavcodec/avcodec.h"
//#include "ffmpeg/include/libavdevice/avdevice.h"
//#include "ffmpeg/include/libavfilter/avfilter.h"
//#include "ffmpeg/include/libavformat/avformat.h"
//#include "ffmpeg/include/libavutil/frame.h"
//#include "ffmpeg/include/libavutil/avutil.h"
//#include "ffmpeg/include/libpostproc/postprocess.h"
//#include "ffmpeg/include/libswresample/swresample.h"
//#include "ffmpeg/include/libswscale/swscale.h"
//}



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QFFmpeg *ffmpeg;
    RtspThread *rtsp;

signals:
    void closeVideo();

private slots:
    void showVideo();

    void SetImage(const QImage &image);
};

#endif // WIDGET_H
