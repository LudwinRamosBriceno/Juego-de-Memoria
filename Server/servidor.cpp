#include "servidor.h"
#include <tarjeta.h>
#include <buildermatriz.h>
#include <QTcpSocket>
#include <string>
#include <iostream>
#include <splitmensaje.h>
#include <crearArchivoBin.h>

Servidor::Servidor(QObject *parent): QObject(parent){

    manejadorMensajes = new handlerServer();
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

        /* El número 2 indica que el nombre del jugador 1 viene como segundo dato en un mensaje delimitado por
         * comas, donde el interpreteMensaje retornará el dato según la posición que se le indique con un entero*/
        QString nombreJugador1 = interpreteMensaje.interpretarMensaje(2,QString(bufferMensaje));
        QString nombreJugador2 = interpreteMensaje.interpretarMensaje(3,QString(bufferMensaje));
        QString mensaje = manejadorMensajes->iniciarJuego(nombreJugador1,nombreJugador2);
        socket->write(mensaje.toUtf8().constData(),mensaje.size());
    }
    else if (QString(bufferMensaje).contains("finalizar")){
        //manejadorMensajes->finalizarJuego();
        free(manejadorMensajes);
        manejadorMensajes = nullptr;
        server->close();

    } else{
        QString mensajeAenviar = manejadorMensajes->logicHandler(QString(bufferMensaje));
        socket->write(mensajeAenviar.toUtf8().constData(),mensajeAenviar.size());
    }
}
void Servidor::enviar(QString mensaje){
    socket->write(mensaje.toUtf8().constData(),mensaje.size());

}

