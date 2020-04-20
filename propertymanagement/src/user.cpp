#include "user.h"

string User::getFname(){
    return fname;
}

string User::getLname(){
    return lname;
}

int User::getUserid(){
    return userid;
}

void User::setFname(string fname){
    this->fname = fname;
}

void User::setLname(string lname){
    this->lname = lname;
}

void User::setUserid(int uid){
    this->userid = uid;
}

User::User(int id, string fnam, string lnam){
    this->userid = id;
    this->fname = fnam;
    this->lname = lnam;
}

User::~User(){

}


