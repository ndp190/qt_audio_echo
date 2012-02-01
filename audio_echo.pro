#-------------------------------------------------
#
# Project created by QtCreator 2012-01-28T18:50:35
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = audio_echo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    io/audioFormatBuilder.cpp \
    io/audioReader.cpp \
    io/audioWriter.cpp

HEADERS  += mainwindow.h \
    io/constants.h \
    io/audioFormatBuilder.h \
    io/audioReader.h \
    io/audioWriter.h

FORMS    += mainwindow.ui
