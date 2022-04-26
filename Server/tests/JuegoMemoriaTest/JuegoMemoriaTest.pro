QT -= gui
QT+= network

INCLUDEPATH += /path/to/ncurses/headers/
LIBS += -L/path/to/ncurses/library/ -lncurses
LIBS += -lgtest -lpthread

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += "gtest/mocks/include"
INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../../"

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../actualizardatosjugadores.cpp \
        ../../buildermatriz.cpp \
        ../../buscadorTarjeta.cpp \
        ../../cargardescargartarjeta.cpp \
        ../../crearArchivoBin.cpp \
        ../../handlerserver.cpp \
        ../../imgtarjetas.cpp \
        ../../informacioncliente.cpp \
        ../../matrizpaginada.cpp \
        ../../operadormatrizpaginada.cpp \
        ../../powerups.cpp \
        ../../registroserver.cpp \
        ../../resultadojuego.cpp \
        ../../servidor.cpp \
        ../../socketserver.cpp \
        ../../splitmensaje.cpp \
        ../../sumadorPuntos.cpp \
        ../../tarjeta.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../actualizardatosjugadores.h \
    ../../buildermatriz.h \
    ../../buscadorTarjeta.h \
    ../../cargardescargartarjeta.h \
    ../../crearArchivoBin.h \
    ../../handlerserver.h \
    ../../imgtarjetas.h \
    ../../informacioncliente.h \
    ../../matrizpaginada.h \
    ../../operadormatrizpaginada.h \
    ../../powerups.h \
    ../../registroserver.h \
    ../../resultadojuego.h \
    ../../servidor.h \
    ../../socketserver.h \
    ../../splitmensaje.h \
    ../../sumadorPuntos.h \
    ../../tarjeta.h
