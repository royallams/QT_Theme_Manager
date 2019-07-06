#include "Controller.h"

Controller::Controller(QString &style_sheet_file_path, kStyleSheetPathType path_type, QObject *parent)
    :parent_object_(parent)
    ,model_(new Model(style_sheet_file_path,path_type))
    ,base_ui_ptr_(NULL)
{

}



bool Controller::InvokeEditDialog(kClassType class_type)
{
    EditDialogGenerator edit_dialog_gen;
    base_ui_ptr_= edit_dialog_gen.Create(class_type);

    if(base_ui_ptr_ == NULL)
    {
        return false;
    }

    ConnectSignalsAndSlots();
    base_ui_ptr_->Display();
    return true;

}

Model *Controller::GetModel(){
    return model_;
}

bool Controller::IsBaseUINull(){
    if(base_ui_ptr_== NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Controller::CloseBaseUI()
{
    if(base_ui_ptr_ != NULL)
    {
        delete base_ui_ptr_;
        base_ui_ptr_= NULL;
        return true;
    }

    return false;
}



QString Controller::GetPreviewSS()
{

    QString final_SS;

    // Prepare the Headlines
    QString headline = model_->GetClassName()+"#"+model_->GetObjectName()+"{";

    final_SS.append(headline);

    QList<QWidget*>::iterator i;
    for (i = base_ui_ptr_->list_selected_options_widget_.begin(); i != base_ui_ptr_->list_selected_options_widget_.end(); ++i)
    {

        QString title= (*i)->windowTitle();

        // Get the SS content appen in the whole context
        QString content_line= GenerateSSInternalContents(title);
        final_SS.append(content_line );
    }


    //Close the Body
    QString close_brac = "}";
    final_SS.append(close_brac);

    return final_SS;



}




void Controller::onEditColorButtonClicked()
{

    // invoke the color Dialog
    QColorDialog color_dialog;
    QColor color= color_dialog.getColor();
    model_->SetColor(color);

    QString msg= "Color Set.";
    emit dynamic_cast<QtThemeManager*>(parent_object_)->notify(msg);
    onPreviewButtonClicked();

}

void Controller::onEditBackgroundButtonClicked()
{
    QColorDialog color_dialog;
    QColor background_color= color_dialog.getColor();
    model_->SetBackgroundColor(background_color);

    QString msg= "onEditBackgroundButtonClicked";
    emit dynamic_cast<QtThemeManager*>(parent_object_)->notify(msg);
    onPreviewButtonClicked();

}

void Controller::onEditIconButtonClicked()
{

    QString msg= "onEditIconButtonClicked";
    emit dynamic_cast<QtThemeManager*>(parent_object_)->notify(msg);
    onPreviewButtonClicked();

}

void Controller::Connect(QWidget *widget_ptr)
{
    //Get the window title
    QString window_title= widget_ptr->windowTitle();


    if(window_title == NAME_EDIT_BACKGROUND_BUTTON)
    {
        QPushButton * back_color_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(back_color_button,&QPushButton::clicked,this,&Controller::onEditBackgroundButtonClicked);
    }
    else if(window_title == NAME_EDIT_COLOR_BUTTON)
    {
        QPushButton * color_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(color_button,&QPushButton::clicked,this,&Controller::onEditColorButtonClicked);
    }
    else if(window_title == NAME_EDIT_ICON_BUTTON)
    {
        QPushButton * icon_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(icon_button,&QPushButton::clicked,this,&Controller::onEditIconButtonClicked);

    }
    else if(window_title == NAME_EXPORT_BUTTON)
    {

    }
    else if(window_title == NAME_PREVIEW_BUTTON)
    {
        QPushButton * preview_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(preview_button,&QPushButton::clicked,this,&Controller::onPreviewButtonClicked);

    }
    else if(window_title == NAME_RESET_BUTTON)
    {
        QPushButton * reset_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(reset_button,&QPushButton::clicked,this,&Controller::onResetButtonClicked);

    }
    else if(window_title == NAME_APPLY_BUTTON)
    {
        QPushButton * apply_button= dynamic_cast<QPushButton*>(widget_ptr);
        connect(apply_button,&QPushButton::clicked,this,&Controller::onApplyButtonClicked);

    }


}

QString Controller::GenerateSSInternalContents(QString &title)
{
    QString internal_content;
    if(title == NAME_EDIT_COLOR_BUTTON)
    {
        //        internal_content = "color :"+base_ptr_->color_.name(QColor::HexArgb)+";"; //#00ffffff
    }
    else if(title == NAME_EDIT_BACKGROUND_BUTTON)
    {
        internal_content = "background-color :"+model_->GetBackgroundColor().name(QColor::HexArgb)+";"; //#00ffffff
    }


    return internal_content;

}

void Controller::ConnectSignalsAndSlots()
{
    QList<QWidget*>::iterator i;
    for (i = base_ui_ptr_->list_selected_options_widget_.begin(); i != base_ui_ptr_->list_selected_options_widget_.end(); ++i)
    {
        Connect(*i);
    }


}

void Controller::Update()
{
    QString style_sheet_file_path ;
    switch (model_->GetStyleSheetPathType()) {
    case kDefaultPath:
        style_sheet_file_path= model_->GetFilePath();
        break;
    case kLatestPath:
        style_sheet_file_path= model_->GetNewStyleSheetFilePath();
        break;
    default:
        style_sheet_file_path= model_->GetFilePath();
        break;
    }

    UpdateStyleSheetToUser(style_sheet_file_path);
    QtThemeManager *theme_manager= dynamic_cast<QtThemeManager*>(parent_object_);
    QString msg= "Update: Done";
    emit theme_manager->notify(msg);

}

bool Controller::UpdateStyleSheetToUser(QString &style_sheet_file_path)
{

    QtThemeManager *theme_manager= dynamic_cast<QtThemeManager*>(parent_object_);

    if(!QFile(style_sheet_file_path).exists())
    {
        QString msg= "File Path does not exist!!";
        emit theme_manager->notify(msg);
        return false;
    }
    QFile file(style_sheet_file_path);
    if(!file.open(QFile::ReadOnly))
    {
        QString msg= " Could not open the file for reading";
        emit theme_manager->notify(msg);
        return false;
    }

    QTextStream in(&file);
    QString ss_text = in.readAll();


    emit theme_manager->styleSheetUpdated(ss_text);
    QString msg= "Update Style Sheet to user: Done";
    emit theme_manager->notify(msg);

    msg="StyleSheet data:- "+ss_text;
    emit theme_manager->notify(msg);


    file.close();
}

bool Controller::Reset()
{
    QtThemeManager *theme_manager= dynamic_cast<QtThemeManager*>(parent_object_);
    QString style_sheet_file_path= model_->GetFilePath();
    UpdateStyleSheetToUser(style_sheet_file_path);
    QString msg= "Reset: Done";
    emit theme_manager->notify(msg);
    return true;

}

void Controller::onPreviewButtonClicked()
{
    //Get the preview ss and Emit a signal with the SS.
    if(IsBaseUINull())
        return;

    QString s_sheet = GetPreviewSS();

    // Edit to the back up Map
    model_->map_object_name_vs_stylesheet_[model_->GetObjectName()]= s_sheet ;

    UpdateFinalStyleSheet();
    emit dynamic_cast<QtThemeManager*>(parent_object_)->styleSheetUpdated(model_->final_style_sheet_);

    QString msg= "Preview StyleSheet Sent to the User.";
    emit dynamic_cast<QtThemeManager*>(parent_object_)->notify(msg);

}


void Controller::UpdateFinalStyleSheet()
{
    // Get the SS from the map for the current
    QString merge_style_sheet;
    //Iterate through the map and form a final stylesheet

    for(auto const pair:model_->map_object_name_vs_stylesheet_)
    {
        merge_style_sheet.append(pair.second);
    }

    model_->final_style_sheet_= merge_style_sheet;
}

void Controller::onApplyButtonClicked()
{

    UpdateFinalStyleSheet();

    // dump it to a new_stylesheet file
    QString new_file_name= model_->GetFilePath().remove(".qss");
    new_file_name.append("_new.qss");

    QFile file(new_file_name);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly))
    {
        return;
    }

    QTextStream out(&file);
    out << model_->final_style_sheet_;
    file.flush();
    file.close();

    model_->SetNewStyleSheetFilePath(new_file_name);


    QString msg = "Style Sheet written in File :"+new_file_name;
    emit dynamic_cast<QtThemeManager*>(parent_object_)->notify(msg);

    // POint the stylesheet now to a new filepath
    // Call reset

    UpdateStyleSheetToUser(new_file_name);
    if(!IsBaseUINull())
    {
        CloseBaseUI();
    }
}

void Controller::onResetButtonClicked()
{
    this->Reset();
}
