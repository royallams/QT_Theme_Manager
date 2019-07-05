#ifndef EDITDIALOGGENERATOR_H
#define EDITDIALOGGENERATOR_H
#include "EditDialogs.h"

class EditDialogGenerator
{
 public:
   explicit EditDialogGenerator(kClassType specify_qt_class_type= kInvalid)
   {
       qt_class_type_ = specify_qt_class_type;
   }


    BaseUI * Invoke(kClassType specify_qt_class_type= kInvalid)
   {
        if(specify_qt_class_type!= kInvalid)
       {
            //Take this as priority
             return CreateUI(specify_qt_class_type);
        }
       else
       {
           //Take whatever previously specified class as input
       }
   }


 private:
   static BaseUI* CreateUI(kClassType qt_class_type);
   kClassType qt_class_type_;


};

#endif // EDITDIALOGGENERATOR_H
