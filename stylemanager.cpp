#include "StyleManager.h"


StyleManager::StyleManager(QString &tell_me_your_style_sheet_path)
    :base_ptr_(NULL)
{
        default_style_sheet_path_= tell_me_your_style_sheet_path;
}

void StyleManager::InvokeEditOption(kClassType class_type, QString &object_name)
{
    {
        //Create Edit Dialog in Stack
        if(class_type == kInvalid)
        {
            QMessageBox msg;
            msg.setText("Class Name Validation: Failed!!");
            msg.exec();
            return;
        }
        if(object_name.isEmpty())
        {
            QMessageBox msg;
            msg.setText("Object Name Validation: Is Empty!!");
            msg.exec();
            return;
        }
        k_selected_class_type_ = class_type;
        selected_object_name_= object_name;

        EditDialogGenerator edit_dialog_gen;
        base_ptr_ = edit_dialog_gen.Invoke(class_type);
        connect(base_ptr_->reset_button_,&QPushButton::clicked,this,&StyleManager::onResetButtonClicked);
        connect(base_ptr_->apply_button_,&QPushButton::clicked,this,&StyleManager::onApplyButtonClicked);
        connect(base_ptr_->preview_button_,&QPushButton::clicked,this,&StyleManager::onPreviewButtonClicked);


        base_ptr_->Display();

    }
}

void StyleManager::onApplyButtonClicked()
{
    // Get the
}

void StyleManager::onResetButtonClicked()
{

}

void StyleManager::onPreviewButtonClicked()
{
    //Get the preview ss and Emit a signal with the SS.
    if(base_ptr_== NULL)
       return;
    QString s_sheet = PrepareSSForPreview();
    emit styleSheetUpdated(s_sheet);
}

QString StyleManager::PrepareSSForPreview()
{
    QString final_SS;

    // Prepare the Headlines
    QString headline = GetClassName()+"#"+selected_object_name_+"{";

    final_SS.append(headline);

    QList<QWidget*>::iterator i;
    for (i = base_ptr_->list_selected_options_widget_.begin(); i != base_ptr_->list_selected_options_widget_.end(); ++i)
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

QString StyleManager::GetClassName()
{
    switch (k_selected_class_type_) {
    case kPushButton:
        return CLASS_NAME_PUSH_BUTTON;
        break;
    default :
        return CLASS_NAME_PUSH_BUTTON;
        break;
    }

}

QString StyleManager::GenerateSSInternalContents(QString &title)
{
    QString internal_content;
    if(title == NAME_EDIT_COLOR_BUTTON)
    {
//        internal_content = "color :"+base_ptr_->color_.name(QColor::HexArgb)+";"; //#00ffffff
    }
    else if(title == NAME_EDIT_BACKGROUND_BUTTON)
    {
        internal_content = "background-color :"+base_ptr_->background_color_.name(QColor::HexArgb)+";"; //#00ffffff
     }


    return internal_content;

}

