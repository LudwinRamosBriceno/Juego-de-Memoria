#include "servidor.h"
#include <QTcpSocket>
#include <string>
#include <iostream>

Servidor::Servidor(QObject *parent)
    : QObject(parent)
{
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

    QByteArray bufferMensaje;
    bufferMensaje.resize(socket->bytesAvailable()); // indica el tamaño de la información enviada.
    socket->read(bufferMensaje.data(),bufferMensaje.size()); // se guarda la información en bufferMensaje.

    if (QString(bufferMensaje).contains("iniciar")){
        qDebug()<<"si";
        //QString mensaje ="nombres";
        //socket->write(mensaje.toUtf8().constData(),mensaje.size());
    }
    qDebug()<<"no";
}

void Servidor::setNombresJugadores(){

}
