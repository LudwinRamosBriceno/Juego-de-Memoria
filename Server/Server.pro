QT -= gui
QT+= network
CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        buildermatriz.cpp \
        crearArchivoBin.cpp \
        imgtarjetas.cpp \
        informacioncliente.cpp \
        main.cpp \
        matrizpaginada.cpp \
        servidor.cpp \
        splitmensaje.cpp \
        tarjeta.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    buildermatriz.h \
    crearArchivoBin.h \
    imgtarjetas.h \
    informacioncliente.h \
    matrizpaginada.h \
    servidor.h \
    splitmensaje.h \
    tarjeta.h
