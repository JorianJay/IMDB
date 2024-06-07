#-------------------------------------------------
#
# Project created by QtCreator 2011-12-29T20:43:23
#  webkitwidgets core gui webkit network widgets
#-------------------------------------------------

QT       += gui core network webkitwidgets sensors declarative script scripttools

TARGET = IMDB
TEMPLATE = app

#-----------------------------------------------------
# LIBS += -L/path/to/libfuzzylite/library -lfuzzylite
# INCLUDEPATH+=/path/to/libfuzzylite/headers
#------------------------------------------------------

SOURCES += main.cpp\
        mainwindow.cpp \
    imdbsettings.cpp \
    imdb.cpp \
    imdbtimer.cpp \
    qexceptionapp.cpp \
    gallerypages.cpp \
    gallerytab.cpp \
    imagelabel.cpp \
    reviewpages.cpp \
    reviewtab.cpp

HEADERS  += mainwindow.h \
    imdbsettings.h \
    imdb.h \
    imdbtimer.h \
    qexceptionapp.h \
    gallerypages.h \
    gallerytab.h \
    imagelabel.h \
    reviewpages.h \
    reviewtab.h

FORMS    += mainwindow.ui \
    imdbsettings.ui \
    imdb.ui

CONFIG(debug, debug|release):DEFINES+=DEBUG

RESOURCES += \
    imdbResources.qrc

RC_FILE = imdb.rc

OTHER_FILES += \
    html/Status.html \
    images/Video.png \
    images/Upload.png \
    images/Tools.png \
    images/Toolbar Videos.png \
    images/Stop.png \
    images/Speech_Bubble.png \
    images/Recycle_Bin_Full.png \
    images/PieChart.png \
    images/Photo_Album.png \
    images/Info.png \
    images/Book.png





































