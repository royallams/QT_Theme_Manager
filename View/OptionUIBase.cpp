#include "OptionUIBase.h"

OptionUIBase::OptionUIBase()
{

}


void OptionUIBase::CreateCentralWidget()
{
    v_layout_ = new QVBoxLayout;
    reset_button_ = new QPushButton(this);
    reset_button_->setText(NAME_RESET_BUTTON);
    reset_button_->setWindowTitle(NAME_RESET_BUTTON);

    apply_button_ = new QPushButton(this);
    apply_button_->setText(NAME_APPLY_BUTTON);
    apply_button_->setWindowTitle(NAME_APPLY_BUTTON);

//    preview_button_ = new QPushButton(this);
//    preview_button_->setText(NAME_PREVIEW_BUTTON);
//    preview_button_->setWindowTitle(NAME_PREVIEW_BUTTON);


    export_to_file_button_ = new QPushButton(this);
    export_to_file_button_->setText(NAME_EXPORT_BUTTON);
    export_to_file_button_->setWindowTitle(NAME_EXPORT_BUTTON);

    v_layout_->addWidget(reset_button_);
    v_layout_->addWidget(apply_button_);
//    v_layout_->addWidget(preview_button_);
    v_layout_->addWidget(export_to_file_button_);



    // This we will maintain to dynamically generate the stylesheet and also to properly connect signals with only required slots..
    list_selected_options_widget_.push_back(reset_button_);
    list_selected_options_widget_.push_back(apply_button_);
//    list_selected_options_widget_.push_back(preview_button_);
    list_selected_options_widget_.push_back(export_to_file_button_);

}

void OptionUIBase::AddColorOption()
{
    edit_color_button_ = new QPushButton(this);
    edit_color_button_->setText(NAME_EDIT_COLOR_BUTTON);
    edit_color_button_->setWindowTitle(NAME_EDIT_COLOR_BUTTON);

    //    connect(edit_color_button_,&QPushButton::clicked,this,&OptionUIBase::onEditColorButtonClicked);
    v_layout_->addWidget(edit_color_button_);
    list_selected_options_widget_.push_back(edit_color_button_);

    UpdateLayout();


}

void OptionUIBase::AddBackgroundOption()
{
    edit_background_button_ = new QPushButton(this);
    edit_background_button_->setText(NAME_EDIT_BACKGROUND_BUTTON);
    edit_background_button_->setWindowTitle(NAME_EDIT_BACKGROUND_BUTTON);

    //    connect(edit_background_button_,&QPushButton::clicked,this,&OptionUIBase::onEditBackgroundButtonClicked);
    v_layout_->addWidget(edit_background_button_);
    list_selected_options_widget_.push_back(edit_background_button_);

    UpdateLayout();
}

void OptionUIBase::AddIconOption()
{
    edit_icon_button_ = new QPushButton(this);
    edit_icon_button_->setText(NAME_EDIT_ICON_BUTTON);
    edit_icon_button_->setWindowTitle(NAME_EDIT_ICON_BUTTON);

    //    connect(edit_icon_button_,&QPushButton::clicked,this,&OptionUIBase::onEditIconButtonClicked);
    v_layout_->addWidget(edit_icon_button_);
    list_selected_options_widget_.push_back(edit_icon_button_);

    UpdateLayout();
}



void OptionUIBase::UpdateLayout()
{
    this->setLayout(v_layout_);
}





