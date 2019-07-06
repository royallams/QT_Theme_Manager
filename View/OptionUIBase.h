#ifndef OPTIONUIBASE_H
#define OPTIONUIBASE_H

#include "QDialog"
#include "QLayout"
#include "QPushButton"
#include "globaldefines.h"

class OptionUIBase:public QDialog
{
    Q_OBJECT
public :
    explicit OptionUIBase();
    void Display(){
        this->exec();
    }

    void CreateCentralWidget();
    void AddColorOption();
    void AddBackgroundOption();
    void AddIconOption();

    //    virtual QString PrepareSSForPreview();

public:
    QPushButton *preview_button_;
    QPushButton *reset_button_;
    QPushButton *apply_button_;
    QPushButton *export_to_file_button_;

    QList<QWidget*>list_selected_options_widget_;

private:
    void UpdateLayout();


    QPushButton *edit_color_button_;
    QPushButton *edit_background_button_;
    QPushButton *edit_icon_button_;
    QVBoxLayout *v_layout_;



};


#endif // OPTIONUIBASE_H
