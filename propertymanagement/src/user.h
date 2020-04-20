#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {

private:
    string fname;
    string lname;
    int userid;
public:
    void setFname(string fname);
    void setLname(string lname);
    void setUserid(int uid);
    string getFname();
    string getLname();
    int getUserid();
    User(int, string, string);
    ~User();
};

#endif // USER_H
