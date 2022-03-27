/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[193];
    char stringdata0[4006];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "closeSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "createActions"
QT_MOC_LITERAL(4, 38, 9), // "WordCount"
QT_MOC_LITERAL(5, 48, 15), // "DisplayJsonDict"
QT_MOC_LITERAL(6, 64, 13), // "QTextBrowser*"
QT_MOC_LITERAL(7, 78, 1), // "b"
QT_MOC_LITERAL(8, 80, 5), // "input"
QT_MOC_LITERAL(9, 86, 11), // "eventFilter"
QT_MOC_LITERAL(10, 98, 7), // "QEvent*"
QT_MOC_LITERAL(11, 106, 15), // "saveImageRegion"
QT_MOC_LITERAL(12, 122, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(13, 145, 17), // "AddRecentProjects"
QT_MOC_LITERAL(14, 163, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(15, 187, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(16, 214, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(17, 245, 15), // "mousePressEvent"
QT_MOC_LITERAL(18, 261, 12), // "QMouseEvent*"
QT_MOC_LITERAL(19, 274, 2), // "ev"
QT_MOC_LITERAL(20, 277, 13), // "menuSelection"
QT_MOC_LITERAL(21, 291, 8), // "QAction*"
QT_MOC_LITERAL(22, 300, 6), // "action"
QT_MOC_LITERAL(23, 307, 17), // "translate_replace"
QT_MOC_LITERAL(24, 325, 15), // "clipboard_paste"
QT_MOC_LITERAL(25, 341, 13), // "keyPressEvent"
QT_MOC_LITERAL(26, 355, 10), // "QKeyEvent*"
QT_MOC_LITERAL(27, 366, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(28, 398, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(29, 430, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(30, 458, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(31, 486, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(32, 518, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(33, 548, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(34, 577, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(35, 611, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(36, 635, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(37, 661, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(38, 689, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(39, 714, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(40, 741, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(41, 770, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(42, 800, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(43, 831, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(44, 868, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(45, 894, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(46, 928, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(47, 957, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(48, 986, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(49, 1010, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(50, 1051, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(51, 1083, 10), // "file_click"
QT_MOC_LITERAL(52, 1094, 11), // "QModelIndex"
QT_MOC_LITERAL(53, 1106, 4), // "indx"
QT_MOC_LITERAL(54, 1111, 12), // "LoadDocument"
QT_MOC_LITERAL(55, 1124, 6), // "QFile*"
QT_MOC_LITERAL(56, 1131, 4), // "file"
QT_MOC_LITERAL(57, 1136, 3), // "ext"
QT_MOC_LITERAL(58, 1140, 4), // "name"
QT_MOC_LITERAL(59, 1145, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(60, 1163, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(61, 1190, 1), // "p"
QT_MOC_LITERAL(62, 1192, 10), // "AddNewFile"
QT_MOC_LITERAL(63, 1203, 13), // "OpenDirectory"
QT_MOC_LITERAL(64, 1217, 10), // "UpdateInfo"
QT_MOC_LITERAL(65, 1228, 14), // "compareVersion"
QT_MOC_LITERAL(66, 1243, 10), // "RemoveFile"
QT_MOC_LITERAL(67, 1254, 8), // "closetab"
QT_MOC_LITERAL(68, 1263, 5), // "index"
QT_MOC_LITERAL(69, 1269, 10), // "tabchanged"
QT_MOC_LITERAL(70, 1280, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(71, 1307, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(72, 1331, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(73, 1358, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(74, 1394, 16), // "directoryChanged"
QT_MOC_LITERAL(75, 1411, 4), // "path"
QT_MOC_LITERAL(76, 1416, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(77, 1447, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(78, 1481, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(79, 1505, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(80, 1532, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(81, 1560, 26), // "on_actionSymbols_triggered"
QT_MOC_LITERAL(82, 1587, 35), // "on_actionInsert_Tab_Space_tri..."
QT_MOC_LITERAL(83, 1623, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(84, 1665, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(85, 1694, 30), // "on_actionSuperscript_triggered"
QT_MOC_LITERAL(86, 1725, 19), // "UpdateFileBrekadown"
QT_MOC_LITERAL(87, 1745, 28), // "on_actionAdd_Image_triggered"
QT_MOC_LITERAL(88, 1774, 11), // "SaveTimeLog"
QT_MOC_LITERAL(89, 1786, 14), // "DisplayTimeLog"
QT_MOC_LITERAL(90, 1801, 31), // "on_actionResize_Image_triggered"
QT_MOC_LITERAL(91, 1833, 13), // "LogHighlights"
QT_MOC_LITERAL(92, 1847, 4), // "word"
QT_MOC_LITERAL(93, 1852, 32), // "on_compareVerifierOutput_clicked"
QT_MOC_LITERAL(94, 1885, 20), // "on_sanButton_toggled"
QT_MOC_LITERAL(95, 1906, 7), // "checked"
QT_MOC_LITERAL(96, 1914, 20), // "on_hinButton_toggled"
QT_MOC_LITERAL(97, 1935, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(98, 1964, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(99, 1988, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(100, 2012, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(101, 2043, 33), // "on_actionInsert_Table_2_trigg..."
QT_MOC_LITERAL(102, 2077, 10), // "closeEvent"
QT_MOC_LITERAL(103, 2088, 12), // "QCloseEvent*"
QT_MOC_LITERAL(104, 2101, 5), // "event"
QT_MOC_LITERAL(105, 2107, 20), // "getAverageAccuracies"
QT_MOC_LITERAL(106, 2128, 7), // "mainObj"
QT_MOC_LITERAL(107, 2136, 9), // "sendEmail"
QT_MOC_LITERAL(108, 2146, 7), // "message"
QT_MOC_LITERAL(109, 2154, 36), // "on_actionInsert_Columnleft_tr..."
QT_MOC_LITERAL(110, 2191, 37), // "on_actionInsert_Columnright_t..."
QT_MOC_LITERAL(111, 2229, 34), // "on_actionInsert_Rowabove_trig..."
QT_MOC_LITERAL(112, 2264, 34), // "on_actionInsert_Rowbelow_trig..."
QT_MOC_LITERAL(113, 2299, 32), // "on_actionRemove_Column_triggered"
QT_MOC_LITERAL(114, 2332, 29), // "on_actionRemove_Row_triggered"
QT_MOC_LITERAL(115, 2362, 25), // "on_actionItalic_triggered"
QT_MOC_LITERAL(116, 2388, 28), // "on_actionNonitalic_triggered"
QT_MOC_LITERAL(117, 2417, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(118, 2445, 35), // "on_actionFind_and_Replace_tri..."
QT_MOC_LITERAL(119, 2481, 16), // "checkUnsavedWork"
QT_MOC_LITERAL(120, 2498, 11), // "saveAllWork"
QT_MOC_LITERAL(121, 2510, 12), // "readSettings"
QT_MOC_LITERAL(122, 2523, 13), // "writeSettings"
QT_MOC_LITERAL(123, 2537, 12), // "setMFilename"
QT_MOC_LITERAL(124, 2550, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(125, 2572, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(126, 2596, 16), // "runGlobalReplace"
QT_MOC_LITERAL(127, 2613, 16), // "QVector<QString>"
QT_MOC_LITERAL(128, 2630, 28), // "globalReplaceQueryMessageBox"
QT_MOC_LITERAL(129, 2659, 8), // "old_word"
QT_MOC_LITERAL(130, 2668, 8), // "new_word"
QT_MOC_LITERAL(131, 2677, 4), // "int&"
QT_MOC_LITERAL(132, 2682, 3), // "chk"
QT_MOC_LITERAL(133, 2686, 24), // "writeGlobalCPairsToFiles"
QT_MOC_LITERAL(134, 2711, 9), // "file_path"
QT_MOC_LITERAL(135, 2721, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(136, 2743, 20), // "globalReplacementMap"
QT_MOC_LITERAL(137, 2764, 36), // "addCurrentlyOpenFileToEditedF..."
QT_MOC_LITERAL(138, 2801, 20), // "deleteEditedFilesLog"
QT_MOC_LITERAL(139, 2822, 14), // "RecentPageInfo"
QT_MOC_LITERAL(140, 2837, 14), // "isStringInFile"
QT_MOC_LITERAL(141, 2852, 12), // "searchString"
QT_MOC_LITERAL(142, 2865, 16), // "dumpStringToFile"
QT_MOC_LITERAL(143, 2882, 6), // "string"
QT_MOC_LITERAL(144, 2889, 9), // "highlight"
QT_MOC_LITERAL(145, 2899, 42), // "getGlobalReplacementMapFromCh..."
QT_MOC_LITERAL(146, 2942, 13), // "replacedWords"
QT_MOC_LITERAL(147, 2956, 13), // "QVector<int>*"
QT_MOC_LITERAL(148, 2970, 17), // "replaceInAllPages"
QT_MOC_LITERAL(149, 2988, 25), // "on_actionas_PDF_triggered"
QT_MOC_LITERAL(150, 3014, 27), // "on_actionGet_Help_triggered"
QT_MOC_LITERAL(151, 3042, 27), // "on_actionTutorial_triggered"
QT_MOC_LITERAL(152, 3070, 24), // "on_actionLinux_triggered"
QT_MOC_LITERAL(153, 3095, 26), // "on_actionWindows_triggered"
QT_MOC_LITERAL(154, 3122, 33), // "on_actionShortcut_Guide_trigg..."
QT_MOC_LITERAL(155, 3156, 26), // "on_textBrowser_textChanged"
QT_MOC_LITERAL(156, 3183, 26), // "on_zoom_Out_Button_clicked"
QT_MOC_LITERAL(157, 3210, 25), // "on_zoom_In_Button_clicked"
QT_MOC_LITERAL(158, 3236, 24), // "zoom_slider_valueChanged"
QT_MOC_LITERAL(159, 3261, 5), // "value"
QT_MOC_LITERAL(160, 3267, 17), // "zoom_slider_moved"
QT_MOC_LITERAL(161, 3285, 17), // "zoomedUsingScroll"
QT_MOC_LITERAL(162, 3303, 38), // "on_actionUndo_Global_Replace_..."
QT_MOC_LITERAL(163, 3342, 29), // "undoGlobalReplace_Single_Word"
QT_MOC_LITERAL(164, 3372, 7), // "oldWord"
QT_MOC_LITERAL(165, 3380, 7), // "newWord"
QT_MOC_LITERAL(166, 3388, 29), // "reverseGlobalReplacedWordsMap"
QT_MOC_LITERAL(167, 3418, 38), // "getUndoGlobalReplaceMap_Multi..."
QT_MOC_LITERAL(168, 3457, 28), // "replaceInAllFilesFromTSVfile"
QT_MOC_LITERAL(169, 3486, 20), // "checkForValidTSVfile"
QT_MOC_LITERAL(170, 3507, 6), // "QFile&"
QT_MOC_LITERAL(171, 3514, 22), // "globalReplacePreviewfn"
QT_MOC_LITERAL(172, 3537, 12), // "QVector<int>"
QT_MOC_LITERAL(173, 3550, 22), // "getBeforeAndAfterWords"
QT_MOC_LITERAL(174, 3573, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(175, 3599, 5), // "fPath"
QT_MOC_LITERAL(176, 3605, 25), // "on_actionUpload_triggered"
QT_MOC_LITERAL(177, 3631, 20), // "on_justify_triggered"
QT_MOC_LITERAL(178, 3652, 29), // "on_actionFont_Color_triggered"
QT_MOC_LITERAL(179, 3682, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(180, 3706, 26), // "SaveFile_GUI_Preprocessing"
QT_MOC_LITERAL(181, 3733, 27), // "SaveFile_GUI_Postprocessing"
QT_MOC_LITERAL(182, 3761, 13), // "GlobalReplace"
QT_MOC_LITERAL(183, 3775, 12), // "stopSpinning"
QT_MOC_LITERAL(184, 3788, 29), // "on_lineEditSearch_textChanged"
QT_MOC_LITERAL(185, 3818, 4), // "arg1"
QT_MOC_LITERAL(186, 3823, 20), // "on_action1_triggered"
QT_MOC_LITERAL(187, 3844, 20), // "on_action2_triggered"
QT_MOC_LITERAL(188, 3865, 20), // "on_action3_triggered"
QT_MOC_LITERAL(189, 3886, 34), // "on_actionSoftware_Update_trig..."
QT_MOC_LITERAL(190, 3921, 16), // "SaveFile_Backend"
QT_MOC_LITERAL(191, 3938, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(192, 3972, 33) // "on_actionLoad_Prev_Page_trigg..."

    },
    "MainWindow\0closeSignal\0\0createActions\0"
    "WordCount\0DisplayJsonDict\0QTextBrowser*\0"
    "b\0input\0eventFilter\0QEvent*\0saveImageRegion\0"
    "on_actionNew_triggered\0AddRecentProjects\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionSpell_Check_triggered\0"
    "mousePressEvent\0QMouseEvent*\0ev\0"
    "menuSelection\0QAction*\0action\0"
    "translate_replace\0clipboard_paste\0"
    "keyPressEvent\0QKeyEvent*\0"
    "on_actionLoadGDocPage_triggered\0"
    "on_actionToDevanagari_triggered\0"
    "on_actionLoadData_triggered\0"
    "on_actionLoadDict_triggered\0"
    "on_actionLoadOCRWords_triggered\0"
    "on_actionLoadDomain_triggered\0"
    "on_actionLoadSubPS_triggered\0"
    "on_actionLoadConfusions_triggered\0"
    "on_actionSugg_triggered\0"
    "on_actionToSlp1_triggered\0"
    "on_actionSanskrit_triggered\0"
    "on_actionHindi_triggered\0"
    "on_actionEnglish_triggered\0"
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
    "OpenDirectory\0UpdateInfo\0compareVersion\0"
    "RemoveFile\0closetab\0index\0tabchanged\0"
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
    "checkUnsavedWork\0saveAllWork\0readSettings\0"
    "writeSettings\0setMFilename\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "runGlobalReplace\0QVector<QString>\0"
    "globalReplaceQueryMessageBox\0old_word\0"
    "new_word\0int&\0chk\0writeGlobalCPairsToFiles\0"
    "file_path\0QMap<QString,QString>\0"
    "globalReplacementMap\0"
    "addCurrentlyOpenFileToEditedFilesLog\0"
    "deleteEditedFilesLog\0RecentPageInfo\0"
    "isStringInFile\0searchString\0"
    "dumpStringToFile\0string\0highlight\0"
    "getGlobalReplacementMapFromChecklistDialog\0"
    "replacedWords\0QVector<int>*\0"
    "replaceInAllPages\0on_actionas_PDF_triggered\0"
    "on_actionGet_Help_triggered\0"
    "on_actionTutorial_triggered\0"
    "on_actionLinux_triggered\0"
    "on_actionWindows_triggered\0"
    "on_actionShortcut_Guide_triggered\0"
    "on_textBrowser_textChanged\0"
    "on_zoom_Out_Button_clicked\0"
    "on_zoom_In_Button_clicked\0"
    "zoom_slider_valueChanged\0value\0"
    "zoom_slider_moved\0zoomedUsingScroll\0"
    "on_actionUndo_Global_Replace_triggered\0"
    "undoGlobalReplace_Single_Word\0oldWord\0"
    "newWord\0reverseGlobalReplacedWordsMap\0"
    "getUndoGlobalReplaceMap_Multiple_Words\0"
    "replaceInAllFilesFromTSVfile\0"
    "checkForValidTSVfile\0QFile&\0"
    "globalReplacePreviewfn\0QVector<int>\0"
    "getBeforeAndAfterWords\0QMap<QString,QStringList>\0"
    "fPath\0on_actionUpload_triggered\0"
    "on_justify_triggered\0on_actionFont_Color_triggered\0"
    "on_actionBold_triggered\0"
    "SaveFile_GUI_Preprocessing\0"
    "SaveFile_GUI_Postprocessing\0GlobalReplace\0"
    "stopSpinning\0on_lineEditSearch_textChanged\0"
    "arg1\0on_action1_triggered\0"
    "on_action2_triggered\0on_action3_triggered\0"
    "on_actionSoftware_Update_triggered\0"
    "SaveFile_Backend\0on_actionLoad_Next_Page_triggered\0"
    "on_actionLoad_Prev_Page_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     146,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  744,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  745,    2, 0x08 /* Private */,
       4,    0,  746,    2, 0x08 /* Private */,
       5,    2,  747,    2, 0x08 /* Private */,
       9,    2,  752,    2, 0x08 /* Private */,
      11,    6,  757,    2, 0x08 /* Private */,
      12,    0,  770,    2, 0x08 /* Private */,
      13,    0,  771,    2, 0x08 /* Private */,
      14,    0,  772,    2, 0x08 /* Private */,
      15,    0,  773,    2, 0x08 /* Private */,
      16,    0,  774,    2, 0x08 /* Private */,
      17,    1,  775,    2, 0x08 /* Private */,
      20,    1,  778,    2, 0x08 /* Private */,
      23,    1,  781,    2, 0x08 /* Private */,
      24,    1,  784,    2, 0x08 /* Private */,
      25,    1,  787,    2, 0x08 /* Private */,
      27,    0,  790,    2, 0x08 /* Private */,
      28,    0,  791,    2, 0x08 /* Private */,
      29,    0,  792,    2, 0x08 /* Private */,
      30,    0,  793,    2, 0x08 /* Private */,
      31,    0,  794,    2, 0x08 /* Private */,
      32,    0,  795,    2, 0x08 /* Private */,
      33,    0,  796,    2, 0x08 /* Private */,
      34,    0,  797,    2, 0x08 /* Private */,
      35,    0,  798,    2, 0x08 /* Private */,
      36,    0,  799,    2, 0x08 /* Private */,
      37,    0,  800,    2, 0x08 /* Private */,
      38,    0,  801,    2, 0x08 /* Private */,
      39,    0,  802,    2, 0x08 /* Private */,
      40,    0,  803,    2, 0x08 /* Private */,
      41,    0,  804,    2, 0x08 /* Private */,
      42,    0,  805,    2, 0x08 /* Private */,
      43,    0,  806,    2, 0x08 /* Private */,
      44,    0,  807,    2, 0x08 /* Private */,
      45,    0,  808,    2, 0x08 /* Private */,
      46,    0,  809,    2, 0x08 /* Private */,
      47,    0,  810,    2, 0x08 /* Private */,
      48,    0,  811,    2, 0x08 /* Private */,
      49,    0,  812,    2, 0x08 /* Private */,
      50,    0,  813,    2, 0x08 /* Private */,
      51,    1,  814,    2, 0x08 /* Private */,
      54,    3,  817,    2, 0x08 /* Private */,
      59,    1,  824,    2, 0x08 /* Private */,
      60,    1,  827,    2, 0x08 /* Private */,
      62,    0,  830,    2, 0x08 /* Private */,
      63,    0,  831,    2, 0x08 /* Private */,
      64,    0,  832,    2, 0x08 /* Private */,
      65,    0,  833,    2, 0x08 /* Private */,
      66,    0,  834,    2, 0x08 /* Private */,
      67,    1,  835,    2, 0x08 /* Private */,
      69,    1,  838,    2, 0x08 /* Private */,
      70,    0,  841,    2, 0x08 /* Private */,
      71,    0,  842,    2, 0x08 /* Private */,
      72,    0,  843,    2, 0x08 /* Private */,
      73,    0,  844,    2, 0x08 /* Private */,
      74,    1,  845,    2, 0x08 /* Private */,
      76,    0,  848,    2, 0x08 /* Private */,
      77,    0,  849,    2, 0x08 /* Private */,
      78,    0,  850,    2, 0x08 /* Private */,
      79,    0,  851,    2, 0x08 /* Private */,
      80,    0,  852,    2, 0x08 /* Private */,
      81,    0,  853,    2, 0x08 /* Private */,
      82,    0,  854,    2, 0x08 /* Private */,
      83,    0,  855,    2, 0x08 /* Private */,
      84,    0,  856,    2, 0x08 /* Private */,
      85,    0,  857,    2, 0x08 /* Private */,
      86,    0,  858,    2, 0x08 /* Private */,
      87,    0,  859,    2, 0x08 /* Private */,
      88,    0,  860,    2, 0x08 /* Private */,
      89,    0,  861,    2, 0x08 /* Private */,
      90,    0,  862,    2, 0x08 /* Private */,
      91,    1,  863,    2, 0x08 /* Private */,
      93,    0,  866,    2, 0x08 /* Private */,
      94,    1,  867,    2, 0x08 /* Private */,
      96,    1,  870,    2, 0x08 /* Private */,
      97,    0,  873,    2, 0x08 /* Private */,
      98,    0,  874,    2, 0x08 /* Private */,
      99,    0,  875,    2, 0x08 /* Private */,
     100,    0,  876,    2, 0x08 /* Private */,
     101,    0,  877,    2, 0x08 /* Private */,
     102,    1,  878,    2, 0x08 /* Private */,
     105,    1,  881,    2, 0x08 /* Private */,
     107,    1,  884,    2, 0x08 /* Private */,
     109,    0,  887,    2, 0x08 /* Private */,
     110,    0,  888,    2, 0x08 /* Private */,
     111,    0,  889,    2, 0x08 /* Private */,
     112,    0,  890,    2, 0x08 /* Private */,
     113,    0,  891,    2, 0x08 /* Private */,
     114,    0,  892,    2, 0x08 /* Private */,
     115,    0,  893,    2, 0x08 /* Private */,
     116,    0,  894,    2, 0x08 /* Private */,
     117,    0,  895,    2, 0x08 /* Private */,
     118,    0,  896,    2, 0x08 /* Private */,
     119,    0,  897,    2, 0x08 /* Private */,
     120,    0,  898,    2, 0x08 /* Private */,
     121,    0,  899,    2, 0x08 /* Private */,
     122,    0,  900,    2, 0x08 /* Private */,
     123,    1,  901,    2, 0x08 /* Private */,
     124,    0,  904,    2, 0x08 /* Private */,
     125,    0,  905,    2, 0x08 /* Private */,
     126,    2,  906,    2, 0x08 /* Private */,
     128,    3,  911,    2, 0x08 /* Private */,
     133,    2,  918,    2, 0x08 /* Private */,
     137,    0,  923,    2, 0x08 /* Private */,
     138,    0,  924,    2, 0x08 /* Private */,
     139,    0,  925,    2, 0x08 /* Private */,
     140,    2,  926,    2, 0x08 /* Private */,
     142,    2,  931,    2, 0x08 /* Private */,
     144,    2,  936,    2, 0x08 /* Private */,
     145,    2,  941,    2, 0x08 /* Private */,
     149,    0,  946,    2, 0x08 /* Private */,
     150,    0,  947,    2, 0x08 /* Private */,
     151,    0,  948,    2, 0x08 /* Private */,
     152,    0,  949,    2, 0x08 /* Private */,
     153,    0,  950,    2, 0x08 /* Private */,
     154,    0,  951,    2, 0x08 /* Private */,
     155,    0,  952,    2, 0x08 /* Private */,
     156,    0,  953,    2, 0x08 /* Private */,
     157,    0,  954,    2, 0x08 /* Private */,
     158,    1,  955,    2, 0x08 /* Private */,
     160,    1,  958,    2, 0x08 /* Private */,
     161,    0,  961,    2, 0x08 /* Private */,
     162,    0,  962,    2, 0x08 /* Private */,
     163,    2,  963,    2, 0x08 /* Private */,
     166,    0,  968,    2, 0x08 /* Private */,
     167,    1,  969,    2, 0x08 /* Private */,
     168,    0,  972,    2, 0x08 /* Private */,
     169,    1,  973,    2, 0x08 /* Private */,
     171,    2,  976,    2, 0x08 /* Private */,
     173,    2,  981,    2, 0x08 /* Private */,
     176,    0,  986,    2, 0x08 /* Private */,
     177,    0,  987,    2, 0x08 /* Private */,
     178,    0,  988,    2, 0x08 /* Private */,
     179,    0,  989,    2, 0x08 /* Private */,
     180,    0,  990,    2, 0x08 /* Private */,
     181,    0,  991,    2, 0x08 /* Private */,
     182,    0,  992,    2, 0x08 /* Private */,
     183,    0,  993,    2, 0x08 /* Private */,
     184,    1,  994,    2, 0x08 /* Private */,
     186,    0,  997,    2, 0x08 /* Private */,
     187,    0,  998,    2, 0x08 /* Private */,
     188,    0,  999,    2, 0x08 /* Private */,
     189,    0, 1000,    2, 0x08 /* Private */,
     190,    0, 1001,    2, 0x0a /* Public */,
     191,    0, 1002,    2, 0x0a /* Public */,
     192,    0, 1003,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 10,    2,    2,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 26,    2,
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
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, 0x80000000 | 55, QMetaType::QString, QMetaType::QString,   56,   57,   58,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, QMetaType::QPoint,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   75,
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
    QMetaType::Void, QMetaType::QString,   92,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   95,
    QMetaType::Void, QMetaType::Bool,   95,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 103,  104,
    QMetaType::QJsonObject, QMetaType::QJsonObject,  106,
    QMetaType::Bool, QMetaType::QString,  108,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 127,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 131,  129,  130,  132,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 135,  134,  136,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  134,  141,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  134,  143,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    0x80000000 | 135, 0x80000000 | 127, 0x80000000 | 147,  146,  148,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  159,
    QMetaType::Void, QMetaType::Int,  159,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  164,  165,
    QMetaType::Void,
    0x80000000 | 135, 0x80000000 | 135,    2,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 170,   56,
    QMetaType::Void, 0x80000000 | 135, 0x80000000 | 172,    2,    2,
    0x80000000 | 174, QMetaType::QString, 0x80000000 | 135,  175,  136,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  185,
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
        case 0: _t->closeSignal(); break;
        case 1: _t->createActions(); break;
        case 2: _t->WordCount(); break;
        case 3: _t->DisplayJsonDict((*reinterpret_cast< QTextBrowser*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->saveImageRegion((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 6: _t->on_actionNew_triggered(); break;
        case 7: _t->AddRecentProjects(); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionSave_As_triggered(); break;
        case 10: _t->on_actionSpell_Check_triggered(); break;
        case 11: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 12: _t->menuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 13: _t->translate_replace((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 14: _t->clipboard_paste((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 15: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 16: _t->on_actionLoadGDocPage_triggered(); break;
        case 17: _t->on_actionToDevanagari_triggered(); break;
        case 18: _t->on_actionLoadData_triggered(); break;
        case 19: _t->on_actionLoadDict_triggered(); break;
        case 20: _t->on_actionLoadOCRWords_triggered(); break;
        case 21: _t->on_actionLoadDomain_triggered(); break;
        case 22: _t->on_actionLoadSubPS_triggered(); break;
        case 23: _t->on_actionLoadConfusions_triggered(); break;
        case 24: _t->on_actionSugg_triggered(); break;
        case 25: _t->on_actionToSlp1_triggered(); break;
        case 26: _t->on_actionSanskrit_triggered(); break;
        case 27: _t->on_actionHindi_triggered(); break;
        case 28: _t->on_actionEnglish_triggered(); break;
        case 29: _t->on_actionLeftAlign_triggered(); break;
        case 30: _t->on_actionRightAlign_triggered(); break;
        case 31: _t->on_actionCentreAlign_triggered(); break;
        case 32: _t->on_actionAllFontProperties_triggered(); break;
        case 33: _t->on_actionUnBold_triggered(); break;
        case 34: _t->on_actionJusitfiedAlign_triggered(); break;
        case 35: _t->on_actionHighlight_triggered(); break;
        case 36: _t->on_actionFontBlack_triggered(); break;
        case 37: _t->updateAverageAccuracies(); break;
        case 38: _t->on_actionViewAverageAccuracies_triggered(); break;
        case 39: _t->on_actionOpen_Project_triggered(); break;
        case 40: _t->file_click((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 41: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 42: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 43: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 44: _t->AddNewFile(); break;
        case 45: _t->OpenDirectory(); break;
        case 46: { QString _r = _t->UpdateInfo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->compareVersion(); break;
        case 48: _t->RemoveFile(); break;
        case 49: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->on_actionTurn_In_triggered(); break;
        case 52: _t->on_actionPush_triggered(); break;
        case 53: _t->on_actionFetch_2_triggered(); break;
        case 54: _t->on_actionVerifier_Turn_In_triggered(); break;
        case 55: _t->directoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 56: _t->on_actionAccuracyLog_triggered(); break;
        case 57: _t->on_compareCorrectorOutput_clicked(); break;
        case 58: _t->on_viewComments_clicked(); break;
        case 59: _t->on_actionZoom_In_triggered(); break;
        case 60: _t->on_actionZoom_Out_triggered(); break;
        case 61: _t->on_actionSymbols_triggered(); break;
        case 62: _t->on_actionInsert_Tab_Space_triggered(); break;
        case 63: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 64: _t->on_actionSubscript_triggered(); break;
        case 65: _t->on_actionSuperscript_triggered(); break;
        case 66: _t->UpdateFileBrekadown(); break;
        case 67: _t->on_actionAdd_Image_triggered(); break;
        case 68: _t->SaveTimeLog(); break;
        case 69: _t->DisplayTimeLog(); break;
        case 70: _t->on_actionResize_Image_triggered(); break;
        case 71: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 72: _t->on_compareVerifierOutput_clicked(); break;
        case 73: _t->on_sanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 74: _t->on_hinButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 75: _t->on_actionLineSpace_triggered(); break;
        case 76: _t->on_actionUndo_triggered(); break;
        case 77: _t->on_actionRedo_triggered(); break;
        case 78: _t->on_actionNew_Project_triggered(); break;
        case 79: _t->on_actionInsert_Table_2_triggered(); break;
        case 80: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 81: { QJsonObject _r = _t->getAverageAccuracies((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 82: { bool _r = _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 83: _t->on_actionInsert_Columnleft_triggered(); break;
        case 84: _t->on_actionInsert_Columnright_triggered(); break;
        case 85: _t->on_actionInsert_Rowabove_triggered(); break;
        case 86: _t->on_actionInsert_Rowbelow_triggered(); break;
        case 87: _t->on_actionRemove_Column_triggered(); break;
        case 88: _t->on_actionRemove_Row_triggered(); break;
        case 89: _t->on_actionItalic_triggered(); break;
        case 90: _t->on_actionNonitalic_triggered(); break;
        case 91: _t->on_actionSave_All_triggered(); break;
        case 92: _t->on_actionFind_and_Replace_triggered(); break;
        case 93: { bool _r = _t->checkUnsavedWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 94: _t->saveAllWork(); break;
        case 95: _t->readSettings(); break;
        case 96: _t->writeSettings(); break;
        case 97: _t->setMFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 98: _t->on_pushButton_clicked(); break;
        case 99: _t->on_pushButton_2_clicked(); break;
        case 100: _t->runGlobalReplace((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 101: { bool _r = _t->globalReplaceQueryMessageBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 102: { int _r = _t->writeGlobalCPairsToFiles((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 103: _t->addCurrentlyOpenFileToEditedFilesLog(); break;
        case 104: _t->deleteEditedFilesLog(); break;
        case 105: _t->RecentPageInfo(); break;
        case 106: { bool _r = _t->isStringInFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 107: _t->dumpStringToFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 108: _t->highlight((*reinterpret_cast< QTextBrowser*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 109: { QMap<QString,QString> _r = _t->getGlobalReplacementMapFromChecklistDialog((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<int>*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 110: _t->on_actionas_PDF_triggered(); break;
        case 111: _t->on_actionGet_Help_triggered(); break;
        case 112: _t->on_actionTutorial_triggered(); break;
        case 113: _t->on_actionLinux_triggered(); break;
        case 114: _t->on_actionWindows_triggered(); break;
        case 115: _t->on_actionShortcut_Guide_triggered(); break;
        case 116: _t->on_textBrowser_textChanged(); break;
        case 117: _t->on_zoom_Out_Button_clicked(); break;
        case 118: _t->on_zoom_In_Button_clicked(); break;
        case 119: _t->zoom_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 120: _t->zoom_slider_moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 121: _t->zoomedUsingScroll(); break;
        case 122: _t->on_actionUndo_Global_Replace_triggered(); break;
        case 123: { bool _r = _t->undoGlobalReplace_Single_Word((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 124: _t->reverseGlobalReplacedWordsMap(); break;
        case 125: { QMap<QString,QString> _r = _t->getUndoGlobalReplaceMap_Multiple_Words((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 126: _t->replaceInAllFilesFromTSVfile(); break;
        case 127: { bool _r = _t->checkForValidTSVfile((*reinterpret_cast< QFile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 128: _t->globalReplacePreviewfn((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        case 129: { QMap<QString,QStringList> _r = _t->getBeforeAndAfterWords((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 130: _t->on_actionUpload_triggered(); break;
        case 131: _t->on_justify_triggered(); break;
        case 132: _t->on_actionFont_Color_triggered(); break;
        case 133: _t->on_actionBold_triggered(); break;
        case 134: _t->SaveFile_GUI_Preprocessing(); break;
        case 135: _t->SaveFile_GUI_Postprocessing(); break;
        case 136: _t->GlobalReplace(); break;
        case 137: _t->stopSpinning(); break;
        case 138: _t->on_lineEditSearch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 139: _t->on_action1_triggered(); break;
        case 140: _t->on_action2_triggered(); break;
        case 141: _t->on_action3_triggered(); break;
        case 142: _t->on_actionSoftware_Update_triggered(); break;
        case 143: _t->SaveFile_Backend(); break;
        case 144: _t->on_actionLoad_Next_Page_triggered(); break;
        case 145: _t->on_actionLoad_Prev_Page_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextBrowser* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 100:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 108:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextBrowser* >(); break;
            }
            break;
        case 109:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 128:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeSignal)) {
                *result = 0;
                return;
            }
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
        if (_id < 146)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 146;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 146)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 146;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
