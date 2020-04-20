QT -= gui
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        accessscreen.cpp \
        adminmenu.cpp \
        adminuser.cpp \
        building.cpp \
        databaseconnection.cpp \
        insertdata.cpp \
        landlordmenu.cpp \
        landlorduser.cpp \
        loginout.cpp \
        loginscreen.cpp \
        logoutscreen.cpp \
        main.cpp \
        maintenancehandler.cpp \
        maintenancerequest.cpp \
        menu.cpp \
        menuitem.cpp \
        message.cpp \
        messagehandler.cpp \
        messagemenu.cpp \
        password.cpp \
        rent.cpp \
        rentaction.cpp \
        rentalunit.cpp \
        selectdata.cpp \
        session.cpp \
        tenant.cpp \
        tenantmenu.cpp \
        tenantuser.cpp \
        updatedata.cpp \
        user.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    accessscreen.h \
    adminmenu.h \
    adminuser.h \
    building.h \
    constants.h \
    databaseconnection.h \
    insertdata.h \
    landlordmenu.h \
    landlorduser.h \
    loginout.h \
    loginscreen.h \
    logoutscreen.h \
    maintenancehandler.h \
    maintenancerequest.h \
    menu.h \
    menuitem.h \
    message.h \
    messagehandler.h \
    messagemenu.h \
    password.h \
    rent.h \
    rentaction.h \
    rentalunit.h \
    selectdata.h \
    session.h \
    tenant.h \
    tenantmenu.h \
    tenantuser.h \
    updatedata.h \
    user.h \
    usertype.h
