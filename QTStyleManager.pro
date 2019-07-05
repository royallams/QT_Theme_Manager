#-------------------------------------------------
#
# Project created by QtCreator 2019-07-05T21:23:54
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTStyleManager
TEMPLATE = app


SOURCES += main.cpp \
    DemoQtGUI.cpp \
    StyleManager.cpp \
    EditDialogs.cpp \
    EditDialogGenerator.cpp

HEADERS  += \
    DemoQtGUI.h \
    GlobalNames.h \
    StyleManager.h \
    EditDialogs.h \
    EditDialogGenerator.h

FORMS += \
    dialog.ui
