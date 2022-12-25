#define Uses_TRect
#define Uses_TDialog
#define Uses_TButton
#define Uses_TInputLine
#define Uses_TStaticText
#include <tvision/tv.h>
#include <string>

class TNewRecordDialog: public TDialog {
public:
    TNewRecordDialog();
    std::string getMood();

private:
    TInputLine* inputMood;
};
