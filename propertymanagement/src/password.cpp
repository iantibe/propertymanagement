#include "password.h"
#include "selectdata.h"

Password::Password(){

}

bool Password::validatePassword(string u, string pw){
    QSqlQuery query;
    query.prepare("select uname, password from user where uname =:uname and password = :password");
    query.bindValue(":uname", u.c_str() );
    query.bindValue(":password", pw.c_str());

    if(query.exec()){
        if(query.next()){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}


