/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[94];
    char stringdata0[2342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(4, 59, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(5, 86, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(6, 117, 15), // "mousePressEvent"
QT_MOC_LITERAL(7, 133, 12), // "QMouseEvent*"
QT_MOC_LITERAL(8, 146, 2), // "ev"
QT_MOC_LITERAL(9, 149, 13), // "menuSelection"
QT_MOC_LITERAL(10, 163, 8), // "QAction*"
QT_MOC_LITERAL(11, 172, 6), // "action"
QT_MOC_LITERAL(12, 179, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(13, 213, 33), // "on_actionLoad_Prev_Page_trigg..."
QT_MOC_LITERAL(14, 247, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(15, 279, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(16, 311, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(17, 339, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(18, 367, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(19, 399, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(20, 429, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(21, 458, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(22, 492, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(23, 516, 33), // "on_actionCreateBest2OCR_trigg..."
QT_MOC_LITERAL(24, 550, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(25, 576, 38), // "on_actionCreateSuggestionLog_..."
QT_MOC_LITERAL(26, 615, 53), // "on_actionCreateSuggestionLogN..."
QT_MOC_LITERAL(27, 669, 36), // "on_actionErrorDetectionRep_tr..."
QT_MOC_LITERAL(28, 706, 47), // "on_actionErrorDetectWithoutAd..."
QT_MOC_LITERAL(29, 754, 24), // "on_actionCPair_triggered"
QT_MOC_LITERAL(30, 779, 27), // "on_actionToSlp1_2_triggered"
QT_MOC_LITERAL(31, 807, 24), // "on_actionToDev_triggered"
QT_MOC_LITERAL(32, 832, 29), // "on_actionExtractDev_triggered"
QT_MOC_LITERAL(33, 862, 36), // "on_actionPrimarySecOCRPair_tr..."
QT_MOC_LITERAL(34, 899, 39), // "on_actionCPairIEROcrVsCorrect..."
QT_MOC_LITERAL(35, 939, 30), // "on_actionEditDistRep_triggered"
QT_MOC_LITERAL(36, 970, 36), // "on_actionConfusionFreqHist_tr..."
QT_MOC_LITERAL(37, 1007, 39), // "on_actionCPairGEROcrVsCorrect..."
QT_MOC_LITERAL(38, 1047, 44), // "on_actionFilterOutGT50EditDis..."
QT_MOC_LITERAL(39, 1092, 34), // "on_actionPrepareFeatures_trig..."
QT_MOC_LITERAL(40, 1127, 40), // "on_actionErrorDetectionRepUni..."
QT_MOC_LITERAL(41, 1168, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(42, 1196, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(43, 1221, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(44, 1248, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(45, 1272, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(46, 1301, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(47, 1331, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(48, 1362, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(49, 1399, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(50, 1425, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(51, 1459, 35), // "on_actionAverage_Accuracy_tri..."
QT_MOC_LITERAL(52, 1495, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(53, 1524, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(54, 1553, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(55, 1577, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(56, 1618, 13), // "LogHighlights"
QT_MOC_LITERAL(57, 1632, 4), // "word"
QT_MOC_LITERAL(58, 1637, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(59, 1669, 10), // "file_click"
QT_MOC_LITERAL(60, 1680, 11), // "QModelIndex"
QT_MOC_LITERAL(61, 1692, 4), // "indx"
QT_MOC_LITERAL(62, 1697, 12), // "LoadDocument"
QT_MOC_LITERAL(63, 1710, 6), // "QFile*"
QT_MOC_LITERAL(64, 1717, 4), // "file"
QT_MOC_LITERAL(65, 1722, 3), // "ext"
QT_MOC_LITERAL(66, 1726, 4), // "name"
QT_MOC_LITERAL(67, 1731, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(68, 1749, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(69, 1776, 1), // "p"
QT_MOC_LITERAL(70, 1778, 10), // "AddNewFile"
QT_MOC_LITERAL(71, 1789, 13), // "OpenDirectory"
QT_MOC_LITERAL(72, 1803, 10), // "RemoveFile"
QT_MOC_LITERAL(73, 1814, 8), // "closetab"
QT_MOC_LITERAL(74, 1823, 5), // "index"
QT_MOC_LITERAL(75, 1829, 10), // "tabchanged"
QT_MOC_LITERAL(76, 1840, 25), // "on_actionCommit_triggered"
QT_MOC_LITERAL(77, 1866, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(78, 1893, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(79, 1917, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(80, 1944, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(81, 1980, 16), // "directoryChanged"
QT_MOC_LITERAL(82, 1997, 4), // "path"
QT_MOC_LITERAL(83, 2002, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(84, 2033, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(85, 2067, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(86, 2091, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(87, 2118, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(88, 2146, 29), // "on_actionDiacritics_triggered"
QT_MOC_LITERAL(89, 2176, 34), // "on_actionInset_Tab_Space_trig..."
QT_MOC_LITERAL(90, 2211, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(91, 2240, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(92, 2282, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(93, 2311, 30) // "on_actionSuperscript_triggered"

    },
    "MainWindow\0on_actionNew_triggered\0\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionSpell_Check_triggered\0"
    "mousePressEvent\0QMouseEvent*\0ev\0"
    "menuSelection\0QAction*\0action\0"
    "on_actionLoad_Next_Page_triggered\0"
    "on_actionLoad_Prev_Page_triggered\0"
    "on_actionLoadGDocPage_triggered\0"
    "on_actionToDevanagari_triggered\0"
    "on_actionLoadData_triggered\0"
    "on_actionLoadDict_triggered\0"
    "on_actionLoadOCRWords_triggered\0"
    "on_actionLoadDomain_triggered\0"
    "on_actionLoadSubPS_triggered\0"
    "on_actionLoadConfusions_triggered\0"
    "on_actionSugg_triggered\0"
    "on_actionCreateBest2OCR_triggered\0"
    "on_actionToSlp1_triggered\0"
    "on_actionCreateSuggestionLog_triggered\0"
    "on_actionCreateSuggestionLogNearestPriority_triggered\0"
    "on_actionErrorDetectionRep_triggered\0"
    "on_actionErrorDetectWithoutAdaptation_triggered\0"
    "on_actionCPair_triggered\0"
    "on_actionToSlp1_2_triggered\0"
    "on_actionToDev_triggered\0"
    "on_actionExtractDev_triggered\0"
    "on_actionPrimarySecOCRPair_triggered\0"
    "on_actionCPairIEROcrVsCorrect_triggered\0"
    "on_actionEditDistRep_triggered\0"
    "on_actionConfusionFreqHist_triggered\0"
    "on_actionCPairGEROcrVsCorrect_triggered\0"
    "on_actionFilterOutGT50EditDisPairs_triggered\0"
    "on_actionPrepareFeatures_triggered\0"
    "on_actionErrorDetectionRepUniq_triggered\0"
    "on_actionSanskrit_triggered\0"
    "on_actionHindi_triggered\0"
    "on_actionEnglish_triggered\0"
    "on_actionBold_triggered\0"
    "on_actionLeftAlign_triggered\0"
    "on_actionRightAlign_triggered\0"
    "on_actionCentreAlign_triggered\0"
    "on_actionAllFontProperties_triggered\0"
    "on_actionUnBold_triggered\0"
    "on_actionJusitfiedAlign_triggered\0"
    "on_actionAverage_Accuracy_triggered\0"
    "on_actionHighlight_triggered\0"
    "on_actionFontBlack_triggered\0"
    "updateAverageAccuracies\0"
    "on_actionViewAverageAccuracies_triggered\0"
    "LogHighlights\0word\0on_actionOpen_Project_triggered\0"
    "file_click\0QModelIndex\0indx\0LoadDocument\0"
    "QFile*\0file\0ext\0name\0LoadImageFromFile\0"
    "CustomContextMenuTriggered\0p\0AddNewFile\0"
    "OpenDirectory\0RemoveFile\0closetab\0"
    "index\0tabchanged\0on_actionCommit_triggered\0"
    "on_actionTurn_In_triggered\0"
    "on_actionPush_triggered\0"
    "on_actionFetch_2_triggered\0"
    "on_actionVerifier_Turn_In_triggered\0"
    "directoryChanged\0path\0"
    "on_actionAccuracyLog_triggered\0"
    "on_compareCorrectorOutput_clicked\0"
    "on_viewComments_clicked\0"
    "on_actionZoom_In_triggered\0"
    "on_actionZoom_Out_triggered\0"
    "on_actionDiacritics_triggered\0"
    "on_actionInset_Tab_Space_triggered\0"
    "on_actionLineSpace_triggered\0"
    "on_actionInsert_Horizontal_Line_triggered\0"
    "on_actionSubscript_triggered\0"
    "on_actionSuperscript_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  404,    2, 0x08 /* Private */,
       3,    0,  405,    2, 0x08 /* Private */,
       4,    0,  406,    2, 0x08 /* Private */,
       5,    0,  407,    2, 0x08 /* Private */,
       6,    1,  408,    2, 0x08 /* Private */,
       9,    1,  411,    2, 0x08 /* Private */,
      12,    0,  414,    2, 0x08 /* Private */,
      13,    0,  415,    2, 0x08 /* Private */,
      14,    0,  416,    2, 0x08 /* Private */,
      15,    0,  417,    2, 0x08 /* Private */,
      16,    0,  418,    2, 0x08 /* Private */,
      17,    0,  419,    2, 0x08 /* Private */,
      18,    0,  420,    2, 0x08 /* Private */,
      19,    0,  421,    2, 0x08 /* Private */,
      20,    0,  422,    2, 0x08 /* Private */,
      21,    0,  423,    2, 0x08 /* Private */,
      22,    0,  424,    2, 0x08 /* Private */,
      23,    0,  425,    2, 0x08 /* Private */,
      24,    0,  426,    2, 0x08 /* Private */,
      25,    0,  427,    2, 0x08 /* Private */,
      26,    0,  428,    2, 0x08 /* Private */,
      27,    0,  429,    2, 0x08 /* Private */,
      28,    0,  430,    2, 0x08 /* Private */,
      29,    0,  431,    2, 0x08 /* Private */,
      30,    0,  432,    2, 0x08 /* Private */,
      31,    0,  433,    2, 0x08 /* Private */,
      32,    0,  434,    2, 0x08 /* Private */,
      33,    0,  435,    2, 0x08 /* Private */,
      34,    0,  436,    2, 0x08 /* Private */,
      35,    0,  437,    2, 0x08 /* Private */,
      36,    0,  438,    2, 0x08 /* Private */,
      37,    0,  439,    2, 0x08 /* Private */,
      38,    0,  440,    2, 0x08 /* Private */,
      39,    0,  441,    2, 0x08 /* Private */,
      40,    0,  442,    2, 0x08 /* Private */,
      41,    0,  443,    2, 0x08 /* Private */,
      42,    0,  444,    2, 0x08 /* Private */,
      43,    0,  445,    2, 0x08 /* Private */,
      44,    0,  446,    2, 0x08 /* Private */,
      45,    0,  447,    2, 0x08 /* Private */,
      46,    0,  448,    2, 0x08 /* Private */,
      47,    0,  449,    2, 0x08 /* Private */,
      48,    0,  450,    2, 0x08 /* Private */,
      49,    0,  451,    2, 0x08 /* Private */,
      50,    0,  452,    2, 0x08 /* Private */,
      51,    0,  453,    2, 0x08 /* Private */,
      52,    0,  454,    2, 0x08 /* Private */,
      53,    0,  455,    2, 0x08 /* Private */,
      54,    0,  456,    2, 0x08 /* Private */,
      55,    0,  457,    2, 0x08 /* Private */,
      56,    1,  458,    2, 0x08 /* Private */,
      58,    0,  461,    2, 0x08 /* Private */,
      59,    1,  462,    2, 0x08 /* Private */,
      62,    3,  465,    2, 0x08 /* Private */,
      67,    1,  472,    2, 0x08 /* Private */,
      68,    1,  475,    2, 0x08 /* Private */,
      70,    0,  478,    2, 0x08 /* Private */,
      71,    0,  479,    2, 0x08 /* Private */,
      72,    0,  480,    2, 0x08 /* Private */,
      73,    1,  481,    2, 0x08 /* Private */,
      75,    1,  484,    2, 0x08 /* Private */,
      76,    0,  487,    2, 0x08 /* Private */,
      77,    0,  488,    2, 0x08 /* Private */,
      78,    0,  489,    2, 0x08 /* Private */,
      79,    0,  490,    2, 0x08 /* Private */,
      80,    0,  491,    2, 0x08 /* Private */,
      81,    1,  492,    2, 0x08 /* Private */,
      83,    0,  495,    2, 0x08 /* Private */,
      84,    0,  496,    2, 0x08 /* Private */,
      85,    0,  497,    2, 0x08 /* Private */,
      86,    0,  498,    2, 0x08 /* Private */,
      87,    0,  499,    2, 0x08 /* Private */,
      88,    0,  500,    2, 0x08 /* Private */,
      89,    0,  501,    2, 0x08 /* Private */,
      90,    0,  502,    2, 0x08 /* Private */,
      91,    0,  503,    2, 0x08 /* Private */,
      92,    0,  504,    2, 0x08 /* Private */,
      93,    0,  505,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void, 0x80000000 | 63, QMetaType::QString, QMetaType::QString,   64,   65,   66,
    QMetaType::Void, 0x80000000 | 63,   64,
    QMetaType::Void, QMetaType::QPoint,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   82,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNew_triggered(); break;
        case 1: _t->on_actionSave_triggered(); break;
        case 2: _t->on_actionSave_As_triggered(); break;
        case 3: _t->on_actionSpell_Check_triggered(); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->on_actionLoad_Next_Page_triggered(); break;
        case 7: _t->on_actionLoad_Prev_Page_triggered(); break;
        case 8: _t->on_actionLoadGDocPage_triggered(); break;
        case 9: _t->on_actionToDevanagari_triggered(); break;
        case 10: _t->on_actionLoadData_triggered(); break;
        case 11: _t->on_actionLoadDict_triggered(); break;
        case 12: _t->on_actionLoadOCRWords_triggered(); break;
        case 13: _t->on_actionLoadDomain_triggered(); break;
        case 14: _t->on_actionLoadSubPS_triggered(); break;
        case 15: _t->on_actionLoadConfusions_triggered(); break;
        case 16: _t->on_actionSugg_triggered(); break;
        case 17: _t->on_actionCreateBest2OCR_triggered(); break;
        case 18: _t->on_actionToSlp1_triggered(); break;
        case 19: _t->on_actionCreateSuggestionLog_triggered(); break;
        case 20: _t->on_actionCreateSuggestionLogNearestPriority_triggered(); break;
        case 21: _t->on_actionErrorDetectionRep_triggered(); break;
        case 22: _t->on_actionErrorDetectWithoutAdaptation_triggered(); break;
        case 23: _t->on_actionCPair_triggered(); break;
        case 24: _t->on_actionToSlp1_2_triggered(); break;
        case 25: _t->on_actionToDev_triggered(); break;
        case 26: _t->on_actionExtractDev_triggered(); break;
        case 27: _t->on_actionPrimarySecOCRPair_triggered(); break;
        case 28: _t->on_actionCPairIEROcrVsCorrect_triggered(); break;
        case 29: _t->on_actionEditDistRep_triggered(); break;
        case 30: _t->on_actionConfusionFreqHist_triggered(); break;
        case 31: _t->on_actionCPairGEROcrVsCorrect_triggered(); break;
        case 32: _t->on_actionFilterOutGT50EditDisPairs_triggered(); break;
        case 33: _t->on_actionPrepareFeatures_triggered(); break;
        case 34: _t->on_actionErrorDetectionRepUniq_triggered(); break;
        case 35: _t->on_actionSanskrit_triggered(); break;
        case 36: _t->on_actionHindi_triggered(); break;
        case 37: _t->on_actionEnglish_triggered(); break;
        case 38: _t->on_actionBold_triggered(); break;
        case 39: _t->on_actionLeftAlign_triggered(); break;
        case 40: _t->on_actionRightAlign_triggered(); break;
        case 41: _t->on_actionCentreAlign_triggered(); break;
        case 42: _t->on_actionAllFontProperties_triggered(); break;
        case 43: _t->on_actionUnBold_triggered(); break;
        case 44: _t->on_actionJusitfiedAlign_triggered(); break;
        case 45: _t->on_actionAverage_Accuracy_triggered(); break;
        case 46: _t->on_actionHighlight_triggered(); break;
        case 47: _t->on_actionFontBlack_triggered(); break;
        case 48: _t->updateAverageAccuracies(); break;
        case 49: _t->on_actionViewAverageAccuracies_triggered(); break;
        case 50: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 51: _t->on_actionOpen_Project_triggered(); break;
        case 52: _t->file_click((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 53: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 54: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 55: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 56: _t->AddNewFile(); break;
        case 57: _t->OpenDirectory(); break;
        case 58: _t->RemoveFile(); break;
        case 59: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->on_actionCommit_triggered(); break;
        case 62: _t->on_actionTurn_In_triggered(); break;
        case 63: _t->on_actionPush_triggered(); break;
        case 64: _t->on_actionFetch_2_triggered(); break;
        case 65: _t->on_actionVerifier_Turn_In_triggered(); break;
        case 66: _t->directoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 67: _t->on_actionAccuracyLog_triggered(); break;
        case 68: _t->on_compareCorrectorOutput_clicked(); break;
        case 69: _t->on_viewComments_clicked(); break;
        case 70: _t->on_actionZoom_In_triggered(); break;
        case 71: _t->on_actionZoom_Out_triggered(); break;
        case 72: _t->on_actionDiacritics_triggered(); break;
        case 73: _t->on_actionInset_Tab_Space_triggered(); break;
        case 74: _t->on_actionLineSpace_triggered(); break;
        case 75: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 76: _t->on_actionSubscript_triggered(); break;
        case 77: _t->on_actionSuperscript_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 53:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 54:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
