#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtThemeManager.h"
#include "QMessageBox"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onStyleSheetUpdated(QString &ss);
    void onNotify(QString &mesg);
    void on_PlainTextEdit_Style();
    void on_Edit_Dialog_clicked();
private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked();

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_customContextMenuRequested(const QPoint &pos);

    void on_checkBox_customContextMenuRequested(const QPoint &pos);

    void on_MainWindow_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QtThemeManager *test_style_mgr_;

};

#endif // MAINWINDOW_H
