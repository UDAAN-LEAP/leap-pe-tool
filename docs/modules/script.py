class_list = [
        "AverageAccuracies",
        "CommentsView",
        "CreateProjectPage",
        "CustomTextBrowser",
        "dashboard",
        "DiffView",
        "eddis",
        "edit_Distance",
        "equationeditor",
        "Filter",
        "GlobalReplaceDialog",
        "globalReplaceInformation",
        "globalReplacePreview",
        "GlobalReplaceWorker",
        "HandleBbox",
        "InternDiffView",
        "lg2_common",
        "LoadDataWorker",
        "LoadingSpinner",
        "LoginPageView",
        "MainWindow",
        "markRegion",
        "meanStdPage",
        "PDFHandling",
        "PdfRangeDialog",
        "PrintWorker",
        "ProgressBarDialog",
        "Project",
        "ProjectHierarchyWindow",
        "ProjectWizard",
        "ResizeImageView",
        "ShortcutGuideDialog",
        "slpNPatternDict",
        "SymbolsView",
        "TextFinder",
        "TreeItem",
        "TreeModel",
        "trieEditDis",
        "UndoGlobalReplace",
        "VerifySet",
        "Worker",
        "Graphics_view_zoom"
]

for cpp_class in class_list:
    f = open(f"{cpp_class.lower()}.rst", "w")
    f.write(cpp_class + "\n" + ("="*len(cpp_class)) + "\n\n")
    f.write(f".. doxygenclass:: {cpp_class}" + "\n   :members:\n" + "   :private-members:\n")
    f.close()

