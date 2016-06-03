#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //rtsp://:8554/192.168.66.108
    //rtsp://video.fjtu.com.cn/vs01/flws/flws_01.rm
    //udp://:1234/192.168.16.228

    //http://:8080/192.168.16.228
    rtsp = new RtspThread(this);


    connect(ui->openBtn,SIGNAL(clicked(bool)),this,SLOT(showVideo()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::showVideo()
{
    if(ui->openBtn->text()=="Open")
    {
        ffmpeg=new QFFmpeg(this);
        connect(ffmpeg, SIGNAL(GetImage(QImage)), this, SLOT(SetImage(QImage)));
        ffmpeg->Start();
        ffmpeg->SetUrl(ui->urlLineEdit->text());

        if (ffmpeg->Init())
        {
            rtsp->setffmpeg(ffmpeg);
            rtsp->start();
        }

        ui->openBtn->setText("Close");
    }
    else if(ui->openBtn->text()=="Close")
    {

        rtsp->stop();
        //ffmpeg->Free_mem();
        //closeVideo();


        //disconnect(ffmpeg, SIGNAL(GetImage(QImage)), this, SLOT(SetImage(QImage)));
        ui->openBtn->setText("Open");
        //delete ffmpeg;
    }
}

int tempWidth = 480;
int tempHeight = 320;
void Widget::SetImage(const QImage &image)
{
    tempWidth = ui->labVideo->geometry().width();
    tempHeight = ui->labVideo->geometry().height();
    if (image.height() > 0) {
        QPixmap pix = QPixmap::fromImage(image.scaled(tempWidth, tempHeight));
        ui->labVideo->setPixmap(pix);
    }
}
