#include "menu.h"
#include <iostream>
#include <cctype>

void Menu::drawmenu(vector<Menuitem> list){

}

int Menu::selection(int sel){
    bool exitFlag = false;
    string preCheckedEntry;
    int postCheckedEntry;
    bool isDigitFlag = true;

    while(!exitFlag){
        cout << "Enter Selection: ";
        cin >> preCheckedEntry;

        for(int i = 0; i < preCheckedEntry.size(); i++){
            if(isdigit(preCheckedEntry[i]) == false){
                isDigitFlag = false;
            }
        }

        if(!isDigitFlag){
         cout << "Please enter a number between 1 and " << sel;
         isDigitFlag = true;
        } else {
            postCheckedEntry = atoi(preCheckedEntry.c_str());

            if(postCheckedEntry >= 0 and postCheckedEntry <= sel){
                exitFlag = true;
            }else {
                cout << "Please enter a number between 1 and " << sel;
            }
        }
     }

    return postCheckedEntry;
}

string Menu::getTitle(){
    return title;
}

void Menu::setTitle(string t){
    this->title = t;
}

Menu::Menu(string t){
    this->title = t;
}
