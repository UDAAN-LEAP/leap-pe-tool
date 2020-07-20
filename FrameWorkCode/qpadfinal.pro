#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T18:03:39
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qpadfinal
TEMPLATE = app

#LIBS += -L"/home/rohit/ExpFinal/2OCRCorrect"
LIBS += -L"/usr/include/tesseract"
LIBS += -L"/usr/include/leptonica"
#LIBS += -L"/usr/lib" -llept\
#        -ltesseract
LIBS += -ltesseract -llept
#LIBS += -L"/home/nilesh/OCRCorrection/boost_1_61_0/stage/lib" -lboost_serialization

SOURCES +=\
    DiffView.cpp \
    averageaccuracies.cpp \
    commentsview.cpp \
    diff_match_patch.cpp \
        mainwindow.cpp \
    main.cpp \
    zoom.cpp \
    qcustomplot.cpp \
	interndiffview.cpp

HEADERS  += mainwindow.h \
    DiffView.h \
    averageaccuracies.h \
    commentsview.h \
    diff_match_patch.h \
    eddis.h \
    slpNPatternDict.h \
    tesseract/apitypes.h \
    tesseract/apitypes.h \
    tesseract/baseapi.h \
    tesseract/baseapi.h \
    tesseract/capi.h \
    tesseract/capi.h \
    tesseract/genericvector.h \
    tesseract/genericvector.h \
    tesseract/helpers.h \
    tesseract/helpers.h \
    tesseract/ltrresultiterator.h \
    tesseract/ltrresultiterator.h \
    tesseract/ocrclass.h \
    tesseract/ocrclass.h \
    tesseract/osdetect.h \
    tesseract/osdetect.h \
    tesseract/pageiterator.h \
    tesseract/pageiterator.h \
    tesseract/platform.h \
    tesseract/platform.h \
    tesseract/publictypes.h \
    tesseract/publictypes.h \
    tesseract/renderer.h \
    tesseract/renderer.h \
    tesseract/resultiterator.h \
    tesseract/resultiterator.h \
    tesseract/serialis.h \
    tesseract/serialis.h \
    tesseract/strngs.h \
    tesseract/strngs.h \
    tesseract/thresholder.h \
    tesseract/thresholder.h \
    tesseract/unichar.h \
    tesseract/unichar.h \
    tesseract/version.h \
    tesseract/version.h \
    trieEditdis.h \
    zoom.h \
    qcustomplot.h \
    meanStdPage.h \
	interndiffview.h

FORMS    += mainwindow.ui \
    DiffView.ui \
    averageaccuracies.ui \
    commentsview.ui \
	interndiffview.ui

RESOURCES += \
    AppResources.qrc

CONFIG += c++11
