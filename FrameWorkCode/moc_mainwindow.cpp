/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[128];
    char stringdata0[3069];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "DisplayJsonDict"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "eventFilter"
QT_MOC_LITERAL(4, 40, 7), // "QEvent*"
QT_MOC_LITERAL(5, 48, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(6, 71, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(7, 95, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(8, 122, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(9, 153, 15), // "mousePressEvent"
QT_MOC_LITERAL(10, 169, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 182, 2), // "ev"
QT_MOC_LITERAL(12, 185, 13), // "menuSelection"
QT_MOC_LITERAL(13, 199, 8), // "QAction*"
QT_MOC_LITERAL(14, 208, 6), // "action"
QT_MOC_LITERAL(15, 215, 17), // "translate_replace"
QT_MOC_LITERAL(16, 233, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(17, 267, 33), // "on_actionLoad_Prev_Page_trigg..."
QT_MOC_LITERAL(18, 301, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(19, 333, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(20, 365, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(21, 393, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(22, 421, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(23, 453, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(24, 483, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(25, 512, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(26, 546, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(27, 570, 33), // "on_actionCreateBest2OCR_trigg..."
QT_MOC_LITERAL(28, 604, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(29, 630, 38), // "on_actionCreateSuggestionLog_..."
QT_MOC_LITERAL(30, 669, 53), // "on_actionCreateSuggestionLogN..."
QT_MOC_LITERAL(31, 723, 36), // "on_actionErrorDetectionRep_tr..."
QT_MOC_LITERAL(32, 760, 47), // "on_actionErrorDetectWithoutAd..."
QT_MOC_LITERAL(33, 808, 24), // "on_actionCPair_triggered"
QT_MOC_LITERAL(34, 833, 27), // "on_actionToSlp1_2_triggered"
QT_MOC_LITERAL(35, 861, 24), // "on_actionToDev_triggered"
QT_MOC_LITERAL(36, 886, 29), // "on_actionExtractDev_triggered"
QT_MOC_LITERAL(37, 916, 36), // "on_actionPrimarySecOCRPair_tr..."
QT_MOC_LITERAL(38, 953, 39), // "on_actionCPairIEROcrVsCorrect..."
QT_MOC_LITERAL(39, 993, 30), // "on_actionEditDistRep_triggered"
QT_MOC_LITERAL(40, 1024, 36), // "on_actionConfusionFreqHist_tr..."
QT_MOC_LITERAL(41, 1061, 39), // "on_actionCPairGEROcrVsCorrect..."
QT_MOC_LITERAL(42, 1101, 44), // "on_actionFilterOutGT50EditDis..."
QT_MOC_LITERAL(43, 1146, 34), // "on_actionPrepareFeatures_trig..."
QT_MOC_LITERAL(44, 1181, 40), // "on_actionErrorDetectionRepUni..."
QT_MOC_LITERAL(45, 1222, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(46, 1250, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(47, 1275, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(48, 1302, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(49, 1326, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(50, 1355, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(51, 1385, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(52, 1416, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(53, 1453, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(54, 1479, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(55, 1513, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(56, 1542, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(57, 1571, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(58, 1595, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(59, 1636, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(60, 1668, 10), // "file_click"
QT_MOC_LITERAL(61, 1679, 11), // "QModelIndex"
QT_MOC_LITERAL(62, 1691, 4), // "indx"
QT_MOC_LITERAL(63, 1696, 12), // "LoadDocument"
QT_MOC_LITERAL(64, 1709, 6), // "QFile*"
QT_MOC_LITERAL(65, 1716, 4), // "file"
QT_MOC_LITERAL(66, 1721, 3), // "ext"
QT_MOC_LITERAL(67, 1725, 4), // "name"
QT_MOC_LITERAL(68, 1730, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(69, 1748, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(70, 1775, 1), // "p"
QT_MOC_LITERAL(71, 1777, 10), // "AddNewFile"
QT_MOC_LITERAL(72, 1788, 13), // "OpenDirectory"
QT_MOC_LITERAL(73, 1802, 10), // "RemoveFile"
QT_MOC_LITERAL(74, 1813, 8), // "closetab"
QT_MOC_LITERAL(75, 1822, 5), // "index"
QT_MOC_LITERAL(76, 1828, 10), // "tabchanged"
QT_MOC_LITERAL(77, 1839, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(78, 1866, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(79, 1890, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(80, 1917, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(81, 1953, 16), // "directoryChanged"
QT_MOC_LITERAL(82, 1970, 4), // "path"
QT_MOC_LITERAL(83, 1975, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(84, 2006, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(85, 2040, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(86, 2064, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(87, 2091, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(88, 2119, 26), // "on_actionSymbols_triggered"
QT_MOC_LITERAL(89, 2146, 35), // "on_actionInsert_Tab_Space_tri..."
QT_MOC_LITERAL(90, 2182, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(91, 2224, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(92, 2253, 30), // "on_actionSuperscript_triggered"
QT_MOC_LITERAL(93, 2284, 19), // "UpdateFileBrekadown"
QT_MOC_LITERAL(94, 2304, 28), // "on_actionAdd_Image_triggered"
QT_MOC_LITERAL(95, 2333, 11), // "SaveTimeLog"
QT_MOC_LITERAL(96, 2345, 14), // "DisplayTimeLog"
QT_MOC_LITERAL(97, 2360, 31), // "on_actionResize_Image_triggered"
QT_MOC_LITERAL(98, 2392, 13), // "LogHighlights"
QT_MOC_LITERAL(99, 2406, 4), // "word"
QT_MOC_LITERAL(100, 2411, 32), // "on_compareVerifierOutput_clicked"
QT_MOC_LITERAL(101, 2444, 20), // "on_sanButton_toggled"
QT_MOC_LITERAL(102, 2465, 7), // "checked"
QT_MOC_LITERAL(103, 2473, 20), // "on_hinButton_toggled"
QT_MOC_LITERAL(104, 2494, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(105, 2523, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(106, 2547, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(107, 2571, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(108, 2602, 33), // "on_actionInsert_Table_2_trigg..."
QT_MOC_LITERAL(109, 2636, 10), // "closeEvent"
QT_MOC_LITERAL(110, 2647, 12), // "QCloseEvent*"
QT_MOC_LITERAL(111, 2660, 5), // "event"
QT_MOC_LITERAL(112, 2666, 20), // "getAverageAccuracies"
QT_MOC_LITERAL(113, 2687, 7), // "mainObj"
QT_MOC_LITERAL(114, 2695, 9), // "sendEmail"
QT_MOC_LITERAL(115, 2705, 7), // "message"
QT_MOC_LITERAL(116, 2713, 36), // "on_actionInsert_Columnleft_tr..."
QT_MOC_LITERAL(117, 2750, 37), // "on_actionInsert_Columnright_t..."
QT_MOC_LITERAL(118, 2788, 34), // "on_actionInsert_Rowabove_trig..."
QT_MOC_LITERAL(119, 2823, 34), // "on_actionInsert_Rowbelow_trig..."
QT_MOC_LITERAL(120, 2858, 32), // "on_actionRemove_Column_triggered"
QT_MOC_LITERAL(121, 2891, 29), // "on_actionRemove_Row_triggered"
QT_MOC_LITERAL(122, 2921, 25), // "on_actionItalic_triggered"
QT_MOC_LITERAL(123, 2947, 28), // "on_actionNonitalic_triggered"
QT_MOC_LITERAL(124, 2976, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(125, 3004, 35), // "on_actionFind_and_Replace_tri..."
QT_MOC_LITERAL(126, 3040, 16), // "checkUnsavedWork"
QT_MOC_LITERAL(127, 3057, 11) // "saveAllWork"

    },
    "MainWindow\0DisplayJsonDict\0\0eventFilter\0"
    "QEvent*\0on_actionNew_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionSpell_Check_triggered\0"
    "mousePressEvent\0QMouseEvent*\0ev\0"
    "menuSelection\0QAction*\0action\0"
    "translate_replace\0on_actionLoad_Next_Page_triggered\0"
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
    "on_actionHighlight_triggered\0"
    "on_actionFontBlack_triggered\0"
    "updateAverageAccuracies\0"
    "on_actionViewAverageAccuracies_triggered\0"
    "on_actionOpen_Project_triggered\0"
    "file_click\0QModelIndex\0indx\0LoadDocument\0"
    "QFile*\0file\0ext\0name\0LoadImageFromFile\0"
    "CustomContextMenuTriggered\0p\0AddNewFile\0"
    "OpenDirectory\0RemoveFile\0closetab\0"
    "index\0tabchanged\0on_actionTurn_In_triggered\0"
    "on_actionPush_triggered\0"
    "on_actionFetch_2_triggered\0"
    "on_actionVerifier_Turn_In_triggered\0"
    "directoryChanged\0path\0"
    "on_actionAccuracyLog_triggered\0"
    "on_compareCorrectorOutput_clicked\0"
    "on_viewComments_clicked\0"
    "on_actionZoom_In_triggered\0"
    "on_actionZoom_Out_triggered\0"
    "on_actionSymbols_triggered\0"
    "on_actionInsert_Tab_Space_triggered\0"
    "on_actionInsert_Horizontal_Line_triggered\0"
    "on_actionSubscript_triggered\0"
    "on_actionSuperscript_triggered\0"
    "UpdateFileBrekadown\0on_actionAdd_Image_triggered\0"
    "SaveTimeLog\0DisplayTimeLog\0"
    "on_actionResize_Image_triggered\0"
    "LogHighlights\0word\0on_compareVerifierOutput_clicked\0"
    "on_sanButton_toggled\0checked\0"
    "on_hinButton_toggled\0on_actionLineSpace_triggered\0"
    "on_actionUndo_triggered\0on_actionRedo_triggered\0"
    "on_actionNew_Project_triggered\0"
    "on_actionInsert_Table_2_triggered\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "getAverageAccuracies\0mainObj\0sendEmail\0"
    "message\0on_actionInsert_Columnleft_triggered\0"
    "on_actionInsert_Columnright_triggered\0"
    "on_actionInsert_Rowabove_triggered\0"
    "on_actionInsert_Rowbelow_triggered\0"
    "on_actionRemove_Column_triggered\0"
    "on_actionRemove_Row_triggered\0"
    "on_actionItalic_triggered\0"
    "on_actionNonitalic_triggered\0"
    "on_actionSave_All_triggered\0"
    "on_actionFind_and_Replace_triggered\0"
    "checkUnsavedWork\0saveAllWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     106,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  544,    2, 0x08 /* Private */,
       3,    2,  545,    2, 0x08 /* Private */,
       5,    0,  550,    2, 0x08 /* Private */,
       6,    0,  551,    2, 0x08 /* Private */,
       7,    0,  552,    2, 0x08 /* Private */,
       8,    0,  553,    2, 0x08 /* Private */,
       9,    1,  554,    2, 0x08 /* Private */,
      12,    1,  557,    2, 0x08 /* Private */,
      15,    1,  560,    2, 0x08 /* Private */,
      16,    0,  563,    2, 0x08 /* Private */,
      17,    0,  564,    2, 0x08 /* Private */,
      18,    0,  565,    2, 0x08 /* Private */,
      19,    0,  566,    2, 0x08 /* Private */,
      20,    0,  567,    2, 0x08 /* Private */,
      21,    0,  568,    2, 0x08 /* Private */,
      22,    0,  569,    2, 0x08 /* Private */,
      23,    0,  570,    2, 0x08 /* Private */,
      24,    0,  571,    2, 0x08 /* Private */,
      25,    0,  572,    2, 0x08 /* Private */,
      26,    0,  573,    2, 0x08 /* Private */,
      27,    0,  574,    2, 0x08 /* Private */,
      28,    0,  575,    2, 0x08 /* Private */,
      29,    0,  576,    2, 0x08 /* Private */,
      30,    0,  577,    2, 0x08 /* Private */,
      31,    0,  578,    2, 0x08 /* Private */,
      32,    0,  579,    2, 0x08 /* Private */,
      33,    0,  580,    2, 0x08 /* Private */,
      34,    0,  581,    2, 0x08 /* Private */,
      35,    0,  582,    2, 0x08 /* Private */,
      36,    0,  583,    2, 0x08 /* Private */,
      37,    0,  584,    2, 0x08 /* Private */,
      38,    0,  585,    2, 0x08 /* Private */,
      39,    0,  586,    2, 0x08 /* Private */,
      40,    0,  587,    2, 0x08 /* Private */,
      41,    0,  588,    2, 0x08 /* Private */,
      42,    0,  589,    2, 0x08 /* Private */,
      43,    0,  590,    2, 0x08 /* Private */,
      44,    0,  591,    2, 0x08 /* Private */,
      45,    0,  592,    2, 0x08 /* Private */,
      46,    0,  593,    2, 0x08 /* Private */,
      47,    0,  594,    2, 0x08 /* Private */,
      48,    0,  595,    2, 0x08 /* Private */,
      49,    0,  596,    2, 0x08 /* Private */,
      50,    0,  597,    2, 0x08 /* Private */,
      51,    0,  598,    2, 0x08 /* Private */,
      52,    0,  599,    2, 0x08 /* Private */,
      53,    0,  600,    2, 0x08 /* Private */,
      54,    0,  601,    2, 0x08 /* Private */,
      55,    0,  602,    2, 0x08 /* Private */,
      56,    0,  603,    2, 0x08 /* Private */,
      57,    0,  604,    2, 0x08 /* Private */,
      58,    0,  605,    2, 0x08 /* Private */,
      59,    0,  606,    2, 0x08 /* Private */,
      60,    1,  607,    2, 0x08 /* Private */,
      63,    3,  610,    2, 0x08 /* Private */,
      68,    1,  617,    2, 0x08 /* Private */,
      69,    1,  620,    2, 0x08 /* Private */,
      71,    0,  623,    2, 0x08 /* Private */,
      72,    0,  624,    2, 0x08 /* Private */,
      73,    0,  625,    2, 0x08 /* Private */,
      74,    1,  626,    2, 0x08 /* Private */,
      76,    1,  629,    2, 0x08 /* Private */,
      77,    0,  632,    2, 0x08 /* Private */,
      78,    0,  633,    2, 0x08 /* Private */,
      79,    0,  634,    2, 0x08 /* Private */,
      80,    0,  635,    2, 0x08 /* Private */,
      81,    1,  636,    2, 0x08 /* Private */,
      83,    0,  639,    2, 0x08 /* Private */,
      84,    0,  640,    2, 0x08 /* Private */,
      85,    0,  641,    2, 0x08 /* Private */,
      86,    0,  642,    2, 0x08 /* Private */,
      87,    0,  643,    2, 0x08 /* Private */,
      88,    0,  644,    2, 0x08 /* Private */,
      89,    0,  645,    2, 0x08 /* Private */,
      90,    0,  646,    2, 0x08 /* Private */,
      91,    0,  647,    2, 0x08 /* Private */,
      92,    0,  648,    2, 0x08 /* Private */,
      93,    0,  649,    2, 0x08 /* Private */,
      94,    0,  650,    2, 0x08 /* Private */,
      95,    0,  651,    2, 0x08 /* Private */,
      96,    0,  652,    2, 0x08 /* Private */,
      97,    0,  653,    2, 0x08 /* Private */,
      98,    1,  654,    2, 0x08 /* Private */,
     100,    0,  657,    2, 0x08 /* Private */,
     101,    1,  658,    2, 0x08 /* Private */,
     103,    1,  661,    2, 0x08 /* Private */,
     104,    0,  664,    2, 0x08 /* Private */,
     105,    0,  665,    2, 0x08 /* Private */,
     106,    0,  666,    2, 0x08 /* Private */,
     107,    0,  667,    2, 0x08 /* Private */,
     108,    0,  668,    2, 0x08 /* Private */,
     109,    1,  669,    2, 0x08 /* Private */,
     112,    1,  672,    2, 0x08 /* Private */,
     114,    1,  675,    2, 0x08 /* Private */,
     116,    0,  678,    2, 0x08 /* Private */,
     117,    0,  679,    2, 0x08 /* Private */,
     118,    0,  680,    2, 0x08 /* Private */,
     119,    0,  681,    2, 0x08 /* Private */,
     120,    0,  682,    2, 0x08 /* Private */,
     121,    0,  683,    2, 0x08 /* Private */,
     122,    0,  684,    2, 0x08 /* Private */,
     123,    0,  685,    2, 0x08 /* Private */,
     124,    0,  686,    2, 0x08 /* Private */,
     125,    0,  687,    2, 0x08 /* Private */,
     126,    0,  688,    2, 0x08 /* Private */,
     127,    0,  689,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,    2,
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
    QMetaType::Void, 0x80000000 | 61,   62,
    QMetaType::Void, 0x80000000 | 64, QMetaType::QString, QMetaType::QString,   65,   66,   67,
    QMetaType::Void, 0x80000000 | 64,   65,
    QMetaType::Void, QMetaType::QPoint,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   75,
    QMetaType::Void, QMetaType::Int,   75,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   99,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  102,
    QMetaType::Void, QMetaType::Bool,  102,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 110,  111,
    QMetaType::QJsonObject, QMetaType::QJsonObject,  113,
    QMetaType::Bool, QMetaType::QString,  115,
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
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DisplayJsonDict(); break;
        case 1: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_actionNew_triggered(); break;
        case 3: _t->on_actionSave_triggered(); break;
        case 4: _t->on_actionSave_As_triggered(); break;
        case 5: _t->on_actionSpell_Check_triggered(); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->translate_replace((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->on_actionLoad_Next_Page_triggered(); break;
        case 10: _t->on_actionLoad_Prev_Page_triggered(); break;
        case 11: _t->on_actionLoadGDocPage_triggered(); break;
        case 12: _t->on_actionToDevanagari_triggered(); break;
        case 13: _t->on_actionLoadData_triggered(); break;
        case 14: _t->on_actionLoadDict_triggered(); break;
        case 15: _t->on_actionLoadOCRWords_triggered(); break;
        case 16: _t->on_actionLoadDomain_triggered(); break;
        case 17: _t->on_actionLoadSubPS_triggered(); break;
        case 18: _t->on_actionLoadConfusions_triggered(); break;
        case 19: _t->on_actionSugg_triggered(); break;
        case 20: _t->on_actionCreateBest2OCR_triggered(); break;
        case 21: _t->on_actionToSlp1_triggered(); break;
        case 22: _t->on_actionCreateSuggestionLog_triggered(); break;
        case 23: _t->on_actionCreateSuggestionLogNearestPriority_triggered(); break;
        case 24: _t->on_actionErrorDetectionRep_triggered(); break;
        case 25: _t->on_actionErrorDetectWithoutAdaptation_triggered(); break;
        case 26: _t->on_actionCPair_triggered(); break;
        case 27: _t->on_actionToSlp1_2_triggered(); break;
        case 28: _t->on_actionToDev_triggered(); break;
        case 29: _t->on_actionExtractDev_triggered(); break;
        case 30: _t->on_actionPrimarySecOCRPair_triggered(); break;
        case 31: _t->on_actionCPairIEROcrVsCorrect_triggered(); break;
        case 32: _t->on_actionEditDistRep_triggered(); break;
        case 33: _t->on_actionConfusionFreqHist_triggered(); break;
        case 34: _t->on_actionCPairGEROcrVsCorrect_triggered(); break;
        case 35: _t->on_actionFilterOutGT50EditDisPairs_triggered(); break;
        case 36: _t->on_actionPrepareFeatures_triggered(); break;
        case 37: _t->on_actionErrorDetectionRepUniq_triggered(); break;
        case 38: _t->on_actionSanskrit_triggered(); break;
        case 39: _t->on_actionHindi_triggered(); break;
        case 40: _t->on_actionEnglish_triggered(); break;
        case 41: _t->on_actionBold_triggered(); break;
        case 42: _t->on_actionLeftAlign_triggered(); break;
        case 43: _t->on_actionRightAlign_triggered(); break;
        case 44: _t->on_actionCentreAlign_triggered(); break;
        case 45: _t->on_actionAllFontProperties_triggered(); break;
        case 46: _t->on_actionUnBold_triggered(); break;
        case 47: _t->on_actionJusitfiedAlign_triggered(); break;
        case 48: _t->on_actionHighlight_triggered(); break;
        case 49: _t->on_actionFontBlack_triggered(); break;
        case 50: _t->updateAverageAccuracies(); break;
        case 51: _t->on_actionViewAverageAccuracies_triggered(); break;
        case 52: _t->on_actionOpen_Project_triggered(); break;
        case 53: _t->file_click((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 54: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 55: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 56: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 57: _t->AddNewFile(); break;
        case 58: _t->OpenDirectory(); break;
        case 59: _t->RemoveFile(); break;
        case 60: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 72: _t->on_actionSymbols_triggered(); break;
        case 73: _t->on_actionInsert_Tab_Space_triggered(); break;
        case 74: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 75: _t->on_actionSubscript_triggered(); break;
        case 76: _t->on_actionSuperscript_triggered(); break;
        case 77: _t->UpdateFileBrekadown(); break;
        case 78: _t->on_actionAdd_Image_triggered(); break;
        case 79: _t->SaveTimeLog(); break;
        case 80: _t->DisplayTimeLog(); break;
        case 81: _t->on_actionResize_Image_triggered(); break;
        case 82: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 83: _t->on_compareVerifierOutput_clicked(); break;
        case 84: _t->on_sanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 85: _t->on_hinButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 86: _t->on_actionLineSpace_triggered(); break;
        case 87: _t->on_actionUndo_triggered(); break;
        case 88: _t->on_actionRedo_triggered(); break;
        case 89: _t->on_actionNew_Project_triggered(); break;
        case 90: _t->on_actionInsert_Table_2_triggered(); break;
        case 91: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 92: { QJsonObject _r = _t->getAverageAccuracies((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 93: { bool _r = _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 94: _t->on_actionInsert_Columnleft_triggered(); break;
        case 95: _t->on_actionInsert_Columnright_triggered(); break;
        case 96: _t->on_actionInsert_Rowabove_triggered(); break;
        case 97: _t->on_actionInsert_Rowbelow_triggered(); break;
        case 98: _t->on_actionRemove_Column_triggered(); break;
        case 99: _t->on_actionRemove_Row_triggered(); break;
        case 100: _t->on_actionItalic_triggered(); break;
        case 101: _t->on_actionNonitalic_triggered(); break;
        case 102: _t->on_actionSave_All_triggered(); break;
        case 103: _t->on_actionFind_and_Replace_triggered(); break;
        case 104: { bool _r = _t->checkUnsavedWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 105: _t->saveAllWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 54:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 55:
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
    &QMainWindow::staticMetaObject,
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
        if (_id < 106)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 106;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 106)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 106;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
