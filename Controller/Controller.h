#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "qcolordialog.h"
#include "Model.h"
#include "QMessageBox"
#include "EditDialogGenerator.h"
#include "QColorDialog"
#include "QObject"
#include "QtThemeManager.h"
#include "QTextStream"

class Controller: public QObject
{
    Q_OBJECT
public:
    Controller(QString &style_sheet_file_path,kStyleSheetPathType path_type,QObject *parent=0);
    bool InvokeEditDialog(kClassType class_type);
    Model* GetModel();
    bool IsBaseUINull();
    bool CloseBaseUI();
    QString  GetPreviewSS();
    QString GenerateSSInternalContents(QString &title);
    void ConnectSignalsAndSlots();
    bool Reset();
    void Update();
public slots:
    void onEditColorButtonClicked();
    void onEditBackgroundButtonClicked();
    void onEditIconButtonClicked();

    void onResetButtonClicked();
    void onApplyButtonClicked();
    void onPreviewButtonClicked();
private:
    void Connect(QWidget *widget_ptr);
    bool UpdateStyleSheetToUser(QString &style_sheet_file_path);
    void UpdateFinalStyleSheet();

    Model *model_;
    QObject *parent_object_;
    OptionUIBase *base_ui_ptr_;

};

#endif // CONTROLLER_H
