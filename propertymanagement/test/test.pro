QT += testlib
QT -= gui

QT += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_programtest.cpp \
    ../src/databaseconnection.cpp

INCLUDEPATH += ../src
