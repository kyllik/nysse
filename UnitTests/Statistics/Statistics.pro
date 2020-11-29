QT += testlib
QT -= gui

TARGET = tst_statistics
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_statistics.cpp \
    ../../Game/statistics.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Game/statistics.hh\
    ../../Course/CourseLib/interfaces/istatistics.hh

INCLUDEPATH += \
            ../../Game/

DEPENDPATH += \
            ../../Game/
