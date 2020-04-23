#include "errorhandler.h"
#include "Databaseconnection.h"

void Errorhandler::saveError(string e){
    QSqlQuery query;
    time_t t = time(0);
    query.prepare("insert into errortable (desc, time) values(:desc, :time)");
    query.bindValue(":desc",e.c_str());
    query.bindValue(":time", t);
    query.exec();

}

vector<Error> Errorhandler::getErrors(){
    vector<Error> list;
    Error error;
    QSqlQuery query;
    query.prepare("select desc, time from errortable");
    query.exec();

    while (query.next()) {
        QString desc = query.value(0).toString();
        error.setDesc(desc.toStdString());
        error.setTime(query.value(1).toULongLong());
        list.push_back(error);
    }

    return list;
}
