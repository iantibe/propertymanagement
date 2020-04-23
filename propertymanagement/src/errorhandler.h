#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <string>
#include "error.h"
#include <vector>

using namespace std;

class Errorhandler {
public:
    void saveError(string);
    vector<Error> getErrors();
};

#endif // ERRORHANDLER_H
