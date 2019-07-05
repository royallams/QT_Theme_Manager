#include "EditDialogs.h"


BaseUI::BaseUI()
{

}

void BaseUI::CreateCentralWidget()
{
    v_layout_ = new QVBoxLayout;
    reset_button_ = new QPushButton(this);
    reset_button_->setText(NAME_RESET_BUTTON);
    reset_button_->setWindowTitle(NAME_RESET_BUTTON);

    apply_button_ = new QPushButton(this);
    apply_button_->setText(NAME_APPLY_BUTTON);
    apply_button_->setWindowTitle(NAME_APPLY_BUTTON);

    preview_button_ = new QPushButton(this);
    preview_button_->setText(NAME_PREVIEW_BUTTON);
    preview_button_->setWindowTitle(NAME_PREVIEW_BUTTON);

    v_layout_->addWidget(reset_button_);
    v_layout_->addWidget(apply_button_);
    v_layout_->addWidget(preview_button_);



    list_selected_options_widget_.push_back(reset_button_);
    list_selected_options_widget_.push_back(apply_button_);
}

void BaseUI::AddColorOption()
{
    edit_color_button_ = new QPushButton(this);
    edit_color_button_->setText(NAME_EDIT_COLOR_BUTTON);
    edit_color_button_->setWindowTitle(NAME_EDIT_COLOR_BUTTON);

    connect(edit_color_button_,&QPushButton::clicked,this,&BaseUI::onEditColorButtonClicked);
    v_layout_->addWidget(edit_color_button_);
    list_selected_options_widget_.push_back(edit_color_button_);

    UpdateLayout();


}

void BaseUI::AddBackgroundOption()
{
    edit_background_button_ = new QPushButton(this);
    edit_background_button_->setText(NAME_EDIT_BACKGROUND_BUTTON);
    edit_background_button_->setWindowTitle(NAME_EDIT_BACKGROUND_BUTTON);

    connect(edit_background_button_,&QPushButton::clicked,this,&BaseUI::onEditBackgroundButtonClicked);
    v_layout_->addWidget(edit_background_button_);
    list_selected_options_widget_.push_back(edit_background_button_);

    UpdateLayout();
}

void BaseUI::AddIconOption()
{
    edit_icon_button_ = new QPushButton(this);
    edit_icon_button_->setText(NAME_EDIT_ICON_BUTTON);
    edit_icon_button_->setWindowTitle(NAME_EDIT_ICON_BUTTON);

    connect(edit_icon_button_,&QPushButton::clicked,this,&BaseUI::onEditIconButtonClicked);
    v_layout_->addWidget(edit_icon_button_);
    list_selected_options_widget_.push_back(edit_icon_button_);

    UpdateLayout();
}



void BaseUI::onEditColorButtonClicked()
{

    // invoke the color Dialog
    QColorDialog color_dialog;
    color_ = color_dialog.getColor();

}

void BaseUI::onEditBackgroundButtonClicked()
{
    QColorDialog color_dialog;
    background_color_ = color_dialog.getColor();
}

void BaseUI::onEditIconButtonClicked()
{
    QMessageBox msg;
    msg.setText("onEditIconButtonClicked");
    msg.exec();
}



void BaseUI::UpdateLayout()
{
    this->setLayout(v_layout_);
}



/*************************************DERIVED CLASSES****************************/
EditPushButtonUI::EditPushButtonUI()
{
    CreateCentralWidget();
    AddColorOption();
    AddBackgroundOption();

}


EditDialogUI::EditDialogUI()
{
    CreateCentralWidget();
    AddColorOption();
    AddBackgroundOption();
    AddIconOption();
}


EditCheckBoxUI::EditCheckBoxUI()
{
    CreateCentralWidget();
    AddColorOption();
    AddBackgroundOption();
    AddIconOption();
}


