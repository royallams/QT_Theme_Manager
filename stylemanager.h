#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H
#include "EditDialogs.h"
#include "EditDialogGenerator.h"
#include "QMap"


class StyleManager:public QObject
{
    Q_OBJECT
public:
    explicit StyleManager(QString &tell_me_your_style_sheet_path);
    void InvokeEditOption(kClassType class_type, QString &object_name);


private:
    QString PrepareSSForPreview();
    QString GenerateSSInternalContents(QString &title);

    QString GetClassName();

    QMap<QString,QString>map_objectname_stylesheet_;
    QString default_style_sheet_path_;
    QString applied_style_sheet_path_;
    kClassType k_selected_class_type_;
    QString selected_object_name_;

    BaseUI *base_ptr_;

signals:
    void styleSheetUpdated(QString &stylesheet);
    void notify(QString &messages);


public slots:
    void onApplyButtonClicked();
    void onResetButtonClicked();
    void onPreviewButtonClicked();
};





#endif // STYLEMANAGER_H
