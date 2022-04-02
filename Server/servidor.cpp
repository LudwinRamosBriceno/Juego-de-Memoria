#include "servidor.h"
#include <tarjeta.h>
#include <buildermatriz.h>
#include <QTcpSocket>
#include <string>
#include <iostream>
#include <splitmensaje.h>

Servidor::Servidor(QObject *parent): QObject(parent){

    matrizPaginada = new matrizpaginada();
    cliente = new informacioncliente();
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,2080);
    socket = new QTcpSocket(this);

    //connect(socket,SIGNAL(newConnection()),this,SLOT(conexion_nueva()));
}
void Servidor::conectar(){
    connect(server,SIGNAL(newConnection()),this,SLOT(conexion_nueva()));
}
void Servidor::conexion_nueva(){

    //bool cerrarConexion = false;
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(leer_mensaje()));

}
void Servidor::leer_mensaje(){

    splitMensaje interpreteMensaje;
    QByteArray bufferMensaje;
    bufferMensaje.resize(socket->bytesAvailable()); // indica el tamaño de la información enviada.
    socket->read(bufferMensaje.data(),bufferMensaje.size()); // se guarda la información en bufferMensaje.

    if (QString(bufferMensaje).contains("iniciar")){

        builderMatriz constructorMatriz;

        tarjeta* construccionMatrizPaginada = constructorMatriz.construirMatriz();// se construye la matrizPaginada
        matrizPaginada->setTarjetasCargadas(construccionMatrizPaginada); /* se envia la matriz paginada a
                                                                                   a la clase matriz paginada*/
        cliente->setNombreJugador1(interpreteMensaje.interpretarMensaje(2,QString(bufferMensaje)));
        cliente->setNombreJugador2(interpreteMensaje.interpretarMensaje(3,QString(bufferMensaje)));
        cliente->setPuntajeJugador1(0);
        cliente->setPuntajeJugador1(0);
        cliente->setparTarjetasReveladasJugador1(0);
        cliente->setparTarjetasReveladasJugador1(0);
        qDebug()<<cliente->getNombreJugador1();
        //socket->write(mensaje.toUtf8().constData(),mensaje.size());
    }
}

