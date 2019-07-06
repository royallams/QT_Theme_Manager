#include "Model.h"

Model::Model(QString &style_sheet_file_path, kStyleSheetPathType path_type)
    :style_sheet_file_path_(style_sheet_file_path)
    ,path_type_(path_type)
{

}

void Model::SetColor(QColor &color)
{
    color_ = color;
}

QColor Model::GetColor()
{
    return color_;
}

void Model::SetBackgroundColor(QColor &background_color)
{
    background_color_ = background_color;
}

QColor Model::GetBackgroundColor()
{
    return background_color_;

}

void Model::SetSelectedClassType(kClassType &class_type)
{
    k_selected_class_type_= class_type;
}

kClassType Model::GetSelectedClassType()
{
    return k_selected_class_type_;
}

void Model::SetObjectNameType(QString &object_name)
{
    selected_object_name_= object_name;
}

QString Model::GetObjectName()
{
    return selected_object_name_;
}

QString Model::GetClassName()
{

    switch (k_selected_class_type_) {
    case kPushButton:
        return CLASS_NAME_PUSH_BUTTON;
        break;
    case kCheckBox:
        return CLASS_NAME_CHECK_BOX;
        break;
    case kPlainTextEdit:
        return CLASS_NAME_PLAIN_TEXT_EDIT;
        break;
    case kDialog:
        return CLASS_NAME_DIALOG;
        break;
    case kLabel:
        return CLASS_NAME_DIALOG;
        break;
    case kWidget:
        return CLASS_NAME_WIDGET;
        break;
    default :
        return CLASS_NAME_UNKNOWN;
        break;
    }

}


QString Model::GetFilePath()
{
    return style_sheet_file_path_;
}

void Model::SetNewStyleSheetFilePath(QString &new_file_path)
{
    new_style_sheet_file_path_= new_file_path;
}

QString Model::GetNewStyleSheetFilePath()
{
    return new_style_sheet_file_path_;
}

kStyleSheetPathType Model::GetStyleSheetPathType()
{
    return path_type_;
}


