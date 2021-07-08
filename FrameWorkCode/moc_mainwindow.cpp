/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[125];
    char stringdata0[3023];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "eventFilter"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "QEvent*"
QT_MOC_LITERAL(4, 32, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(5, 55, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(6, 79, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(7, 106, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(8, 137, 15), // "mousePressEvent"
QT_MOC_LITERAL(9, 153, 12), // "QMouseEvent*"
QT_MOC_LITERAL(10, 166, 2), // "ev"
QT_MOC_LITERAL(11, 169, 13), // "menuSelection"
QT_MOC_LITERAL(12, 183, 8), // "QAction*"
QT_MOC_LITERAL(13, 192, 6), // "action"
QT_MOC_LITERAL(14, 199, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(15, 233, 33), // "on_actionLoad_Prev_Page_trigg..."
QT_MOC_LITERAL(16, 267, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(17, 299, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(18, 331, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(19, 359, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(20, 387, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(21, 419, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(22, 449, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(23, 478, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(24, 512, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(25, 536, 33), // "on_actionCreateBest2OCR_trigg..."
QT_MOC_LITERAL(26, 570, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(27, 596, 38), // "on_actionCreateSuggestionLog_..."
QT_MOC_LITERAL(28, 635, 53), // "on_actionCreateSuggestionLogN..."
QT_MOC_LITERAL(29, 689, 36), // "on_actionErrorDetectionRep_tr..."
QT_MOC_LITERAL(30, 726, 47), // "on_actionErrorDetectWithoutAd..."
QT_MOC_LITERAL(31, 774, 24), // "on_actionCPair_triggered"
QT_MOC_LITERAL(32, 799, 27), // "on_actionToSlp1_2_triggered"
QT_MOC_LITERAL(33, 827, 24), // "on_actionToDev_triggered"
QT_MOC_LITERAL(34, 852, 29), // "on_actionExtractDev_triggered"
QT_MOC_LITERAL(35, 882, 36), // "on_actionPrimarySecOCRPair_tr..."
QT_MOC_LITERAL(36, 919, 39), // "on_actionCPairIEROcrVsCorrect..."
QT_MOC_LITERAL(37, 959, 30), // "on_actionEditDistRep_triggered"
QT_MOC_LITERAL(38, 990, 36), // "on_actionConfusionFreqHist_tr..."
QT_MOC_LITERAL(39, 1027, 39), // "on_actionCPairGEROcrVsCorrect..."
QT_MOC_LITERAL(40, 1067, 44), // "on_actionFilterOutGT50EditDis..."
QT_MOC_LITERAL(41, 1112, 34), // "on_actionPrepareFeatures_trig..."
QT_MOC_LITERAL(42, 1147, 40), // "on_actionErrorDetectionRepUni..."
QT_MOC_LITERAL(43, 1188, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(44, 1216, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(45, 1241, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(46, 1268, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(47, 1292, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(48, 1321, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(49, 1351, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(50, 1382, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(51, 1419, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(52, 1445, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(53, 1479, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(54, 1508, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(55, 1537, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(56, 1561, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(57, 1602, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(58, 1634, 10), // "file_click"
QT_MOC_LITERAL(59, 1645, 4), // "indx"
QT_MOC_LITERAL(60, 1650, 12), // "LoadDocument"
QT_MOC_LITERAL(61, 1663, 6), // "QFile*"
QT_MOC_LITERAL(62, 1670, 4), // "file"
QT_MOC_LITERAL(63, 1675, 3), // "ext"
QT_MOC_LITERAL(64, 1679, 4), // "name"
QT_MOC_LITERAL(65, 1684, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(66, 1702, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(67, 1729, 1), // "p"
QT_MOC_LITERAL(68, 1731, 10), // "AddNewFile"
QT_MOC_LITERAL(69, 1742, 13), // "OpenDirectory"
QT_MOC_LITERAL(70, 1756, 10), // "RemoveFile"
QT_MOC_LITERAL(71, 1767, 8), // "closetab"
QT_MOC_LITERAL(72, 1776, 5), // "index"
QT_MOC_LITERAL(73, 1782, 10), // "tabchanged"
QT_MOC_LITERAL(74, 1793, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(75, 1820, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(76, 1844, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(77, 1871, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(78, 1907, 16), // "directoryChanged"
QT_MOC_LITERAL(79, 1924, 4), // "path"
QT_MOC_LITERAL(80, 1929, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(81, 1960, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(82, 1994, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(83, 2018, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(84, 2045, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(85, 2073, 26), // "on_actionSymbols_triggered"
QT_MOC_LITERAL(86, 2100, 35), // "on_actionInsert_Tab_Space_tri..."
QT_MOC_LITERAL(87, 2136, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(88, 2178, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(89, 2207, 30), // "on_actionSuperscript_triggered"
QT_MOC_LITERAL(90, 2238, 19), // "UpdateFileBrekadown"
QT_MOC_LITERAL(91, 2258, 28), // "on_actionAdd_Image_triggered"
QT_MOC_LITERAL(92, 2287, 11), // "SaveTimeLog"
QT_MOC_LITERAL(93, 2299, 14), // "DisplayTimeLog"
QT_MOC_LITERAL(94, 2314, 31), // "on_actionResize_Image_triggered"
QT_MOC_LITERAL(95, 2346, 13), // "LogHighlights"
QT_MOC_LITERAL(96, 2360, 4), // "word"
QT_MOC_LITERAL(97, 2365, 32), // "on_compareVerifierOutput_clicked"
QT_MOC_LITERAL(98, 2398, 20), // "on_sanButton_toggled"
QT_MOC_LITERAL(99, 2419, 7), // "checked"
QT_MOC_LITERAL(100, 2427, 20), // "on_hinButton_toggled"
QT_MOC_LITERAL(101, 2448, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(102, 2477, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(103, 2501, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(104, 2525, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(105, 2556, 33), // "on_actionInsert_Table_2_trigg..."
QT_MOC_LITERAL(106, 2590, 10), // "closeEvent"
QT_MOC_LITERAL(107, 2601, 12), // "QCloseEvent*"
QT_MOC_LITERAL(108, 2614, 5), // "event"
QT_MOC_LITERAL(109, 2620, 20), // "getAverageAccuracies"
QT_MOC_LITERAL(110, 2641, 7), // "mainObj"
QT_MOC_LITERAL(111, 2649, 9), // "sendEmail"
QT_MOC_LITERAL(112, 2659, 7), // "message"
QT_MOC_LITERAL(113, 2667, 36), // "on_actionInsert_Columnleft_tr..."
QT_MOC_LITERAL(114, 2704, 37), // "on_actionInsert_Columnright_t..."
QT_MOC_LITERAL(115, 2742, 34), // "on_actionInsert_Rowabove_trig..."
QT_MOC_LITERAL(116, 2777, 34), // "on_actionInsert_Rowbelow_trig..."
QT_MOC_LITERAL(117, 2812, 32), // "on_actionRemove_Column_triggered"
QT_MOC_LITERAL(118, 2845, 29), // "on_actionRemove_Row_triggered"
QT_MOC_LITERAL(119, 2875, 25), // "on_actionItalic_triggered"
QT_MOC_LITERAL(120, 2901, 28), // "on_actionNonitalic_triggered"
QT_MOC_LITERAL(121, 2930, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(122, 2958, 35), // "on_actionFind_and_Replace_tri..."
QT_MOC_LITERAL(123, 2994, 16), // "checkUnsavedWork"
QT_MOC_LITERAL(124, 3011, 11) // "saveAllWork"

    },
    "MainWindow\0eventFilter\0\0QEvent*\0"
    "on_actionNew_triggered\0on_actionSave_triggered\0"
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
    "on_actionHighlight_triggered\0"
    "on_actionFontBlack_triggered\0"
    "updateAverageAccuracies\0"
    "on_actionViewAverageAccuracies_triggered\0"
    "on_actionOpen_Project_triggered\0"
    "file_click\0indx\0LoadDocument\0QFile*\0"
    "file\0ext\0name\0LoadImageFromFile\0"
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
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     104,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  534,    2, 0x08 /* Private */,
       4,    0,  539,    2, 0x08 /* Private */,
       5,    0,  540,    2, 0x08 /* Private */,
       6,    0,  541,    2, 0x08 /* Private */,
       7,    0,  542,    2, 0x08 /* Private */,
       8,    1,  543,    2, 0x08 /* Private */,
      11,    1,  546,    2, 0x08 /* Private */,
      14,    0,  549,    2, 0x08 /* Private */,
      15,    0,  550,    2, 0x08 /* Private */,
      16,    0,  551,    2, 0x08 /* Private */,
      17,    0,  552,    2, 0x08 /* Private */,
      18,    0,  553,    2, 0x08 /* Private */,
      19,    0,  554,    2, 0x08 /* Private */,
      20,    0,  555,    2, 0x08 /* Private */,
      21,    0,  556,    2, 0x08 /* Private */,
      22,    0,  557,    2, 0x08 /* Private */,
      23,    0,  558,    2, 0x08 /* Private */,
      24,    0,  559,    2, 0x08 /* Private */,
      25,    0,  560,    2, 0x08 /* Private */,
      26,    0,  561,    2, 0x08 /* Private */,
      27,    0,  562,    2, 0x08 /* Private */,
      28,    0,  563,    2, 0x08 /* Private */,
      29,    0,  564,    2, 0x08 /* Private */,
      30,    0,  565,    2, 0x08 /* Private */,
      31,    0,  566,    2, 0x08 /* Private */,
      32,    0,  567,    2, 0x08 /* Private */,
      33,    0,  568,    2, 0x08 /* Private */,
      34,    0,  569,    2, 0x08 /* Private */,
      35,    0,  570,    2, 0x08 /* Private */,
      36,    0,  571,    2, 0x08 /* Private */,
      37,    0,  572,    2, 0x08 /* Private */,
      38,    0,  573,    2, 0x08 /* Private */,
      39,    0,  574,    2, 0x08 /* Private */,
      40,    0,  575,    2, 0x08 /* Private */,
      41,    0,  576,    2, 0x08 /* Private */,
      42,    0,  577,    2, 0x08 /* Private */,
      43,    0,  578,    2, 0x08 /* Private */,
      44,    0,  579,    2, 0x08 /* Private */,
      45,    0,  580,    2, 0x08 /* Private */,
      46,    0,  581,    2, 0x08 /* Private */,
      47,    0,  582,    2, 0x08 /* Private */,
      48,    0,  583,    2, 0x08 /* Private */,
      49,    0,  584,    2, 0x08 /* Private */,
      50,    0,  585,    2, 0x08 /* Private */,
      51,    0,  586,    2, 0x08 /* Private */,
      52,    0,  587,    2, 0x08 /* Private */,
      53,    0,  588,    2, 0x08 /* Private */,
      54,    0,  589,    2, 0x08 /* Private */,
      55,    0,  590,    2, 0x08 /* Private */,
      56,    0,  591,    2, 0x08 /* Private */,
      57,    0,  592,    2, 0x08 /* Private */,
      58,    1,  593,    2, 0x08 /* Private */,
      60,    3,  596,    2, 0x08 /* Private */,
      65,    1,  603,    2, 0x08 /* Private */,
      66,    1,  606,    2, 0x08 /* Private */,
      68,    0,  609,    2, 0x08 /* Private */,
      69,    0,  610,    2, 0x08 /* Private */,
      70,    0,  611,    2, 0x08 /* Private */,
      71,    1,  612,    2, 0x08 /* Private */,
      73,    1,  615,    2, 0x08 /* Private */,
      74,    0,  618,    2, 0x08 /* Private */,
      75,    0,  619,    2, 0x08 /* Private */,
      76,    0,  620,    2, 0x08 /* Private */,
      77,    0,  621,    2, 0x08 /* Private */,
      78,    1,  622,    2, 0x08 /* Private */,
      80,    0,  625,    2, 0x08 /* Private */,
      81,    0,  626,    2, 0x08 /* Private */,
      82,    0,  627,    2, 0x08 /* Private */,
      83,    0,  628,    2, 0x08 /* Private */,
      84,    0,  629,    2, 0x08 /* Private */,
      85,    0,  630,    2, 0x08 /* Private */,
      86,    0,  631,    2, 0x08 /* Private */,
      87,    0,  632,    2, 0x08 /* Private */,
      88,    0,  633,    2, 0x08 /* Private */,
      89,    0,  634,    2, 0x08 /* Private */,
      90,    0,  635,    2, 0x08 /* Private */,
      91,    0,  636,    2, 0x08 /* Private */,
      92,    0,  637,    2, 0x08 /* Private */,
      93,    0,  638,    2, 0x08 /* Private */,
      94,    0,  639,    2, 0x08 /* Private */,
      95,    1,  640,    2, 0x08 /* Private */,
      97,    0,  643,    2, 0x08 /* Private */,
      98,    1,  644,    2, 0x08 /* Private */,
     100,    1,  647,    2, 0x08 /* Private */,
     101,    0,  650,    2, 0x08 /* Private */,
     102,    0,  651,    2, 0x08 /* Private */,
     103,    0,  652,    2, 0x08 /* Private */,
     104,    0,  653,    2, 0x08 /* Private */,
     105,    0,  654,    2, 0x08 /* Private */,
     106,    1,  655,    2, 0x08 /* Private */,
     109,    1,  658,    2, 0x08 /* Private */,
     111,    1,  661,    2, 0x08 /* Private */,
     113,    0,  664,    2, 0x08 /* Private */,
     114,    0,  665,    2, 0x08 /* Private */,
     115,    0,  666,    2, 0x08 /* Private */,
     116,    0,  667,    2, 0x08 /* Private */,
     117,    0,  668,    2, 0x08 /* Private */,
     118,    0,  669,    2, 0x08 /* Private */,
     119,    0,  670,    2, 0x08 /* Private */,
     120,    0,  671,    2, 0x08 /* Private */,
     121,    0,  672,    2, 0x08 /* Private */,
     122,    0,  673,    2, 0x08 /* Private */,
     123,    0,  674,    2, 0x08 /* Private */,
     124,    0,  675,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
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
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void, 0x80000000 | 61, QMetaType::QString, QMetaType::QString,   62,   63,   64,
    QMetaType::Void, 0x80000000 | 61,   62,
    QMetaType::Void, QMetaType::QPoint,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   72,
    QMetaType::Void, QMetaType::Int,   72,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   79,
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
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   99,
    QMetaType::Void, QMetaType::Bool,   99,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 107,  108,
    QMetaType::QJsonObject, QMetaType::QJsonObject,  110,
    QMetaType::Bool, QMetaType::QString,  112,
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
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_actionNew_triggered(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionSave_As_triggered(); break;
        case 4: _t->on_actionSpell_Check_triggered(); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->on_actionLoad_Next_Page_triggered(); break;
        case 8: _t->on_actionLoad_Prev_Page_triggered(); break;
        case 9: _t->on_actionLoadGDocPage_triggered(); break;
        case 10: _t->on_actionToDevanagari_triggered(); break;
        case 11: _t->on_actionLoadData_triggered(); break;
        case 12: _t->on_actionLoadDict_triggered(); break;
        case 13: _t->on_actionLoadOCRWords_triggered(); break;
        case 14: _t->on_actionLoadDomain_triggered(); break;
        case 15: _t->on_actionLoadSubPS_triggered(); break;
        case 16: _t->on_actionLoadConfusions_triggered(); break;
        case 17: _t->on_actionSugg_triggered(); break;
        case 18: _t->on_actionCreateBest2OCR_triggered(); break;
        case 19: _t->on_actionToSlp1_triggered(); break;
        case 20: _t->on_actionCreateSuggestionLog_triggered(); break;
        case 21: _t->on_actionCreateSuggestionLogNearestPriority_triggered(); break;
        case 22: _t->on_actionErrorDetectionRep_triggered(); break;
        case 23: _t->on_actionErrorDetectWithoutAdaptation_triggered(); break;
        case 24: _t->on_actionCPair_triggered(); break;
        case 25: _t->on_actionToSlp1_2_triggered(); break;
        case 26: _t->on_actionToDev_triggered(); break;
        case 27: _t->on_actionExtractDev_triggered(); break;
        case 28: _t->on_actionPrimarySecOCRPair_triggered(); break;
        case 29: _t->on_actionCPairIEROcrVsCorrect_triggered(); break;
        case 30: _t->on_actionEditDistRep_triggered(); break;
        case 31: _t->on_actionConfusionFreqHist_triggered(); break;
        case 32: _t->on_actionCPairGEROcrVsCorrect_triggered(); break;
        case 33: _t->on_actionFilterOutGT50EditDisPairs_triggered(); break;
        case 34: _t->on_actionPrepareFeatures_triggered(); break;
        case 35: _t->on_actionErrorDetectionRepUniq_triggered(); break;
        case 36: _t->on_actionSanskrit_triggered(); break;
        case 37: _t->on_actionHindi_triggered(); break;
        case 38: _t->on_actionEnglish_triggered(); break;
        case 39: _t->on_actionBold_triggered(); break;
        case 40: _t->on_actionLeftAlign_triggered(); break;
        case 41: _t->on_actionRightAlign_triggered(); break;
        case 42: _t->on_actionCentreAlign_triggered(); break;
        case 43: _t->on_actionAllFontProperties_triggered(); break;
        case 44: _t->on_actionUnBold_triggered(); break;
        case 45: _t->on_actionJusitfiedAlign_triggered(); break;
        case 46: _t->on_actionHighlight_triggered(); break;
        case 47: _t->on_actionFontBlack_triggered(); break;
        case 48: _t->updateAverageAccuracies(); break;
        case 49: _t->on_actionViewAverageAccuracies_triggered(); break;
        case 50: _t->on_actionOpen_Project_triggered(); break;
        case 51: _t->file_click((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 52: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 53: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 54: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 55: _t->AddNewFile(); break;
        case 56: _t->OpenDirectory(); break;
        case 57: _t->RemoveFile(); break;
        case 58: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->on_actionTurn_In_triggered(); break;
        case 61: _t->on_actionPush_triggered(); break;
        case 62: _t->on_actionFetch_2_triggered(); break;
        case 63: _t->on_actionVerifier_Turn_In_triggered(); break;
        case 64: _t->directoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 65: _t->on_actionAccuracyLog_triggered(); break;
        case 66: _t->on_compareCorrectorOutput_clicked(); break;
        case 67: _t->on_viewComments_clicked(); break;
        case 68: _t->on_actionZoom_In_triggered(); break;
        case 69: _t->on_actionZoom_Out_triggered(); break;
        case 70: _t->on_actionSymbols_triggered(); break;
        case 71: _t->on_actionInsert_Tab_Space_triggered(); break;
        case 72: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 73: _t->on_actionSubscript_triggered(); break;
        case 74: _t->on_actionSuperscript_triggered(); break;
        case 75: _t->UpdateFileBrekadown(); break;
        case 76: _t->on_actionAdd_Image_triggered(); break;
        case 77: _t->SaveTimeLog(); break;
        case 78: _t->DisplayTimeLog(); break;
        case 79: _t->on_actionResize_Image_triggered(); break;
        case 80: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 81: _t->on_compareVerifierOutput_clicked(); break;
        case 82: _t->on_sanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 83: _t->on_hinButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 84: _t->on_actionLineSpace_triggered(); break;
        case 85: _t->on_actionUndo_triggered(); break;
        case 86: _t->on_actionRedo_triggered(); break;
        case 87: _t->on_actionNew_Project_triggered(); break;
        case 88: _t->on_actionInsert_Table_2_triggered(); break;
        case 89: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 90: { QJsonObject _r = _t->getAverageAccuracies((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 91: { bool _r = _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 92: _t->on_actionInsert_Columnleft_triggered(); break;
        case 93: _t->on_actionInsert_Columnright_triggered(); break;
        case 94: _t->on_actionInsert_Rowabove_triggered(); break;
        case 95: _t->on_actionInsert_Rowbelow_triggered(); break;
        case 96: _t->on_actionRemove_Column_triggered(); break;
        case 97: _t->on_actionRemove_Row_triggered(); break;
        case 98: _t->on_actionItalic_triggered(); break;
        case 99: _t->on_actionNonitalic_triggered(); break;
        case 100: _t->on_actionSave_All_triggered(); break;
        case 101: _t->on_actionFind_and_Replace_triggered(); break;
        case 102: { bool _r = _t->checkUnsavedWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 103: _t->saveAllWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 52:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 53:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 104)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 104;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 104)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 104;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
