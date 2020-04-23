#include "error.h"

string Error::getDesc(){
    return desc;
}

time_t Error::getTime(){
    return time;
}

void Error::setDesc(string d){
    this->desc = d;
}

void Error::setTime(time_t t){
    this->time = t;
}
