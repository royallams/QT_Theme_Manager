#-------------------------------------------------
#
# Project created by QtCreator 2019-07-06T11:31:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtThemeManager
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    QtThemeManager.cpp \
    Controller/Controller.cpp \
    View/OptionUIBase.cpp \
    Model/Model.cpp \
    View/OptionUIPushButton.cpp \
    View/OptionUICheckBox.cpp \
    View/OptionUIDialog.cpp \
    View/EditDialogGenerator.cpp \
    View/OptionUIPlainTextEdit.cpp \
    View/OptionUIWidget.cpp

HEADERS  += mainwindow.h \
    QtThemeManager.h \
    Controller/Controller.h \
    View/OptionUIBase.h \
    Model/Model.h \
    Model/globaldefines.h \
    View/OptionUIPushButton.h \
    View/OptionUICheckBox.h \
    View/OptionUIDialog.h \
    View/EditDialogGenerator.h \
    View/OptionUIPlainTextEdit.h \
    View/OptionUIWidget.h



FORMS    += mainwindow.ui


INCLUDEPATH += $$PWD/Controller
DEPENDPATH += $$PWD/Controller
INCLUDEPATH += $$PWD/View
DEPENDPATH += $$PWD/View
INCLUDEPATH += $$PWD/Model
DEPENDPATH += $$PWD/Model

