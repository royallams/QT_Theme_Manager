#ifndef GLOBALDEFINES
#define GLOBALDEFINES

#ifndef GLOBALNAMES
#define GLOBALNAMES

#include "QMessageBox"

#define NAME_EDIT_COLOR_BUTTON "Edit Color"
#define NAME_EDIT_BACKGROUND_BUTTON "Edit background"
#define NAME_EDIT_ICON_BUTTON "Edit Icon"
#define NAME_RESET_BUTTON "Reset"
#define NAME_APPLY_BUTTON "Apply"
#define NAME_PREVIEW_BUTTON "Preview"
#define NAME_EXPORT_BUTTON "Export To File"

#define CLASS_NAME_UNKNOWN "Unknown"
#define CLASS_NAME_PUSH_BUTTON "QPushButton"
#define CLASS_NAME_CHECK_BOX "QCheckBox"
#define CLASS_NAME_PLAIN_TEXT_EDIT "QPlainTextEdit"
#define CLASS_NAME_DIALOG "QDialog"
#define CLASS_NAME_LABEL "QLabel"
#define CLASS_NAME_WIDGET "QWidget"


#define NAME_CONTEXT_MENU_EDIT_THEME "Edit Theme"
#define NAME_CONTEXT_MENU_TITLE "Context Menu"

enum  kClassType{
    kPushButton,
    kDialog,
    kTreeWidget,
    kCheckBox,
    kPlainTextEdit,
    kLabel,
    kWidget,
    kInvalid
};

enum  kStyleSheetPathType{
    kDefaultPath,
    kPreviousPath,
};


#endif // GLOBALNAMES




#endif // GLOBALDEFINES

