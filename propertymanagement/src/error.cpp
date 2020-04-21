#include "error.h"

void Error::addError(string e){
    Insertdata instance;
    instance.saveError(e.c_str());
}
