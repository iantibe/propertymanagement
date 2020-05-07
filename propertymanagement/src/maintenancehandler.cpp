#include "maintenancehandler.h"
#include "selectdata.h"

void Maintanancehandler::submitRequest(Maintenancerequest & mr, int rentalunitid){
    QSqlQuery query;
    query.prepare("insert into maintenancerequest (rentalunitid, isdone, time, desc, requesttypeid) values(?,?,?,?,?)");
    query.addBindValue(rentalunitid);
    query.addBindValue(0); //0 is not done, 1 is done
    query.addBindValue(mr.getTime());
    query.addBindValue(mr.getDescription().c_str());
    query.addBindValue(mr.getRequestType());
    query.exec();
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

void Maintanancehandler::updateMaintenanceRequest(int maintenancerequestid){
    QSqlQuery query;
    query.prepare("update maintenancerequest set isdone = :isdone where maintenancerequestid = :mrid");
    //value of 1 in isdone marks as finished
    query.bindValue(":isdone", 1);
    query.bindValue(":mrid", maintenancerequestid);
    query.exec();
}

vector<Maintenancerequest> Maintanancehandler::getMaintenanceRequestsByRentalunitId(int rentalunitid){
    vector<Maintenancerequest> list;
    QSqlQuery query;
    Tenantuser user(0,"","");
    Rentalunit rentalunit("","",false,false,false,0,0,0,0,false);
    class Tenant tenant(user, rentalunit);
    query.prepare("select time, desc, requesttypeid, maintenancerequestid from maintenancerequest where rentalunitid = :runit and isdone = :isdone");
    query.bindValue(":runit" , rentalunitid);
    //value of zero in isdone marks as unfinished
    query.bindValue(":isdone", 0);
    query.exec();
    while(query.next()){
        QString  desc = query.value(1).toString();
        Maintenancerequest mr(tenant,query.value(0).toULongLong(), query.value(2).toULongLong(), desc.toStdString());
        mr.setMaintenancerequestid(query.value(3).toULongLong());
        list.push_back(mr);
    }
    return list;
}


