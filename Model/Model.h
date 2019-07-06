#ifndef MODEL_H
#define MODEL_H
#include "QColor"
#include "globaldefines.h"
#include "map"

class Model
{
public:
    Model(QString &style_sheet_file_path, kStyleSheetPathType path_type);
    void SetColor(QColor &color);
    QColor GetColor ();
    void SetBackgroundColor(QColor &background_color);
    QColor GetBackgroundColor ();
    void SetSelectedClassType(kClassType &class_type);
    kClassType GetSelectedClassType();
    void SetObjectNameType(QString &object_name);
    QString GetObjectName();
    QString GetClassName();
    QString GetFilePath();

    void SetNewStyleSheetFilePath(QString &new_file_path);
    QString GetNewStyleSheetFilePath();

    kStyleSheetPathType GetStyleSheetPathType();
private:
    QColor color_;
    QColor background_color_;
    kClassType k_selected_class_type_;
    QString selected_object_name_;
    QString style_sheet_file_path_;
    QString new_style_sheet_file_path_;
    kStyleSheetPathType path_type_;



public :
    std::map<QString, QString> map_object_name_vs_stylesheet_;
    QString final_style_sheet_;
};


#endif // MODEL_H
