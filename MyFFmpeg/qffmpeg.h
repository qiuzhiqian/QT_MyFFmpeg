#ifndef QFFMPEG_H
#define QFFMPEG_H

//必须加以下内容,否则编译不能通过,为了兼容C和C99标准
//#ifndef INT64_C
//#define INT64_C
//#define UINT64_C
//#endif

//引入ffmpeg头文件
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
}

#include <QObject>
#include <QMutex>
#include <QImage>

class QFFmpeg : public QObject
{
    Q_OBJECT
public:
    explicit QFFmpeg(QObject *parent = 0);
    ~QFFmpeg();

    bool Init();
    void Play();
    void Start();
    void Stop();
    void Free_mem();

    void SetUrl(QString url){v_url=url;}
    QString Url()const{return v_url;}
    int VideoWidth()const{return videoWidth;}
    int VideoHeight()const{return videoHeight;}

private:
    QMutex mutex;
    AVPicture  pAVPicture;
    AVFormatContext *pAVFormatContext;
    AVCodecContext *pAVCodecContext;
    AVFrame *pAVFrame;
    SwsContext * pSwsContext;
    AVPacket pAVPacket;

    QString v_url;
    int videoWidth;
    int videoHeight;
    int videoStreamIndex;       //视频流索引
    int audioStreamIndex;       //音频流索引

    bool playFlag;

signals:
    void GetImage(const QImage &image);

public slots:

};

#endif // QFFMPEG_H
