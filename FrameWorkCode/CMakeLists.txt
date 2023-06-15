cmake_minimum_required(VERSION 3.16)
project(qpadfinal)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Svg Widgets PrintSupport Xml Network Multimedia REQUIRED)

set(SOURCES
    globalreplacepreview.cpp
CreateProjectPage.cpp
progressbardialog.cpp
about.cpp
trieEditdis.cpp
verifyset.cpp
diff_match_patch.cpp
meanStdPage.cpp
Filters.cpp
ProjectWizard.cpp
crashlog.cpp
loginpageview.cpp
indentoptions.cpp
averageaccuracies.cpp
TreeItem.cpp
worker.cpp
editdistance.cpp
dialog.cpp
Symbols.cpp
undoglobalreplace.cpp
loadingspinner.cpp
connectedsliders.cpp
ProjectHierarchyWindow.cpp
rubberband.cpp
textfinder.cpp
mainwindow.cpp
pdfhandling.cpp
eddis.cpp
slpNPatternDict.cpp
Project.cpp
globalreplaceinformation.cpp
DiffView.cpp
markRegion.cpp
handlebbox.cpp
resizeimageview.cpp
addkeyboardshortcut.cpp
interndiffview.cpp
printworker.cpp
equationeditor.cpp
threadingpush.cpp
pdfrangedialog.cpp
TreeModel.cpp
dashboard.cpp
loaddataworker.cpp
globalreplacedialog.cpp
globalreplaceworker.cpp
customtextbrowser.cpp
main.cpp
commentsdialog.cpp
zoom.cpp
lg2_common.cpp
shortcutguidedialog.cpp
commentsview.cpp
    # Add more source files here if needed
)

set(HEADERS
resizeimageview.h
dashboard.h
Filters.h
addshortcut.h
CreateProjectPage.h
about.h
pdfrangedialog.h
globalreplacedialog.h
globalreplacepreview.h
connectedsliders.h
verifyset.h
dialog.h
TreeItem.h
samasBreakCombineqt.h
globalreplaceinformation.h
mainwindow.h
Project.h
crashlog.h
trieEditdis.h
progressbardialog.h
pdfhandling.h
lcsqt.h
undoglobalreplace.h
ProjectWizard.h
ProjectHierarchyWindow.h
shortcutguidedialog.h
customtextbrowser.h
worker.h
rubberband.h
DiffView.h
handlebbox.h
indentoptions.h
zoom.h
globalreplaceworker.h
lg2_common.h
loginpageview.h
addkeyboardshortcut.h
loadingspinner.h
textfinder.h
addkeyshortcut.h
TreeModel.h
commentsview.h
diff_match_patch.h
editdistance.h
averageaccuracies.h
meanStdPage.h
Symbols.h
threadingpush.h
equationeditor.h
slpNPatternDict.h
eddis.h
loaddataworker.h
markRegion.h
interndiffview.h
printworker.h
    # Add more header files here if needed
)

set(RESOURCES
    AppResources.qrc
    # Add more resource files here if needed
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Svg
    Qt5::Widgets
    Qt5::PrintSupport
    Qt5::Xml
    Qt5::Network
    Qt5::Multimedia
)

# Additional libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    -L${CMAKE_CURRENT_SOURCE_DIR}/../lib/
    -lYAWYSIWYGEE
    -lquazip
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# # Additional configuration for specific platforms
# if(WIN32)
#     if(MSVC)
#         # Link against the release version of the library for release builds
#         target_link_libraries(${PROJECT_NAME}
#             PRIVATE
#             -L${CMAKE_CURRENT_SOURCE_DIR}/../lib/release/
#             -lYAWYSIWYGEE
#         )
#         # Link against the debug version of the library for debug builds
#         target_link_libraries(${PROJECT_NAME}
#             PRIVATE
#             -L${CMAKE_CURRENT_SOURCE_DIR}/../lib/debug/
#             -lYAWYSIWYGEE
#         )
#     else()
#         # Assuming it is MinGW, modify the library names accordingly
#         target_link_libraries(${PROJECT_NAME}
#             PRIVATE
#             -L${CMAKE_CURRENT_SOURCE_DIR}/../lib/
#             -lYAWYSIWYGEE
#         )
#     endif()
# endif()
