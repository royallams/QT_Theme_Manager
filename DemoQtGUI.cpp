#include "DemoQtGUI.h"
#include "ui_dialog.h"
#include "StyleManager.h"

DemoQtGUI::DemoQtGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QString path = "E:/test.qss";
    test_style_mgr_= new StyleManager(path);
    connect(test_style_mgr_,&StyleManager::styleSheetUpdated,this,&DemoQtGUI::onStyleSheetUpdated);

}

DemoQtGUI::~DemoQtGUI()
{
    delete ui;
}

void DemoQtGUI::on_pushButton_clicked()
{
//        StyleManager test_style_mgr(QString::fromStdString("E:/test.qss"));
//        test_style_mgr.InvokeEditOption(kPushButton,ui->pushButton->text());
    QString object_name =ui->pushButton->objectName();
    test_style_mgr_->InvokeEditOption(kPushButton,object_name);

}

void DemoQtGUI::on_checkBox_clicked()
{
//        StyleManager test_style_mgr(QString::fromStdString("E:/test.qss"));
//        test_style_mgr.InvokeEditOption(kCheckBox,ui->pushButton->text());
    QString object_name =ui->checkBox->objectName();
    test_style_mgr_->InvokeEditOption(kCheckBox,object_name);
}

void DemoQtGUI::onStyleSheetUpdated(QString &ss)
{
    this->setStyleSheet(ss);

}
