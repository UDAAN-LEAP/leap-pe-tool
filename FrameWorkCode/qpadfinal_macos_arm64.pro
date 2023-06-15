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

TARGET = qpadfinal
TEMPLATE = app

LIBS+= -dead_strip
LIBS += -L"/usr/local/lib"
LIBS += -lpugixml
LIBS += -L"/usr/local/include/git2"
LIBS += -lgit2

include(qpadfinal.pri)

DEFINES += QT_MESSAGELOGCONTEXT

RESOURCES += \
    AppResources.qrc

#CONFIG += c++11
CONFIG+=sdk_no_version_check

QMAKE_CXXFLAGS += -w
QMAKE_CXX = clang++

QMAKE_APPLE_DEVICE_ARCHS = arm64
CMAKE_OSX_ARCHITECTURES = arm64

#QMAKE_CXXFLAGS += -target x86_64h-apple-darwin20.3.0

# Windows icon
#win32:RC_FILE += qpadfinal.rc

INCLUDEPATH += ../include
INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/../lib/ -lYAWYSIWYGEE
    win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../lib/YAWYSIWYGEE.lib
    else:win32-g++: PRE_TARGETDEPS += $$PWD/../lib/libYAWYSIWYGEE.a
}else{
    LIBS += -L$$PWD/../lib/ -lYAWYSIWYGEE
    win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../lib/YAWYSIWYGEE.lib
    else:win32-g++: PRE_TARGETDEPS += $$PWD/../lib/libYAWYSIWYGEE.a
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lYAWYSIWYGEE
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lYAWYSIWYGEE

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/libYAWYSIWYGEE.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/libYAWYSIWYGEE.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/YAWYSIWYGEE.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/YAWYSIWYGEE.lib


win32: LIBS += -L$$PWD/../lib/ -lquazip

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include
