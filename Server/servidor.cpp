#include "servidor.h"
#include <tarjeta.h>
#include <buildermatriz.h>
#include <QTcpSocket>
#include <string>
#include <iostream>

Servidor::Servidor(QObject *parent)
    : QObject(parent)
{
    matrizTarjetasCargadas = new matrizpaginada();
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

    QByteArray bufferMensaje;
    bufferMensaje.resize(socket->bytesAvailable()); // indica el tamaño de la información enviada.
    socket->read(bufferMensaje.data(),bufferMensaje.size()); // se guarda la información en bufferMensaje.

    if (QString(bufferMensaje).contains("iniciar")){
        builderMatriz *constructorMatriz = new builderMatriz();
        tarjeta* construccionMatrizPaginada = constructorMatriz->construirMatriz();
        matrizTarjetasCargadas->setTarjetasCargadas(construccionMatrizPaginada);
        cliente->setNombreJugador1(splitMensajes(2,QString(bufferMensaje)));
        cliente->setNombreJugador2(splitMensajes(3,QString(bufferMensaje)));

        //socket->write(mensaje.toUtf8().constData(),mensaje.size());
    }
}

// busqueda de un dato en conjunto datos delimitados con comas, que provienen del mensaje del cliente.
QString Servidor::splitMensajes(int indiceDato,QString mensaje_a_separar){
    QString dato ="";
    char separadorDatos = ',';
    int contadorDatos =1;
    for(int i=0;i<mensaje_a_separar.length();i++){
        if (mensaje_a_separar[i]==separadorDatos && contadorDatos==indiceDato){
            return dato;

        }else if(mensaje_a_separar[i]==separadorDatos){
            dato = "";
            contadorDatos++;

        }else{
            dato+=mensaje_a_separar[i];
        }
    }
    return dato;
}
