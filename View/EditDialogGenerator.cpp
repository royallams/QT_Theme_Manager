#include "EditDialogGenerator.h"

OptionUIBase* EditDialogGenerator::CreateUI(kClassType qt_class_type)
{

    switch (qt_class_type) {
    case kPushButton:
        return (new OptionUIPushButton);
        break;
    case kCheckBox:
        return (new OptionUICheckBox);
        break;
    case kDialog:
        return (new OptionUIDialog);
        break;
    case kPlainTextEdit:
        return (new OptionUIPlainTextEdit);
        break;
    case kWidget:
        return (new OptionUIWidget);
        break;
    default:
        return NULL;
        break;
    }
}
