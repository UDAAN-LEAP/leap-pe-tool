#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T18:03:39
#
#-------------------------------------------------

QT += core gui svg widgets
QT += printsupport
QT +=xml
QT +=network networkauth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qpadfinal
TEMPLATE = app

#LIBS += -L"/home/rohit/ExpFinal/2OCRCorrect"
LIBS += -L"/usr/include/tesseract"
LIBS += -L"/usr/include/leptonica"
LIBS += -L"/usr/include/pugixml"
#LIBS += -L"/usr/lib" -llept
#        -ltesseract
LIBS += -ltesseract -llept -lpugixml
#LIBS += -L"/home/nilesh/OCRCorrection/boost_1_61_0/stage/lib" -lboost_serialization
LIBS += -L"/usr/include/git2"

LIBS += -lgit2

include(qpadfinal.pri)

DEFINES += QT_MESSAGELOGCONTEXT

RESOURCES += \
    AppResources.qrc

CONFIG += c++11

FORMS +=

HEADERS +=

SOURCES +=

DISTFILES += \
    UserJson.json

QMAKE_CXXFLAGS += -w
#Windows icon
#win32:RC_FILE += qpadfinal.rc

CONFIG += c++11
INCLUDEPATH += ../include
INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/../lib/ -lYAWYSIWYGEE
    win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../lib/YAWYSIWYGEE.lib
    else:win32-g++: PRE_TARGETDEPS += $$PWD/../lib/libYAWYSIWYGEE.a
}else{
    LIBS += -L$$PWD/../lib/release/ -lYAWYSIWYGEE
    win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../lib/release/YAWYSIWYGEE.lib
    else:win32-g++: PRE_TARGETDEPS += $$PWD/../lib/release/libYAWYSIWYGEE.a
}
