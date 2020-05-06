#include "maintenancehandler.h"
#include "selectdata.h"

vector<Maintenancerequest> Maintanancehandler::getCurrentRequests(){

}

void Maintanancehandler::compleateRequest(Maintenancerequest &){

}

void Maintanancehandler::submitRequest(Maintenancerequest & mr, int rentalunitid){
    QSqlQuery query;
    query.prepare("insert into maintenancerequest (rentalunitid, isdone, time, desc, requesttypeid) values(?,?,?,?,?)");
    query.addBindValue(rentalunitid);
    query.addBindValue(0); //0 is not done, 1 is done
    query.addBindValue(mr.getTime());
    query.addBindValue(mr.getDescription().c_str());
    query.addBindValue(mr.getRequestType());
    query.exec();
    qDebug() << query.lastError();
}

Maintanancehandler::Maintanancehandler(){

}

vector<Maintenancerequest> Maintanancehandler::getTenantUnfinishedRequests(Tenantuser & u){
    Selectdata selectdata;
    vector<Maintenancerequest> list;
    int rentalunitid = selectdata.getRentalunitIdbyTenant(u);
    QSqlQuery query;
    query.prepare("select time, desc, requesttypeid from maintenancerequest where rentalunitid = :ruid and isdone = :isdone");
    query.bindValue(":ruid", rentalunitid);
    query.bindValue(":isdone", 0);
    query.exec();

    while (query.next()){
       Rentalunit rentalunit("","",false,false,false,0,0,0,0,false);
        class Tenant tenant(u,rentalunit);
        QString des = query.value(1).toString();
        Maintenancerequest mr(tenant,query.value(0).toLongLong(),query.value(2).toULongLong(),des.toStdString());
        list.push_back(mr);
    }
    return list;
}

vector<Maintenancerequest> Maintanancehandler::getTenantFinishedRequests(Tenantuser & u){
    Selectdata selectdata;
    vector<Maintenancerequest> list;
    int rentalunitid = selectdata.getRentalunitIdbyTenant(u);
    QSqlQuery query;
    query.prepare("select time, desc, requesttypeid from maintenancerequest where rentalunitid = :ruid and isdone = :isdone");
    query.bindValue(":ruid", rentalunitid);
    query.bindValue(":isdone", 1);
    query.exec();

    while (query.next()){
       Rentalunit rentalunit("","",false,false,false,0,0,0,0,false);
        class Tenant tenant(u,rentalunit);
        QString des = query.value(1).toString();
        Maintenancerequest mr(tenant,query.value(0).toLongLong(),query.value(2).toULongLong(),des.toStdString());
        list.push_back(mr);
    }
    return list;
}


string Maintanancehandler::getMaintenanceTypeById(int id){
    QSqlQuery query;
    query.prepare("select type from requesttype where requesttypeid = :requesttypeid");
    query.bindValue(":requesttypeid", id);
    query.exec();
    query.next();
    QString item = query.value(0).toString();
    return item.toStdString();
}
