QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    handlercliente.cpp \
    identificadortarjetas.cpp \
    main.cpp \
    game.cpp \
    splitmensaje.cpp

HEADERS += \
    game.h \
    handlercliente.h \
    identificadortarjetas.h \
    splitmensaje.h

FORMS += \
    game.ui

TRANSLATIONS += \
    JuegoMemoria_es_419.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc
