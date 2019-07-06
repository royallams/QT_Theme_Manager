#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->plainTextEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->pushButton->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->checkBox->setContextMenuPolicy(Qt::CustomContextMenu);


    QString path = "E:/Default.qss";
    test_style_mgr_= new QtThemeManager(path,kDefaultPath);
    connect(test_style_mgr_,&QtThemeManager::styleSheetUpdated,this,&MainWindow::onStyleSheetUpdated);
    connect(test_style_mgr_,&QtThemeManager::notify,this,&MainWindow::onNotify);

    test_style_mgr_->Update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString object_name =ui->pushButton->objectName();
    test_style_mgr_->InvokeEditOption(kPushButton,object_name);
}

void MainWindow::on_checkBox_clicked()
{
    QString object_name =ui->checkBox->objectName();
    test_style_mgr_->InvokeEditOption(kCheckBox,object_name);
}

void MainWindow::on_Edit_Dialog_clicked()
{
    QString object_name =ui->centralWidget->objectName();
    test_style_mgr_->InvokeEditOption(kWidget,object_name);
}


void MainWindow::on_PlainTextEdit_Style()
{
    QString object_name =ui->plainTextEdit->objectName();
    test_style_mgr_->InvokeEditOption(kPlainTextEdit,object_name);
}

void MainWindow::onStyleSheetUpdated(QString &ss)
{
    ui->centralWidget->setStyleSheet(ss);
    QString mesg="New StyleSheet updated- ";
    ui->plainTextEdit->appendPlainText(mesg);
    ui->plainTextEdit->appendPlainText(ss);


}

void MainWindow::onNotify(QString &mesg)
{

    ui->plainTextEdit->appendPlainText(mesg);

}

void MainWindow::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr(NAME_CONTEXT_MENU_TITLE), this);
    QAction action(NAME_CONTEXT_MENU_EDIT_THEME, this);
    connect(&action, SIGNAL(triggered()), this, SLOT(on_PlainTextEdit_Style()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_pushButton_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr(NAME_CONTEXT_MENU_TITLE), this);
    QAction action(NAME_CONTEXT_MENU_EDIT_THEME, this);
    connect(&action, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_checkBox_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr(NAME_CONTEXT_MENU_TITLE), this);
    QAction action(NAME_CONTEXT_MENU_EDIT_THEME, this);
    connect(&action, SIGNAL(triggered()), this, SLOT(on_checkBox_clicked()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr(NAME_CONTEXT_MENU_TITLE), this);
    QAction action(NAME_CONTEXT_MENU_EDIT_THEME, this);
    connect(&action, SIGNAL(triggered()), this, SLOT(on_Edit_Dialog_clicked()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}
