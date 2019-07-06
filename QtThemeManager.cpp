#include "QtThemeManager.h"

QtThemeManager::QtThemeManager(QString &style_sheet_path_to_use, kStyleSheetPathType path_type)
    :controller_(new Controller(style_sheet_path_to_use,path_type,this))
{

}

void QtThemeManager::InvokeEditOption(kClassType class_type, QString &object_name)
{
    // Validate the input
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

    controller_->GetModel()->SetSelectedClassType(class_type);
    controller_->GetModel()->SetObjectNameType(object_name);

    // Invoke the View.
    if(!controller_->InvokeEditDialog(class_type))
    {
        //Notify the user
        QString msg = "Invoking Option : FAILED - Could not create a dialog";
        emit notify(msg);
        return;
    }

    // The View should be properly connected to the controller for Storing in Model.
    //Create Edit Dialog in Stack

}

void QtThemeManager::Reset()
{
    // Take the ss from the File incase present orwise show error and return
    if(!controller_->Reset())
    {
        return;
    }
}

void QtThemeManager::Update()
{
    controller_->Update();

}



