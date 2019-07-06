#ifndef EDITDIALOGGENERATOR_H
#define EDITDIALOGGENERATOR_H
#include "OptionUICheckBox.h"
#include "OptionUIDialog.h"
#include "OptionUIPushButton.h"
#include "OptionUIPlainTextEdit.h"
#include "OptionUIWidget.h"

class EditDialogGenerator
{
public:
    explicit EditDialogGenerator(){}

    OptionUIBase * Create(kClassType specify_qt_class_type= kInvalid)
    {
        if(specify_qt_class_type== kInvalid)
        {
            //Take this as priority
            return NULL;
        }

        //Take whatever previously specified class as input
        return CreateUI(specify_qt_class_type);


    }


private:
    OptionUIBase *CreateUI(kClassType qt_class_type);


};

#endif // EDITDIALOGGENERATOR_H
