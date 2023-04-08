QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    controllers/combustible.controller.cpp \
    controllers/customer.controller.cpp \
    controllers/employee.controller.cpp \
    controllers/tank.controller.cpp \
    dbconnection/databasemanager.cpp \
    models/combustible.model.cpp \
    models/customer.model.cpp \
    models/employee.model.cpp \
    models/tank.model.cpp \
    settings/settings.cpp \
    auth/login.cpp \
    auth/user.cpp

HEADERS += \
    mainwindow.h \
    controllers/combustible.controller.h \
    controllers/customer.controller.h \
    controllers/employee.controler.h \
    controllers/tank.controller.h \
    dbconnection/databasemanager.h \
    models/combustible.model.h \
    models/customer.model.h \
    models/employee.model.h \
    models/tank.model.h \
    settings/settings.h \
    auth/login.h \
    auth/user.h

FORMS += \
    mainwindow.ui \
    auth/login.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
