#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T08:09:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFFmpeg
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qffmpeg.cpp \
    rtspthread.cpp

LIBS +=-L$$PWD/ffmpeg -lavcodec
LIBS +=-L./ffmpeg -lavdevice
LIBS +=-L./ffmpeg -lavfilter
LIBS +=-L./ffmpeg -lavformat
LIBS +=-L./ffmpeg -lavutil
LIBS +=-L./ffmpeg -lpostproc
LIBS +=-L./ffmpeg -lswresample
LIBS +=-L./ffmpeg -lswscale

INCLUDEPATH +=ffmpeg/include/

#message($$(INCLUDEPATH))

HEADERS  += widget.h \
    qffmpeg.h \
    rtspthread.h

FORMS    += widget.ui

