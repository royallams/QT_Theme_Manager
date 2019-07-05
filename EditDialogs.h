#ifndef BASECLASSUI_H
#define BASECLASSUI_H
#include "QDialog"
#include "QLayout"
#include "QPushButton"
#include "GlobalNames.h"
#include "QMessageBox"
#include "QColorDialog"

class BaseUI:public QDialog
{
    Q_OBJECT
 public :
    explicit BaseUI();
    void Display(){
        this->exec();
    }


    void CreateCentralWidget();
    void AddColorOption();
    void AddBackgroundOption();
    void AddIconOption();

//    virtual QString PrepareSSForPreview();


 private slots:
    void onEditColorButtonClicked();
    void onEditBackgroundButtonClicked();
    void onEditIconButtonClicked();



 public:
    QPushButton *preview_button_;
    QPushButton *reset_button_;
    QPushButton *apply_button_;
    QList<QWidget*>list_selected_options_widget_;

 private:
    void UpdateLayout();


    QPushButton *edit_color_button_;
    QPushButton *edit_background_button_;
    QPushButton *edit_icon_button_;
    QVBoxLayout *v_layout_;

public:
    QColor color_;
    QColor background_color_;


};


class EditPushButtonUI:public BaseUI
{
public:
     EditPushButtonUI();
  };


class EditDialogUI:public BaseUI
{
public:
    EditDialogUI();

 };

class EditCheckBoxUI:public BaseUI
{
public:
    EditCheckBoxUI();

 };




#endif // BASECLASSUI_H
