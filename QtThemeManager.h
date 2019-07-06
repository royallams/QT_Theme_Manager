#ifndef QTTHEMEMANAGER_H
#define QTTHEMEMANAGER_H
#include "QObject"
#include "globaldefines.h"
#include "Controller.h"
#include "QFileInfo"

class Controller;

class QtThemeManager: public QObject
{
    Q_OBJECT
public:
    explicit QtThemeManager(QString &style_sheet_path_to_use, kStyleSheetPathType path_type= kLatestPath);
    void InvokeEditOption(kClassType class_type, QString &object_name);
    void Reset();
    void Update();
signals:
    void styleSheetUpdated(QString &stylesheet);
    void notify(QString &messages);


private:
    Controller *controller_;

};

#endif // QTTHEMEMANAGER_H

