#ifndef DemoQtGUI_H
#define DemoQtGUI_H

#include <QDialog>
#include "StyleManager.h"

namespace Ui {
class Dialog;
}

class DemoQtGUI : public QDialog
{
    Q_OBJECT

public:
    explicit DemoQtGUI(QWidget *parent = 0);
    ~DemoQtGUI();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_clicked();


public slots:
    void onStyleSheetUpdated(QString &ss);
private:
    Ui::Dialog *ui;
    StyleManager *test_style_mgr_;
};

#endif // DemoQtGUI_H
