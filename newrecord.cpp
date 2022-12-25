#include "newrecord.h"

TNewRecordDialog::TNewRecordDialog() 
    : TDialog(TRect(20, 4, 60, 20), "New Record"),
      TWindowInit(initFrame) {
    
    inputMood = new TInputLine(
        TRect(10, 2, 36, 3), 
        100);
    insert(inputMood);
    
    insert(new TStaticText(
        TRect(3, 2, 9, 3), 
        "Mood: "));

    insert(new TButton(
        TRect(14, 13, 24, 15), 
        "~C~ancel", 
        cmCancel, 
        bfNormal));
    
    insert(new TButton(
        TRect(25, 13, 35, 15), 
        "~N~ext", 
        cmNext, 
        bfNormal));
}

std::string TNewRecordDialog::getMood() {
    char data[101];
    inputMood->getData(data);
    return data;
}
