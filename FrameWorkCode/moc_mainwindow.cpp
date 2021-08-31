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
    QByteArrayData data[136];
    char stringdata0[3208];
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
QT_MOC_LITERAL(5, 48, 15), // "saveImageRegion"
QT_MOC_LITERAL(6, 64, 13), // "displayHolder"
QT_MOC_LITERAL(7, 78, 13), // "updateEntries"
QT_MOC_LITERAL(8, 92, 12), // "QDomDocument"
QT_MOC_LITERAL(9, 105, 22), // "createImageInfoXMLFile"
QT_MOC_LITERAL(10, 128, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(11, 151, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(12, 175, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(13, 202, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(14, 233, 15), // "mousePressEvent"
QT_MOC_LITERAL(15, 249, 12), // "QMouseEvent*"
QT_MOC_LITERAL(16, 262, 2), // "ev"
QT_MOC_LITERAL(17, 265, 13), // "menuSelection"
QT_MOC_LITERAL(18, 279, 8), // "QAction*"
QT_MOC_LITERAL(19, 288, 6), // "action"
QT_MOC_LITERAL(20, 295, 17), // "translate_replace"
QT_MOC_LITERAL(21, 313, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(22, 347, 33), // "on_actionLoad_Prev_Page_trigg..."
QT_MOC_LITERAL(23, 381, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(24, 413, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(25, 445, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(26, 473, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(27, 501, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(28, 533, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(29, 563, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(30, 592, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(31, 626, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(32, 650, 33), // "on_actionCreateBest2OCR_trigg..."
QT_MOC_LITERAL(33, 684, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(34, 710, 38), // "on_actionCreateSuggestionLog_..."
QT_MOC_LITERAL(35, 749, 53), // "on_actionCreateSuggestionLogN..."
QT_MOC_LITERAL(36, 803, 36), // "on_actionErrorDetectionRep_tr..."
QT_MOC_LITERAL(37, 840, 47), // "on_actionErrorDetectWithoutAd..."
QT_MOC_LITERAL(38, 888, 24), // "on_actionCPair_triggered"
QT_MOC_LITERAL(39, 913, 27), // "on_actionToSlp1_2_triggered"
QT_MOC_LITERAL(40, 941, 24), // "on_actionToDev_triggered"
QT_MOC_LITERAL(41, 966, 29), // "on_actionExtractDev_triggered"
QT_MOC_LITERAL(42, 996, 36), // "on_actionPrimarySecOCRPair_tr..."
QT_MOC_LITERAL(43, 1033, 39), // "on_actionCPairIEROcrVsCorrect..."
QT_MOC_LITERAL(44, 1073, 30), // "on_actionEditDistRep_triggered"
QT_MOC_LITERAL(45, 1104, 36), // "on_actionConfusionFreqHist_tr..."
QT_MOC_LITERAL(46, 1141, 39), // "on_actionCPairGEROcrVsCorrect..."
QT_MOC_LITERAL(47, 1181, 44), // "on_actionFilterOutGT50EditDis..."
QT_MOC_LITERAL(48, 1226, 34), // "on_actionPrepareFeatures_trig..."
QT_MOC_LITERAL(49, 1261, 40), // "on_actionErrorDetectionRepUni..."
QT_MOC_LITERAL(50, 1302, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(51, 1330, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(52, 1355, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(53, 1382, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(54, 1406, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(55, 1435, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(56, 1465, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(57, 1496, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(58, 1533, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(59, 1559, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(60, 1593, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(61, 1622, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(62, 1651, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(63, 1675, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(64, 1716, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(65, 1748, 10), // "file_click"
QT_MOC_LITERAL(66, 1759, 11), // "QModelIndex"
QT_MOC_LITERAL(67, 1771, 4), // "indx"
QT_MOC_LITERAL(68, 1776, 12), // "LoadDocument"
QT_MOC_LITERAL(69, 1789, 6), // "QFile*"
QT_MOC_LITERAL(70, 1796, 4), // "file"
QT_MOC_LITERAL(71, 1801, 3), // "ext"
QT_MOC_LITERAL(72, 1805, 4), // "name"
QT_MOC_LITERAL(73, 1810, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(74, 1828, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(75, 1855, 1), // "p"
QT_MOC_LITERAL(76, 1857, 10), // "AddNewFile"
QT_MOC_LITERAL(77, 1868, 13), // "OpenDirectory"
QT_MOC_LITERAL(78, 1882, 10), // "RemoveFile"
QT_MOC_LITERAL(79, 1893, 8), // "closetab"
QT_MOC_LITERAL(80, 1902, 5), // "index"
QT_MOC_LITERAL(81, 1908, 10), // "tabchanged"
QT_MOC_LITERAL(82, 1919, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(83, 1946, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(84, 1970, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(85, 1997, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(86, 2033, 16), // "directoryChanged"
QT_MOC_LITERAL(87, 2050, 4), // "path"
QT_MOC_LITERAL(88, 2055, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(89, 2086, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(90, 2120, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(91, 2144, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(92, 2171, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(93, 2199, 26), // "on_actionSymbols_triggered"
QT_MOC_LITERAL(94, 2226, 35), // "on_actionInsert_Tab_Space_tri..."
QT_MOC_LITERAL(95, 2262, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(96, 2304, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(97, 2333, 30), // "on_actionSuperscript_triggered"
QT_MOC_LITERAL(98, 2364, 19), // "UpdateFileBrekadown"
QT_MOC_LITERAL(99, 2384, 28), // "on_actionAdd_Image_triggered"
QT_MOC_LITERAL(100, 2413, 11), // "SaveTimeLog"
QT_MOC_LITERAL(101, 2425, 14), // "DisplayTimeLog"
QT_MOC_LITERAL(102, 2440, 31), // "on_actionResize_Image_triggered"
QT_MOC_LITERAL(103, 2472, 13), // "LogHighlights"
QT_MOC_LITERAL(104, 2486, 4), // "word"
QT_MOC_LITERAL(105, 2491, 32), // "on_compareVerifierOutput_clicked"
QT_MOC_LITERAL(106, 2524, 20), // "on_sanButton_toggled"
QT_MOC_LITERAL(107, 2545, 7), // "checked"
QT_MOC_LITERAL(108, 2553, 20), // "on_hinButton_toggled"
QT_MOC_LITERAL(109, 2574, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(110, 2603, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(111, 2627, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(112, 2651, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(113, 2682, 33), // "on_actionInsert_Table_2_trigg..."
QT_MOC_LITERAL(114, 2716, 10), // "closeEvent"
QT_MOC_LITERAL(115, 2727, 12), // "QCloseEvent*"
QT_MOC_LITERAL(116, 2740, 5), // "event"
QT_MOC_LITERAL(117, 2746, 20), // "getAverageAccuracies"
QT_MOC_LITERAL(118, 2767, 7), // "mainObj"
QT_MOC_LITERAL(119, 2775, 9), // "sendEmail"
QT_MOC_LITERAL(120, 2785, 7), // "message"
QT_MOC_LITERAL(121, 2793, 36), // "on_actionInsert_Columnleft_tr..."
QT_MOC_LITERAL(122, 2830, 37), // "on_actionInsert_Columnright_t..."
QT_MOC_LITERAL(123, 2868, 34), // "on_actionInsert_Rowabove_trig..."
QT_MOC_LITERAL(124, 2903, 34), // "on_actionInsert_Rowbelow_trig..."
QT_MOC_LITERAL(125, 2938, 32), // "on_actionRemove_Column_triggered"
QT_MOC_LITERAL(126, 2971, 29), // "on_actionRemove_Row_triggered"
QT_MOC_LITERAL(127, 3001, 25), // "on_actionItalic_triggered"
QT_MOC_LITERAL(128, 3027, 28), // "on_actionNonitalic_triggered"
QT_MOC_LITERAL(129, 3056, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(130, 3084, 35), // "on_actionFind_and_Replace_tri..."
QT_MOC_LITERAL(131, 3120, 16), // "checkUnsavedWork"
QT_MOC_LITERAL(132, 3137, 11), // "saveAllWork"
QT_MOC_LITERAL(133, 3149, 12), // "setMFilename"
QT_MOC_LITERAL(134, 3162, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(135, 3184, 23) // "on_pushButton_2_clicked"

    },
    "MainWindow\0DisplayJsonDict\0\0eventFilter\0"
    "QEvent*\0saveImageRegion\0displayHolder\0"
    "updateEntries\0QDomDocument\0"
    "createImageInfoXMLFile\0on_actionNew_triggered\0"
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
    "checkUnsavedWork\0saveAllWork\0setMFilename\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     113,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  579,    2, 0x08 /* Private */,
       3,    2,  580,    2, 0x08 /* Private */,
       5,    6,  585,    2, 0x08 /* Private */,
       6,    8,  598,    2, 0x08 /* Private */,
       7,    5,  615,    2, 0x08 /* Private */,
       9,    0,  626,    2, 0x08 /* Private */,
      10,    0,  627,    2, 0x08 /* Private */,
      11,    0,  628,    2, 0x08 /* Private */,
      12,    0,  629,    2, 0x08 /* Private */,
      13,    0,  630,    2, 0x08 /* Private */,
      14,    1,  631,    2, 0x08 /* Private */,
      17,    1,  634,    2, 0x08 /* Private */,
      20,    1,  637,    2, 0x08 /* Private */,
      21,    0,  640,    2, 0x08 /* Private */,
      22,    0,  641,    2, 0x08 /* Private */,
      23,    0,  642,    2, 0x08 /* Private */,
      24,    0,  643,    2, 0x08 /* Private */,
      25,    0,  644,    2, 0x08 /* Private */,
      26,    0,  645,    2, 0x08 /* Private */,
      27,    0,  646,    2, 0x08 /* Private */,
      28,    0,  647,    2, 0x08 /* Private */,
      29,    0,  648,    2, 0x08 /* Private */,
      30,    0,  649,    2, 0x08 /* Private */,
      31,    0,  650,    2, 0x08 /* Private */,
      32,    0,  651,    2, 0x08 /* Private */,
      33,    0,  652,    2, 0x08 /* Private */,
      34,    0,  653,    2, 0x08 /* Private */,
      35,    0,  654,    2, 0x08 /* Private */,
      36,    0,  655,    2, 0x08 /* Private */,
      37,    0,  656,    2, 0x08 /* Private */,
      38,    0,  657,    2, 0x08 /* Private */,
      39,    0,  658,    2, 0x08 /* Private */,
      40,    0,  659,    2, 0x08 /* Private */,
      41,    0,  660,    2, 0x08 /* Private */,
      42,    0,  661,    2, 0x08 /* Private */,
      43,    0,  662,    2, 0x08 /* Private */,
      44,    0,  663,    2, 0x08 /* Private */,
      45,    0,  664,    2, 0x08 /* Private */,
      46,    0,  665,    2, 0x08 /* Private */,
      47,    0,  666,    2, 0x08 /* Private */,
      48,    0,  667,    2, 0x08 /* Private */,
      49,    0,  668,    2, 0x08 /* Private */,
      50,    0,  669,    2, 0x08 /* Private */,
      51,    0,  670,    2, 0x08 /* Private */,
      52,    0,  671,    2, 0x08 /* Private */,
      53,    0,  672,    2, 0x08 /* Private */,
      54,    0,  673,    2, 0x08 /* Private */,
      55,    0,  674,    2, 0x08 /* Private */,
      56,    0,  675,    2, 0x08 /* Private */,
      57,    0,  676,    2, 0x08 /* Private */,
      58,    0,  677,    2, 0x08 /* Private */,
      59,    0,  678,    2, 0x08 /* Private */,
      60,    0,  679,    2, 0x08 /* Private */,
      61,    0,  680,    2, 0x08 /* Private */,
      62,    0,  681,    2, 0x08 /* Private */,
      63,    0,  682,    2, 0x08 /* Private */,
      64,    0,  683,    2, 0x08 /* Private */,
      65,    1,  684,    2, 0x08 /* Private */,
      68,    3,  687,    2, 0x08 /* Private */,
      73,    1,  694,    2, 0x08 /* Private */,
      74,    1,  697,    2, 0x08 /* Private */,
      76,    0,  700,    2, 0x08 /* Private */,
      77,    0,  701,    2, 0x08 /* Private */,
      78,    0,  702,    2, 0x08 /* Private */,
      79,    1,  703,    2, 0x08 /* Private */,
      81,    1,  706,    2, 0x08 /* Private */,
      82,    0,  709,    2, 0x08 /* Private */,
      83,    0,  710,    2, 0x08 /* Private */,
      84,    0,  711,    2, 0x08 /* Private */,
      85,    0,  712,    2, 0x08 /* Private */,
      86,    1,  713,    2, 0x08 /* Private */,
      88,    0,  716,    2, 0x08 /* Private */,
      89,    0,  717,    2, 0x08 /* Private */,
      90,    0,  718,    2, 0x08 /* Private */,
      91,    0,  719,    2, 0x08 /* Private */,
      92,    0,  720,    2, 0x08 /* Private */,
      93,    0,  721,    2, 0x08 /* Private */,
      94,    0,  722,    2, 0x08 /* Private */,
      95,    0,  723,    2, 0x08 /* Private */,
      96,    0,  724,    2, 0x08 /* Private */,
      97,    0,  725,    2, 0x08 /* Private */,
      98,    0,  726,    2, 0x08 /* Private */,
      99,    0,  727,    2, 0x08 /* Private */,
     100,    0,  728,    2, 0x08 /* Private */,
     101,    0,  729,    2, 0x08 /* Private */,
     102,    0,  730,    2, 0x08 /* Private */,
     103,    1,  731,    2, 0x08 /* Private */,
     105,    0,  734,    2, 0x08 /* Private */,
     106,    1,  735,    2, 0x08 /* Private */,
     108,    1,  738,    2, 0x08 /* Private */,
     109,    0,  741,    2, 0x08 /* Private */,
     110,    0,  742,    2, 0x08 /* Private */,
     111,    0,  743,    2, 0x08 /* Private */,
     112,    0,  744,    2, 0x08 /* Private */,
     113,    0,  745,    2, 0x08 /* Private */,
     114,    1,  746,    2, 0x08 /* Private */,
     117,    1,  749,    2, 0x08 /* Private */,
     119,    1,  752,    2, 0x08 /* Private */,
     121,    0,  755,    2, 0x08 /* Private */,
     122,    0,  756,    2, 0x08 /* Private */,
     123,    0,  757,    2, 0x08 /* Private */,
     124,    0,  758,    2, 0x08 /* Private */,
     125,    0,  759,    2, 0x08 /* Private */,
     126,    0,  760,    2, 0x08 /* Private */,
     127,    0,  761,    2, 0x08 /* Private */,
     128,    0,  762,    2, 0x08 /* Private */,
     129,    0,  763,    2, 0x08 /* Private */,
     130,    0,  764,    2, 0x08 /* Private */,
     131,    0,  765,    2, 0x08 /* Private */,
     132,    0,  766,    2, 0x08 /* Private */,
     133,    1,  767,    2, 0x08 /* Private */,
     134,    0,  770,    2, 0x08 /* Private */,
     135,    0,  771,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,    2,
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
    QMetaType::Void, 0x80000000 | 66,   67,
    QMetaType::Void, 0x80000000 | 69, QMetaType::QString, QMetaType::QString,   70,   71,   72,
    QMetaType::Void, 0x80000000 | 69,   70,
    QMetaType::Void, QMetaType::QPoint,   75,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   80,
    QMetaType::Void, QMetaType::Int,   80,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   87,
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
    QMetaType::Void, QMetaType::QString,  104,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  107,
    QMetaType::Void, QMetaType::Bool,  107,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 115,  116,
    QMetaType::QJsonObject, QMetaType::QJsonObject,  118,
    QMetaType::Bool, QMetaType::QString,  120,
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
    QMetaType::Void, QMetaType::QString,    2,
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
        case 0: _t->DisplayJsonDict(); break;
        case 1: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->saveImageRegion((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 3: _t->displayHolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 4: _t->updateEntries((*reinterpret_cast< QDomDocument(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->createImageInfoXMLFile(); break;
        case 6: _t->on_actionNew_triggered(); break;
        case 7: _t->on_actionSave_triggered(); break;
        case 8: _t->on_actionSave_As_triggered(); break;
        case 9: _t->on_actionSpell_Check_triggered(); break;
        case 10: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 11: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 12: _t->translate_replace((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 13: _t->on_actionLoad_Next_Page_triggered(); break;
        case 14: _t->on_actionLoad_Prev_Page_triggered(); break;
        case 15: _t->on_actionLoadGDocPage_triggered(); break;
        case 16: _t->on_actionToDevanagari_triggered(); break;
        case 17: _t->on_actionLoadData_triggered(); break;
        case 18: _t->on_actionLoadDict_triggered(); break;
        case 19: _t->on_actionLoadOCRWords_triggered(); break;
        case 20: _t->on_actionLoadDomain_triggered(); break;
        case 21: _t->on_actionLoadSubPS_triggered(); break;
        case 22: _t->on_actionLoadConfusions_triggered(); break;
        case 23: _t->on_actionSugg_triggered(); break;
        case 24: _t->on_actionCreateBest2OCR_triggered(); break;
        case 25: _t->on_actionToSlp1_triggered(); break;
        case 26: _t->on_actionCreateSuggestionLog_triggered(); break;
        case 27: _t->on_actionCreateSuggestionLogNearestPriority_triggered(); break;
        case 28: _t->on_actionErrorDetectionRep_triggered(); break;
        case 29: _t->on_actionErrorDetectWithoutAdaptation_triggered(); break;
        case 30: _t->on_actionCPair_triggered(); break;
        case 31: _t->on_actionToSlp1_2_triggered(); break;
        case 32: _t->on_actionToDev_triggered(); break;
        case 33: _t->on_actionExtractDev_triggered(); break;
        case 34: _t->on_actionPrimarySecOCRPair_triggered(); break;
        case 35: _t->on_actionCPairIEROcrVsCorrect_triggered(); break;
        case 36: _t->on_actionEditDistRep_triggered(); break;
        case 37: _t->on_actionConfusionFreqHist_triggered(); break;
        case 38: _t->on_actionCPairGEROcrVsCorrect_triggered(); break;
        case 39: _t->on_actionFilterOutGT50EditDisPairs_triggered(); break;
        case 40: _t->on_actionPrepareFeatures_triggered(); break;
        case 41: _t->on_actionErrorDetectionRepUniq_triggered(); break;
        case 42: _t->on_actionSanskrit_triggered(); break;
        case 43: _t->on_actionHindi_triggered(); break;
        case 44: _t->on_actionEnglish_triggered(); break;
        case 45: _t->on_actionBold_triggered(); break;
        case 46: _t->on_actionLeftAlign_triggered(); break;
        case 47: _t->on_actionRightAlign_triggered(); break;
        case 48: _t->on_actionCentreAlign_triggered(); break;
        case 49: _t->on_actionAllFontProperties_triggered(); break;
        case 50: _t->on_actionUnBold_triggered(); break;
        case 51: _t->on_actionJusitfiedAlign_triggered(); break;
        case 52: _t->on_actionHighlight_triggered(); break;
        case 53: _t->on_actionFontBlack_triggered(); break;
        case 54: _t->updateAverageAccuracies(); break;
        case 55: _t->on_actionViewAverageAccuracies_triggered(); break;
        case 56: _t->on_actionOpen_Project_triggered(); break;
        case 57: _t->file_click((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 58: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 59: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 60: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 61: _t->AddNewFile(); break;
        case 62: _t->OpenDirectory(); break;
        case 63: _t->RemoveFile(); break;
        case 64: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->on_actionTurn_In_triggered(); break;
        case 67: _t->on_actionPush_triggered(); break;
        case 68: _t->on_actionFetch_2_triggered(); break;
        case 69: _t->on_actionVerifier_Turn_In_triggered(); break;
        case 70: _t->directoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 71: _t->on_actionAccuracyLog_triggered(); break;
        case 72: _t->on_compareCorrectorOutput_clicked(); break;
        case 73: _t->on_viewComments_clicked(); break;
        case 74: _t->on_actionZoom_In_triggered(); break;
        case 75: _t->on_actionZoom_Out_triggered(); break;
        case 76: _t->on_actionSymbols_triggered(); break;
        case 77: _t->on_actionInsert_Tab_Space_triggered(); break;
        case 78: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 79: _t->on_actionSubscript_triggered(); break;
        case 80: _t->on_actionSuperscript_triggered(); break;
        case 81: _t->UpdateFileBrekadown(); break;
        case 82: _t->on_actionAdd_Image_triggered(); break;
        case 83: _t->SaveTimeLog(); break;
        case 84: _t->DisplayTimeLog(); break;
        case 85: _t->on_actionResize_Image_triggered(); break;
        case 86: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 87: _t->on_compareVerifierOutput_clicked(); break;
        case 88: _t->on_sanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 89: _t->on_hinButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 90: _t->on_actionLineSpace_triggered(); break;
        case 91: _t->on_actionUndo_triggered(); break;
        case 92: _t->on_actionRedo_triggered(); break;
        case 93: _t->on_actionNew_Project_triggered(); break;
        case 94: _t->on_actionInsert_Table_2_triggered(); break;
        case 95: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 96: { QJsonObject _r = _t->getAverageAccuracies((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 97: { bool _r = _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 98: _t->on_actionInsert_Columnleft_triggered(); break;
        case 99: _t->on_actionInsert_Columnright_triggered(); break;
        case 100: _t->on_actionInsert_Rowabove_triggered(); break;
        case 101: _t->on_actionInsert_Rowbelow_triggered(); break;
        case 102: _t->on_actionRemove_Column_triggered(); break;
        case 103: _t->on_actionRemove_Row_triggered(); break;
        case 104: _t->on_actionItalic_triggered(); break;
        case 105: _t->on_actionNonitalic_triggered(); break;
        case 106: _t->on_actionSave_All_triggered(); break;
        case 107: _t->on_actionFind_and_Replace_triggered(); break;
        case 108: { bool _r = _t->checkUnsavedWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 109: _t->saveAllWork(); break;
        case 110: _t->setMFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 111: _t->on_pushButton_clicked(); break;
        case 112: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 58:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 59:
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
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
