#ifndef ERROR_H
#define ERROR_H

#include <ctime>
#include <string>

using namespace std;

class Error {
private:
    string desc;
    time_t time;
public:
    string getDesc();
    time_t getTime();
    void setDesc(string);
    void setTime(time_t);
};

#endif // ERROR_H
