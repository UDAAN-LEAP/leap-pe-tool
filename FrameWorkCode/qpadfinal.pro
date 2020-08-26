#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T18:03:39
#
#-------------------------------------------------

QT += core gui
QT += printsupport
QT +=xml
QT +=network

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


RESOURCES += \
    AppResources.qrc

CONFIG += c++11
