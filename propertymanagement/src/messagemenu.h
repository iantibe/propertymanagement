#ifndef MESSAGEMENU_H
#define MESSAGEMENU_H

#include "menu.h"
#include "menuitem.h"

class Messagemenu : public Menu {
public:
  vector<Menuitem> buildMessageMenu();
  Messagemenu(string);
  void display() override;
};

#endif // MESSAGEMENU_H
