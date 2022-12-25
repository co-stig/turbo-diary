#define Uses_TKeys
#define Uses_TEvent
#define Uses_TApplication
#define Uses_TRect
#define Uses_TDialog
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TMenuBar
#define Uses_MsgBox
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#include <tvision/tv.h>
#include "newrecord.h"
#include <string>

class TDiaryApp: public TApplication {
public:
    static const int cmNewRecord = 100, cmNext = 101;
    TDiaryApp();
    static TMenuBar* initMenuBar(TRect);
private:
    virtual void handleEvent(TEvent&);
    virtual bool newRecord();
};

TDiaryApp::TDiaryApp()
: TProgInit(
    &TDiaryApp::initStatusLine,
    &TDiaryApp::initMenuBar,
    &TDiaryApp::initDeskTop
) { }

void TDiaryApp::handleEvent(TEvent& event) {
    TApplication::handleEvent(event);
    if (event.what == evCommand) {
        switch (event.message.command) {
        case cmNewRecord:
            newRecord();
            clearEvent(event);
            break;
        }
    }
}

bool TDiaryApp::newRecord() {
    TNewRecordDialog* dlg = new TNewRecordDialog();
    deskTop->execView(dlg);
    std::string mood = "Mood: " + dlg->getMood();
    messageBox(mood, mfInformation | mfOKButton);
    destroy(dlg);
    return true;
}

TMenuBar* TDiaryApp::initMenuBar(TRect r) {
    TApplication::initMenuBar(r);
    r.b.y = r.a.y + 1;
    return new TMenuBar(r, 
        *new TSubMenu("~F~ile", kbAltF) +
        *new TMenuItem("~N~ew record", cmNewRecord, kbCtrlN) +
        *new TMenuItem("E~x~it", cmQuit, cmQuit, hcNoContext, "Alt-X")
    );
}

int main() {
    TDiaryApp app;
    app.run();
    return 0;
}
