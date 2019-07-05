#include "EditDialogGenerator.h"

BaseUI* EditDialogGenerator::CreateUI(kClassType qt_class_type)
{

    switch (qt_class_type) {
    case kPushButton:
        return (new EditPushButtonUI);
        break;
    case kCheckBox:
        return (new EditCheckBoxUI);
        break;
    default:
        break;
    }
}
