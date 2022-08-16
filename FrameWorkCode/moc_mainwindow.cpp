/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
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
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[216];
    char stringdata0[4345];
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
QT_MOC_LITERAL(6, 64, 15), // "newTextBrowser*"
QT_MOC_LITERAL(7, 80, 1), // "b"
QT_MOC_LITERAL(8, 82, 5), // "input"
QT_MOC_LITERAL(9, 88, 11), // "eventFilter"
QT_MOC_LITERAL(10, 100, 7), // "QEvent*"
QT_MOC_LITERAL(11, 108, 15), // "saveImageRegion"
QT_MOC_LITERAL(12, 124, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(13, 147, 17), // "AddRecentProjects"
QT_MOC_LITERAL(14, 165, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(15, 189, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(16, 216, 30), // "on_actionSpell_Check_triggered"
QT_MOC_LITERAL(17, 247, 15), // "mousePressEvent"
QT_MOC_LITERAL(18, 263, 12), // "QMouseEvent*"
QT_MOC_LITERAL(19, 276, 2), // "ev"
QT_MOC_LITERAL(20, 279, 13), // "menuSelection"
QT_MOC_LITERAL(21, 293, 8), // "QAction*"
QT_MOC_LITERAL(22, 302, 6), // "action"
QT_MOC_LITERAL(23, 309, 17), // "translate_replace"
QT_MOC_LITERAL(24, 327, 15), // "clipboard_paste"
QT_MOC_LITERAL(25, 343, 13), // "keyPressEvent"
QT_MOC_LITERAL(26, 357, 10), // "QKeyEvent*"
QT_MOC_LITERAL(27, 368, 31), // "on_actionLoadGDocPage_triggered"
QT_MOC_LITERAL(28, 400, 31), // "on_actionToDevanagari_triggered"
QT_MOC_LITERAL(29, 432, 27), // "on_actionLoadData_triggered"
QT_MOC_LITERAL(30, 460, 27), // "on_actionLoadDict_triggered"
QT_MOC_LITERAL(31, 488, 31), // "on_actionLoadOCRWords_triggered"
QT_MOC_LITERAL(32, 520, 29), // "on_actionLoadDomain_triggered"
QT_MOC_LITERAL(33, 550, 28), // "on_actionLoadSubPS_triggered"
QT_MOC_LITERAL(34, 579, 33), // "on_actionLoadConfusions_trigg..."
QT_MOC_LITERAL(35, 613, 23), // "on_actionSugg_triggered"
QT_MOC_LITERAL(36, 637, 25), // "on_actionToSlp1_triggered"
QT_MOC_LITERAL(37, 663, 27), // "on_actionSanskrit_triggered"
QT_MOC_LITERAL(38, 691, 24), // "on_actionHindi_triggered"
QT_MOC_LITERAL(39, 716, 26), // "on_actionEnglish_triggered"
QT_MOC_LITERAL(40, 743, 28), // "on_actionLeftAlign_triggered"
QT_MOC_LITERAL(41, 772, 29), // "on_actionRightAlign_triggered"
QT_MOC_LITERAL(42, 802, 30), // "on_actionCentreAlign_triggered"
QT_MOC_LITERAL(43, 833, 36), // "on_actionAllFontProperties_tr..."
QT_MOC_LITERAL(44, 870, 25), // "on_actionUnBold_triggered"
QT_MOC_LITERAL(45, 896, 33), // "on_actionJusitfiedAlign_trigg..."
QT_MOC_LITERAL(46, 930, 28), // "on_actionHighlight_triggered"
QT_MOC_LITERAL(47, 959, 28), // "on_actionFontBlack_triggered"
QT_MOC_LITERAL(48, 988, 23), // "updateAverageAccuracies"
QT_MOC_LITERAL(49, 1012, 40), // "on_actionViewAverageAccuracie..."
QT_MOC_LITERAL(50, 1053, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(51, 1085, 10), // "file_click"
QT_MOC_LITERAL(52, 1096, 11), // "QModelIndex"
QT_MOC_LITERAL(53, 1108, 4), // "indx"
QT_MOC_LITERAL(54, 1113, 17), // "LoadImageFromFile"
QT_MOC_LITERAL(55, 1131, 6), // "QFile*"
QT_MOC_LITERAL(56, 1138, 4), // "file"
QT_MOC_LITERAL(57, 1143, 26), // "CustomContextMenuTriggered"
QT_MOC_LITERAL(58, 1170, 1), // "p"
QT_MOC_LITERAL(59, 1172, 10), // "AddNewFile"
QT_MOC_LITERAL(60, 1183, 13), // "OpenDirectory"
QT_MOC_LITERAL(61, 1197, 10), // "RemoveFile"
QT_MOC_LITERAL(62, 1208, 8), // "closetab"
QT_MOC_LITERAL(63, 1217, 5), // "index"
QT_MOC_LITERAL(64, 1223, 10), // "tabchanged"
QT_MOC_LITERAL(65, 1234, 26), // "on_actionTurn_In_triggered"
QT_MOC_LITERAL(66, 1261, 23), // "on_actionPush_triggered"
QT_MOC_LITERAL(67, 1285, 26), // "on_actionFetch_2_triggered"
QT_MOC_LITERAL(68, 1312, 35), // "on_actionVerifier_Turn_In_tri..."
QT_MOC_LITERAL(69, 1348, 16), // "directoryChanged"
QT_MOC_LITERAL(70, 1365, 4), // "path"
QT_MOC_LITERAL(71, 1370, 30), // "on_actionAccuracyLog_triggered"
QT_MOC_LITERAL(72, 1401, 33), // "on_compareCorrectorOutput_cli..."
QT_MOC_LITERAL(73, 1435, 23), // "on_viewComments_clicked"
QT_MOC_LITERAL(74, 1459, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(75, 1486, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(76, 1514, 26), // "on_actionSymbols_triggered"
QT_MOC_LITERAL(77, 1541, 35), // "on_actionInsert_Tab_Space_tri..."
QT_MOC_LITERAL(78, 1577, 41), // "on_actionInsert_Horizontal_Li..."
QT_MOC_LITERAL(79, 1619, 28), // "on_actionSubscript_triggered"
QT_MOC_LITERAL(80, 1648, 30), // "on_actionSuperscript_triggered"
QT_MOC_LITERAL(81, 1679, 19), // "UpdateFileBrekadown"
QT_MOC_LITERAL(82, 1699, 28), // "on_actionAdd_Image_triggered"
QT_MOC_LITERAL(83, 1728, 11), // "SaveTimeLog"
QT_MOC_LITERAL(84, 1740, 14), // "DisplayTimeLog"
QT_MOC_LITERAL(85, 1755, 31), // "on_actionResize_Image_triggered"
QT_MOC_LITERAL(86, 1787, 13), // "LogHighlights"
QT_MOC_LITERAL(87, 1801, 4), // "word"
QT_MOC_LITERAL(88, 1806, 32), // "on_compareVerifierOutput_clicked"
QT_MOC_LITERAL(89, 1839, 20), // "on_sanButton_toggled"
QT_MOC_LITERAL(90, 1860, 7), // "checked"
QT_MOC_LITERAL(91, 1868, 20), // "on_hinButton_toggled"
QT_MOC_LITERAL(92, 1889, 28), // "on_actionLineSpace_triggered"
QT_MOC_LITERAL(93, 1918, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(94, 1942, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(95, 1966, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(96, 1997, 33), // "on_actionInsert_Table_2_trigg..."
QT_MOC_LITERAL(97, 2031, 10), // "closeEvent"
QT_MOC_LITERAL(98, 2042, 12), // "QCloseEvent*"
QT_MOC_LITERAL(99, 2055, 5), // "event"
QT_MOC_LITERAL(100, 2061, 20), // "getAverageAccuracies"
QT_MOC_LITERAL(101, 2082, 7), // "mainObj"
QT_MOC_LITERAL(102, 2090, 9), // "sendEmail"
QT_MOC_LITERAL(103, 2100, 7), // "message"
QT_MOC_LITERAL(104, 2108, 36), // "on_actionInsert_Columnleft_tr..."
QT_MOC_LITERAL(105, 2145, 37), // "on_actionInsert_Columnright_t..."
QT_MOC_LITERAL(106, 2183, 34), // "on_actionInsert_Rowabove_trig..."
QT_MOC_LITERAL(107, 2218, 34), // "on_actionInsert_Rowbelow_trig..."
QT_MOC_LITERAL(108, 2253, 32), // "on_actionRemove_Column_triggered"
QT_MOC_LITERAL(109, 2286, 29), // "on_actionRemove_Row_triggered"
QT_MOC_LITERAL(110, 2316, 25), // "on_actionItalic_triggered"
QT_MOC_LITERAL(111, 2342, 28), // "on_actionNonitalic_triggered"
QT_MOC_LITERAL(112, 2371, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(113, 2399, 35), // "on_actionFind_and_Replace_tri..."
QT_MOC_LITERAL(114, 2435, 16), // "checkUnsavedWork"
QT_MOC_LITERAL(115, 2452, 11), // "saveAllWork"
QT_MOC_LITERAL(116, 2464, 12), // "readSettings"
QT_MOC_LITERAL(117, 2477, 13), // "writeSettings"
QT_MOC_LITERAL(118, 2491, 12), // "setMFilename"
QT_MOC_LITERAL(119, 2504, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(120, 2526, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(121, 2550, 16), // "runGlobalReplace"
QT_MOC_LITERAL(122, 2567, 16), // "QVector<QString>"
QT_MOC_LITERAL(123, 2584, 28), // "globalReplaceQueryMessageBox"
QT_MOC_LITERAL(124, 2613, 8), // "old_word"
QT_MOC_LITERAL(125, 2622, 8), // "new_word"
QT_MOC_LITERAL(126, 2631, 4), // "int&"
QT_MOC_LITERAL(127, 2636, 3), // "chk"
QT_MOC_LITERAL(128, 2640, 24), // "writeGlobalCPairsToFiles"
QT_MOC_LITERAL(129, 2665, 9), // "file_path"
QT_MOC_LITERAL(130, 2675, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(131, 2697, 20), // "globalReplacementMap"
QT_MOC_LITERAL(132, 2718, 36), // "addCurrentlyOpenFileToEditedF..."
QT_MOC_LITERAL(133, 2755, 20), // "deleteEditedFilesLog"
QT_MOC_LITERAL(134, 2776, 14), // "RecentPageInfo"
QT_MOC_LITERAL(135, 2791, 14), // "isStringInFile"
QT_MOC_LITERAL(136, 2806, 12), // "searchString"
QT_MOC_LITERAL(137, 2819, 16), // "dumpStringToFile"
QT_MOC_LITERAL(138, 2836, 6), // "string"
QT_MOC_LITERAL(139, 2843, 9), // "highlight"
QT_MOC_LITERAL(140, 2853, 42), // "getGlobalReplacementMapFromCh..."
QT_MOC_LITERAL(141, 2896, 13), // "replacedWords"
QT_MOC_LITERAL(142, 2910, 13), // "QVector<int>*"
QT_MOC_LITERAL(143, 2924, 17), // "replaceInAllPages"
QT_MOC_LITERAL(144, 2942, 25), // "on_actionas_PDF_triggered"
QT_MOC_LITERAL(145, 2968, 27), // "on_actionGet_Help_triggered"
QT_MOC_LITERAL(146, 2996, 27), // "on_actionTutorial_triggered"
QT_MOC_LITERAL(147, 3024, 24), // "on_actionLinux_triggered"
QT_MOC_LITERAL(148, 3049, 26), // "on_actionWindows_triggered"
QT_MOC_LITERAL(149, 3076, 33), // "on_actionShortcut_Guide_trigg..."
QT_MOC_LITERAL(150, 3110, 26), // "on_textBrowser_textChanged"
QT_MOC_LITERAL(151, 3137, 26), // "on_zoom_Out_Button_clicked"
QT_MOC_LITERAL(152, 3164, 25), // "on_zoom_In_Button_clicked"
QT_MOC_LITERAL(153, 3190, 24), // "zoom_slider_valueChanged"
QT_MOC_LITERAL(154, 3215, 5), // "value"
QT_MOC_LITERAL(155, 3221, 17), // "zoom_slider_moved"
QT_MOC_LITERAL(156, 3239, 17), // "zoomedUsingScroll"
QT_MOC_LITERAL(157, 3257, 38), // "on_actionUndo_Global_Replace_..."
QT_MOC_LITERAL(158, 3296, 29), // "undoGlobalReplace_Single_Word"
QT_MOC_LITERAL(159, 3326, 7), // "oldWord"
QT_MOC_LITERAL(160, 3334, 7), // "newWord"
QT_MOC_LITERAL(161, 3342, 29), // "reverseGlobalReplacedWordsMap"
QT_MOC_LITERAL(162, 3372, 38), // "getUndoGlobalReplaceMap_Multi..."
QT_MOC_LITERAL(163, 3411, 28), // "replaceInAllFilesFromTSVfile"
QT_MOC_LITERAL(164, 3440, 20), // "checkForValidTSVfile"
QT_MOC_LITERAL(165, 3461, 6), // "QFile&"
QT_MOC_LITERAL(166, 3468, 22), // "globalReplacePreviewfn"
QT_MOC_LITERAL(167, 3491, 12), // "QVector<int>"
QT_MOC_LITERAL(168, 3504, 22), // "getBeforeAndAfterWords"
QT_MOC_LITERAL(169, 3527, 25), // "QMap<QString,QStringList>"
QT_MOC_LITERAL(170, 3553, 5), // "fPath"
QT_MOC_LITERAL(171, 3559, 25), // "on_actionUpload_triggered"
QT_MOC_LITERAL(172, 3585, 20), // "on_justify_triggered"
QT_MOC_LITERAL(173, 3606, 29), // "on_actionFont_Color_triggered"
QT_MOC_LITERAL(174, 3636, 23), // "on_actionBold_triggered"
QT_MOC_LITERAL(175, 3660, 26), // "SaveFile_GUI_Preprocessing"
QT_MOC_LITERAL(176, 3687, 27), // "SaveFile_GUI_Postprocessing"
QT_MOC_LITERAL(177, 3715, 13), // "GlobalReplace"
QT_MOC_LITERAL(178, 3729, 12), // "stopSpinning"
QT_MOC_LITERAL(179, 3742, 29), // "on_lineEditSearch_textChanged"
QT_MOC_LITERAL(180, 3772, 4), // "arg1"
QT_MOC_LITERAL(181, 3777, 20), // "on_action1_triggered"
QT_MOC_LITERAL(182, 3798, 20), // "on_action2_triggered"
QT_MOC_LITERAL(183, 3819, 20), // "on_action3_triggered"
QT_MOC_LITERAL(184, 3840, 36), // "on_actionCheck_for_Updates_tr..."
QT_MOC_LITERAL(185, 3877, 16), // "closeProgressBar"
QT_MOC_LITERAL(186, 3894, 18), // "setProgressBarPerc"
QT_MOC_LITERAL(187, 3913, 12), // "toDevanagari"
QT_MOC_LITERAL(188, 3926, 4), // "text"
QT_MOC_LITERAL(189, 3931, 15), // "on_find_clicked"
QT_MOC_LITERAL(190, 3947, 30), // "on_actionPDF_Preview_triggered"
QT_MOC_LITERAL(191, 3978, 5), // "print"
QT_MOC_LITERAL(192, 3984, 9), // "QPrinter*"
QT_MOC_LITERAL(193, 3994, 7), // "printer"
QT_MOC_LITERAL(194, 4002, 30), // "on_actionChange_Role_triggered"
QT_MOC_LITERAL(195, 4033, 13), // "bboxInsertion"
QT_MOC_LITERAL(196, 4047, 1), // "f"
QT_MOC_LITERAL(197, 4049, 19), // "finishedPdfCreation"
QT_MOC_LITERAL(198, 4069, 8), // "exitCode"
QT_MOC_LITERAL(199, 4078, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(200, 4099, 10), // "exitStatus"
QT_MOC_LITERAL(201, 4110, 14), // "SearchOnGoogle"
QT_MOC_LITERAL(202, 4125, 17), // "GoogleTranslation"
QT_MOC_LITERAL(203, 4143, 16), // "SaveFile_Backend"
QT_MOC_LITERAL(204, 4160, 33), // "on_actionLoad_Next_Page_trigg..."
QT_MOC_LITERAL(205, 4194, 33), // "on_actionLoad_Prev_Page_trigg..."
QT_MOC_LITERAL(206, 4228, 12), // "LoadDocument"
QT_MOC_LITERAL(207, 4241, 3), // "ext"
QT_MOC_LITERAL(208, 4245, 4), // "name"
QT_MOC_LITERAL(209, 4250, 15), // "pdfPrintIsReady"
QT_MOC_LITERAL(210, 4266, 22), // "readOutputFromPdfPrint"
QT_MOC_LITERAL(211, 4289, 16), // "insertCompletion"
QT_MOC_LITERAL(212, 4306, 10), // "completion"
QT_MOC_LITERAL(213, 4317, 12), // "focusInEvent"
QT_MOC_LITERAL(214, 4330, 12), // "QFocusEvent*"
QT_MOC_LITERAL(215, 4343, 1) // "e"

    },
    "MainWindow\0closeSignal\0\0createActions\0"
    "WordCount\0DisplayJsonDict\0newTextBrowser*\0"
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
    "file_click\0QModelIndex\0indx\0"
    "LoadImageFromFile\0QFile*\0file\0"
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
    "on_actionCheck_for_Updates_triggered\0"
    "closeProgressBar\0setProgressBarPerc\0"
    "toDevanagari\0text\0on_find_clicked\0"
    "on_actionPDF_Preview_triggered\0print\0"
    "QPrinter*\0printer\0on_actionChange_Role_triggered\0"
    "bboxInsertion\0f\0finishedPdfCreation\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus\0"
    "SearchOnGoogle\0GoogleTranslation\0"
    "SaveFile_Backend\0on_actionLoad_Next_Page_triggered\0"
    "on_actionLoad_Prev_Page_triggered\0"
    "LoadDocument\0ext\0name\0pdfPrintIsReady\0"
    "readOutputFromPdfPrint\0insertCompletion\0"
    "completion\0focusInEvent\0QFocusEvent*\0"
    "e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     160,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  814,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  815,    2, 0x08 /* Private */,
       4,    0,  816,    2, 0x08 /* Private */,
       5,    2,  817,    2, 0x08 /* Private */,
       9,    2,  822,    2, 0x08 /* Private */,
      11,    6,  827,    2, 0x08 /* Private */,
      12,    0,  840,    2, 0x08 /* Private */,
      13,    0,  841,    2, 0x08 /* Private */,
      14,    0,  842,    2, 0x08 /* Private */,
      15,    0,  843,    2, 0x08 /* Private */,
      16,    0,  844,    2, 0x08 /* Private */,
      17,    1,  845,    2, 0x08 /* Private */,
      20,    1,  848,    2, 0x08 /* Private */,
      23,    1,  851,    2, 0x08 /* Private */,
      24,    1,  854,    2, 0x08 /* Private */,
      25,    1,  857,    2, 0x08 /* Private */,
      27,    0,  860,    2, 0x08 /* Private */,
      28,    0,  861,    2, 0x08 /* Private */,
      29,    0,  862,    2, 0x08 /* Private */,
      30,    0,  863,    2, 0x08 /* Private */,
      31,    0,  864,    2, 0x08 /* Private */,
      32,    0,  865,    2, 0x08 /* Private */,
      33,    0,  866,    2, 0x08 /* Private */,
      34,    0,  867,    2, 0x08 /* Private */,
      35,    0,  868,    2, 0x08 /* Private */,
      36,    0,  869,    2, 0x08 /* Private */,
      37,    0,  870,    2, 0x08 /* Private */,
      38,    0,  871,    2, 0x08 /* Private */,
      39,    0,  872,    2, 0x08 /* Private */,
      40,    0,  873,    2, 0x08 /* Private */,
      41,    0,  874,    2, 0x08 /* Private */,
      42,    0,  875,    2, 0x08 /* Private */,
      43,    0,  876,    2, 0x08 /* Private */,
      44,    0,  877,    2, 0x08 /* Private */,
      45,    0,  878,    2, 0x08 /* Private */,
      46,    0,  879,    2, 0x08 /* Private */,
      47,    0,  880,    2, 0x08 /* Private */,
      48,    0,  881,    2, 0x08 /* Private */,
      49,    0,  882,    2, 0x08 /* Private */,
      50,    0,  883,    2, 0x08 /* Private */,
      51,    1,  884,    2, 0x08 /* Private */,
      54,    1,  887,    2, 0x08 /* Private */,
      57,    1,  890,    2, 0x08 /* Private */,
      59,    0,  893,    2, 0x08 /* Private */,
      60,    0,  894,    2, 0x08 /* Private */,
      61,    0,  895,    2, 0x08 /* Private */,
      62,    1,  896,    2, 0x08 /* Private */,
      64,    1,  899,    2, 0x08 /* Private */,
      65,    0,  902,    2, 0x08 /* Private */,
      66,    0,  903,    2, 0x08 /* Private */,
      67,    0,  904,    2, 0x08 /* Private */,
      68,    0,  905,    2, 0x08 /* Private */,
      69,    1,  906,    2, 0x08 /* Private */,
      71,    0,  909,    2, 0x08 /* Private */,
      72,    0,  910,    2, 0x08 /* Private */,
      73,    0,  911,    2, 0x08 /* Private */,
      74,    0,  912,    2, 0x08 /* Private */,
      75,    0,  913,    2, 0x08 /* Private */,
      76,    0,  914,    2, 0x08 /* Private */,
      77,    0,  915,    2, 0x08 /* Private */,
      78,    0,  916,    2, 0x08 /* Private */,
      79,    0,  917,    2, 0x08 /* Private */,
      80,    0,  918,    2, 0x08 /* Private */,
      81,    0,  919,    2, 0x08 /* Private */,
      82,    0,  920,    2, 0x08 /* Private */,
      83,    0,  921,    2, 0x08 /* Private */,
      84,    0,  922,    2, 0x08 /* Private */,
      85,    0,  923,    2, 0x08 /* Private */,
      86,    1,  924,    2, 0x08 /* Private */,
      88,    0,  927,    2, 0x08 /* Private */,
      89,    1,  928,    2, 0x08 /* Private */,
      91,    1,  931,    2, 0x08 /* Private */,
      92,    0,  934,    2, 0x08 /* Private */,
      93,    0,  935,    2, 0x08 /* Private */,
      94,    0,  936,    2, 0x08 /* Private */,
      95,    0,  937,    2, 0x08 /* Private */,
      96,    0,  938,    2, 0x08 /* Private */,
      97,    1,  939,    2, 0x08 /* Private */,
     100,    1,  942,    2, 0x08 /* Private */,
     102,    1,  945,    2, 0x08 /* Private */,
     104,    0,  948,    2, 0x08 /* Private */,
     105,    0,  949,    2, 0x08 /* Private */,
     106,    0,  950,    2, 0x08 /* Private */,
     107,    0,  951,    2, 0x08 /* Private */,
     108,    0,  952,    2, 0x08 /* Private */,
     109,    0,  953,    2, 0x08 /* Private */,
     110,    0,  954,    2, 0x08 /* Private */,
     111,    0,  955,    2, 0x08 /* Private */,
     112,    0,  956,    2, 0x08 /* Private */,
     113,    0,  957,    2, 0x08 /* Private */,
     114,    0,  958,    2, 0x08 /* Private */,
     115,    0,  959,    2, 0x08 /* Private */,
     116,    0,  960,    2, 0x08 /* Private */,
     117,    0,  961,    2, 0x08 /* Private */,
     118,    1,  962,    2, 0x08 /* Private */,
     119,    0,  965,    2, 0x08 /* Private */,
     120,    0,  966,    2, 0x08 /* Private */,
     121,    2,  967,    2, 0x08 /* Private */,
     123,    3,  972,    2, 0x08 /* Private */,
     128,    2,  979,    2, 0x08 /* Private */,
     132,    0,  984,    2, 0x08 /* Private */,
     133,    0,  985,    2, 0x08 /* Private */,
     134,    0,  986,    2, 0x08 /* Private */,
     135,    2,  987,    2, 0x08 /* Private */,
     137,    2,  992,    2, 0x08 /* Private */,
     139,    2,  997,    2, 0x08 /* Private */,
     140,    2, 1002,    2, 0x08 /* Private */,
     144,    0, 1007,    2, 0x08 /* Private */,
     145,    0, 1008,    2, 0x08 /* Private */,
     146,    0, 1009,    2, 0x08 /* Private */,
     147,    0, 1010,    2, 0x08 /* Private */,
     148,    0, 1011,    2, 0x08 /* Private */,
     149,    0, 1012,    2, 0x08 /* Private */,
     150,    0, 1013,    2, 0x08 /* Private */,
     151,    0, 1014,    2, 0x08 /* Private */,
     152,    0, 1015,    2, 0x08 /* Private */,
     153,    1, 1016,    2, 0x08 /* Private */,
     155,    1, 1019,    2, 0x08 /* Private */,
     156,    0, 1022,    2, 0x08 /* Private */,
     157,    0, 1023,    2, 0x08 /* Private */,
     158,    2, 1024,    2, 0x08 /* Private */,
     161,    0, 1029,    2, 0x08 /* Private */,
     162,    1, 1030,    2, 0x08 /* Private */,
     163,    0, 1033,    2, 0x08 /* Private */,
     164,    1, 1034,    2, 0x08 /* Private */,
     166,    2, 1037,    2, 0x08 /* Private */,
     168,    2, 1042,    2, 0x08 /* Private */,
     171,    0, 1047,    2, 0x08 /* Private */,
     172,    0, 1048,    2, 0x08 /* Private */,
     173,    0, 1049,    2, 0x08 /* Private */,
     174,    0, 1050,    2, 0x08 /* Private */,
     175,    0, 1051,    2, 0x08 /* Private */,
     176,    0, 1052,    2, 0x08 /* Private */,
     177,    0, 1053,    2, 0x08 /* Private */,
     178,    0, 1054,    2, 0x08 /* Private */,
     179,    1, 1055,    2, 0x08 /* Private */,
     181,    0, 1058,    2, 0x08 /* Private */,
     182,    0, 1059,    2, 0x08 /* Private */,
     183,    0, 1060,    2, 0x08 /* Private */,
     184,    0, 1061,    2, 0x08 /* Private */,
     185,    0, 1062,    2, 0x08 /* Private */,
     186,    1, 1063,    2, 0x08 /* Private */,
     187,    1, 1066,    2, 0x08 /* Private */,
     189,    0, 1069,    2, 0x08 /* Private */,
     190,    0, 1070,    2, 0x08 /* Private */,
     191,    1, 1071,    2, 0x08 /* Private */,
     194,    0, 1074,    2, 0x08 /* Private */,
     195,    1, 1075,    2, 0x08 /* Private */,
     195,    0, 1078,    2, 0x28 /* Private | MethodCloned */,
     197,    2, 1079,    2, 0x08 /* Private */,
     201,    0, 1084,    2, 0x08 /* Private */,
     202,    0, 1085,    2, 0x08 /* Private */,
     203,    0, 1086,    2, 0x0a /* Public */,
     204,    0, 1087,    2, 0x0a /* Public */,
     205,    0, 1088,    2, 0x0a /* Public */,
     206,    3, 1089,    2, 0x0a /* Public */,
     209,    0, 1096,    2, 0x0a /* Public */,
     210,    0, 1097,    2, 0x0a /* Public */,
     211,    1, 1098,    2, 0x0a /* Public */,
     213,    1, 1101,    2, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, QMetaType::QPoint,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   70,
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
    QMetaType::Void, QMetaType::QString,   87,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   90,
    QMetaType::Void, QMetaType::Bool,   90,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 98,   99,
    QMetaType::QJsonObject, QMetaType::QJsonObject,  101,
    QMetaType::Bool, QMetaType::QString,  103,
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
    QMetaType::Void, QMetaType::QString, 0x80000000 | 122,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 126,  124,  125,  127,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 130,  129,  131,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  129,  136,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  129,  138,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    0x80000000 | 130, 0x80000000 | 122, 0x80000000 | 142,  141,  143,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  154,
    QMetaType::Void, QMetaType::Int,  154,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  159,  160,
    QMetaType::Void,
    0x80000000 | 130, 0x80000000 | 130,    2,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 165,   56,
    QMetaType::Void, 0x80000000 | 130, 0x80000000 | 167,    2,    2,
    0x80000000 | 169, QMetaType::QString, 0x80000000 | 130,  170,  131,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  180,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::QString, 0x80000000 | 138,  188,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 192,  193,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55,  196,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 199,  198,  200,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55, QMetaType::QString, QMetaType::QString,   56,  207,  208,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  212,
    QMetaType::Void, 0x80000000 | 214,  215,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeSignal(); break;
        case 1: _t->createActions(); break;
        case 2: _t->WordCount(); break;
        case 3: _t->DisplayJsonDict((*reinterpret_cast< newTextBrowser*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
        case 41: _t->LoadImageFromFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 42: _t->CustomContextMenuTriggered((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 43: _t->AddNewFile(); break;
        case 44: _t->OpenDirectory(); break;
        case 45: _t->RemoveFile(); break;
        case 46: _t->closetab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->tabchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_actionTurn_In_triggered(); break;
        case 49: _t->on_actionPush_triggered(); break;
        case 50: _t->on_actionFetch_2_triggered(); break;
        case 51: _t->on_actionVerifier_Turn_In_triggered(); break;
        case 52: _t->directoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 53: _t->on_actionAccuracyLog_triggered(); break;
        case 54: _t->on_compareCorrectorOutput_clicked(); break;
        case 55: _t->on_viewComments_clicked(); break;
        case 56: _t->on_actionZoom_In_triggered(); break;
        case 57: _t->on_actionZoom_Out_triggered(); break;
        case 58: _t->on_actionSymbols_triggered(); break;
        case 59: _t->on_actionInsert_Tab_Space_triggered(); break;
        case 60: _t->on_actionInsert_Horizontal_Line_triggered(); break;
        case 61: _t->on_actionSubscript_triggered(); break;
        case 62: _t->on_actionSuperscript_triggered(); break;
        case 63: _t->UpdateFileBrekadown(); break;
        case 64: _t->on_actionAdd_Image_triggered(); break;
        case 65: _t->SaveTimeLog(); break;
        case 66: _t->DisplayTimeLog(); break;
        case 67: _t->on_actionResize_Image_triggered(); break;
        case 68: _t->LogHighlights((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 69: _t->on_compareVerifierOutput_clicked(); break;
        case 70: _t->on_sanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 71: _t->on_hinButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 72: _t->on_actionLineSpace_triggered(); break;
        case 73: _t->on_actionUndo_triggered(); break;
        case 74: _t->on_actionRedo_triggered(); break;
        case 75: _t->on_actionNew_Project_triggered(); break;
        case 76: _t->on_actionInsert_Table_2_triggered(); break;
        case 77: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 78: { QJsonObject _r = _t->getAverageAccuracies((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 79: { bool _r = _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 80: _t->on_actionInsert_Columnleft_triggered(); break;
        case 81: _t->on_actionInsert_Columnright_triggered(); break;
        case 82: _t->on_actionInsert_Rowabove_triggered(); break;
        case 83: _t->on_actionInsert_Rowbelow_triggered(); break;
        case 84: _t->on_actionRemove_Column_triggered(); break;
        case 85: _t->on_actionRemove_Row_triggered(); break;
        case 86: _t->on_actionItalic_triggered(); break;
        case 87: _t->on_actionNonitalic_triggered(); break;
        case 88: _t->on_actionSave_All_triggered(); break;
        case 89: _t->on_actionFind_and_Replace_triggered(); break;
        case 90: { bool _r = _t->checkUnsavedWork();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 91: _t->saveAllWork(); break;
        case 92: _t->readSettings(); break;
        case 93: _t->writeSettings(); break;
        case 94: _t->setMFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 95: _t->on_pushButton_clicked(); break;
        case 96: _t->on_pushButton_2_clicked(); break;
        case 97: _t->runGlobalReplace((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 98: { bool _r = _t->globalReplaceQueryMessageBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 99: { int _r = _t->writeGlobalCPairsToFiles((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 100: _t->addCurrentlyOpenFileToEditedFilesLog(); break;
        case 101: _t->deleteEditedFilesLog(); break;
        case 102: _t->RecentPageInfo(); break;
        case 103: { bool _r = _t->isStringInFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 104: _t->dumpStringToFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 105: _t->highlight((*reinterpret_cast< newTextBrowser*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 106: { QMap<QString,QString> _r = _t->getGlobalReplacementMapFromChecklistDialog((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<int>*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 107: _t->on_actionas_PDF_triggered(); break;
        case 108: _t->on_actionGet_Help_triggered(); break;
        case 109: _t->on_actionTutorial_triggered(); break;
        case 110: _t->on_actionLinux_triggered(); break;
        case 111: _t->on_actionWindows_triggered(); break;
        case 112: _t->on_actionShortcut_Guide_triggered(); break;
        case 113: _t->on_textBrowser_textChanged(); break;
        case 114: _t->on_zoom_Out_Button_clicked(); break;
        case 115: _t->on_zoom_In_Button_clicked(); break;
        case 116: _t->zoom_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 117: _t->zoom_slider_moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 118: _t->zoomedUsingScroll(); break;
        case 119: _t->on_actionUndo_Global_Replace_triggered(); break;
        case 120: { bool _r = _t->undoGlobalReplace_Single_Word((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 121: _t->reverseGlobalReplacedWordsMap(); break;
        case 122: { QMap<QString,QString> _r = _t->getUndoGlobalReplaceMap_Multiple_Words((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 123: _t->replaceInAllFilesFromTSVfile(); break;
        case 124: { bool _r = _t->checkForValidTSVfile((*reinterpret_cast< QFile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 125: _t->globalReplacePreviewfn((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        case 126: { QMap<QString,QStringList> _r = _t->getBeforeAndAfterWords((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 127: _t->on_actionUpload_triggered(); break;
        case 128: _t->on_justify_triggered(); break;
        case 129: _t->on_actionFont_Color_triggered(); break;
        case 130: _t->on_actionBold_triggered(); break;
        case 131: _t->SaveFile_GUI_Preprocessing(); break;
        case 132: _t->SaveFile_GUI_Postprocessing(); break;
        case 133: _t->GlobalReplace(); break;
        case 134: _t->stopSpinning(); break;
        case 135: _t->on_lineEditSearch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 136: _t->on_action1_triggered(); break;
        case 137: _t->on_action2_triggered(); break;
        case 138: _t->on_action3_triggered(); break;
        case 139: _t->on_actionCheck_for_Updates_triggered(); break;
        case 140: _t->closeProgressBar(); break;
        case 141: _t->setProgressBarPerc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 142: { QString _r = _t->toDevanagari((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 143: _t->on_find_clicked(); break;
        case 144: _t->on_actionPDF_Preview_triggered(); break;
        case 145: _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 146: _t->on_actionChange_Role_triggered(); break;
        case 147: _t->bboxInsertion((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 148: _t->bboxInsertion(); break;
        case 149: _t->finishedPdfCreation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 150: _t->SearchOnGoogle(); break;
        case 151: _t->GoogleTranslation(); break;
        case 152: _t->SaveFile_Backend(); break;
        case 153: _t->on_actionLoad_Next_Page_triggered(); break;
        case 154: _t->on_actionLoad_Prev_Page_triggered(); break;
        case 155: _t->LoadDocument((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 156: _t->pdfPrintIsReady(); break;
        case 157: _t->readOutputFromPdfPrint(); break;
        case 158: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 159: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< newTextBrowser* >(); break;
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
        case 97:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 105:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< newTextBrowser* >(); break;
            }
            break;
        case 106:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 125:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 147:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 155:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
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
        if (_id < 160)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 160;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 160)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 160;
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
