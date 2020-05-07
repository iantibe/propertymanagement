#ifndef MESSAGEMENU_H
#define MESSAGEMENU_H

#include "menu.h"
#include "menuitem.h"

class Messagemenu : public Menu {
public:
  Messagemenu(string);
  void display() override;
};

#endif // MESSAGEMENU_H
