#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T18:03:39
#
#-------------------------------------------------

QT += core gui svg widgets
QT += printsupport
QT += xml
QT += network networkauth
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udaan_x86_64
TEMPLATE = app

LIBS+= -dead_strip
LIBS += -L$$PWD/../deps/macos/x86_64/lib
LIBS += -lpugixml
LIBS += -L$$PWD/../deps/macos/x86_64/include
LIBS += -lgit2

include(qpadfinal.pri)

DEFINES += QT_MESSAGELOGCONTEXT

RESOURCES += \
    AppResources.qrc

#CONFIG += c++11
CONFIG+=sdk_no_version_check

QMAKE_CXXFLAGS += -w
QMAKE_CXX = clang++

QMAKE_APPLE_DEVICE_ARCHS = arm64 x86_64
CMAKE_OSX_ARCHITECTURES = arm64 x86_64
QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0

#QMAKE_CXXFLAGS += -target x86_64h-apple-darwin20.3.0


INCLUDEPATH += ../include
INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
LIBS += -L$$PWD/../deps/macos/x86_64/opt/YAWYSIWYGEE/bin/ -lYAWYSIWYGEE

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include

INCLUDEPATH += $$PWD/../deps/macos/x86_64/include
DEPENDPATH += $$PWD/../deps/macos/x86_64/include

