#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T14:14:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RESTer
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
    gui/mainwindow.cpp \
    httpclient/httpheader.cpp \
    httpclient/httprequest.cpp \
    httpclient/httpresponse.cpp \
    httpclient/httpmethod.cpp \
    httpclient/httpget.cpp \
    httpclient/httpmessage.cpp \
    httpclient/restexecutor.cpp

HEADERS  += gui/mainwindow.h \
    httpclient/httpheader.h \
    httpclient/httprequest.h \
    httpclient/httpresponse.h \
    httpclient/httpmethod.h \
    httpclient/httpget.h \
    httpclient/httpmessage.h \
    httpclient/restexecutor.h

FORMS    += gui/mainwindow.ui

RESOURCES += \
    resources.qrc
