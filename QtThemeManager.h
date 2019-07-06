#ifndef QTTHEMEMANAGER_H
#define QTTHEMEMANAGER_H
#include "QObject"
#include "globaldefines.h"
#include "Controller.h"
#include "QFileInfo"

class Controller;

/*!
 * \class [QtThemeManager]
 *
 * \brief This Class acts as an interface to the User. It provides API to use this manager to make stylesheet changes to any
 * QT Widget related projects.
 * \author [Royal B.K]
 * \date 06/07/19
 */

class QtThemeManager: public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief  This constructor creates a controller which in turn prepares a model with the same invokation.
     * [param 1]- Default Style Sheet file path to use for styling the GUI.
     * [param 2]- This parameter decides whether to take the previous Stylesheet for use or take the default file path instead.
     */
    explicit QtThemeManager(QString &style_sheet_path_to_use, kStyleSheetPathType path_type= kPreviousPath);

    /*!
     * \brief  This function creates an edit option dialog dynamically based on the Qt Class type. Meaning differnt options
     * for differnt dialog.
     * [param 1]- This input is the type of Class for which the Edit option Dialog is required.
     * [param 2]- This is the name of object for which the stylesheet is required. This will be used in the stylesheet to generate specific object related stylesheet.
     *
     */
    void InvokeEditOption(kClassType class_type, QString &object_name);

    /*!
     * \brief  This function is used to update the stylesheet with the default file data and send a signal that
     * emits the stylesheet data to the user.
     */
    void Reset();

    /*!
     * \brief  This function is used to update the stylesheet with the  file data depending on  kStyleSheetPathType as mentioned by the user  and send a signal that
     * emits the stylesheet data to the user.
     */
    void Update();
signals:

    /*!
     * \brief  This signal gets emitted whenever there is stylesheet changes and may want to update the user with the latest StyleSheet data.
     */
    void styleSheetUpdated(QString &stylesheet);

    /*!
     * \brief  This signal is used to notify the user with any messages related to errors or stages.
     */
    void notify(QString &messages);


private:
    Controller *controller_;

};

#endif // QTTHEMEMANAGER_H

