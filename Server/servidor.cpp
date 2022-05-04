#include "servidor.h"
#include <tarjeta.h>
#include <buildermatriz.h>
#include <QTcpSocket>
#include <string>
#include <iostream>
#include <splitmensaje.h>
#include <crearArchivoBin.h>
#include <QTimer>
#include <QCoreApplication>
#include <socketserver.h>
#include <QDebug>
using namespace std;

Servidor::Servidor(QObject *parent): QObject(parent){

}

Servidor::Servidor(socketServer* server){
    manejadorMensajes = new handlerServer();
    socketserver = server;
    finalizarJuego = false;
    mensajeCliente = "";
}

void Servidor::abrirConexion(){
    while(!finalizarJuego){
        mensajeCliente = socketserver->read();
        if(mensajeCliente!=""){
            leer_mensaje();
            socketserver->limpiarMensaje();
        }
    }
}

bool Servidor::leer_mensaje(){
    splitMensaje interpreteMensaje;
    mensajeCliente = socketserver->read();
    if (mensajeCliente.contains("iniciar")){

        /* El número 2 indica que el nombre del jugador 1 viene como segundo dato en un mensaje delimitado por
         * comas, donde el interpreteMensaje retornará el dato según la posición que se le indique con un entero*/
        QString nombreJugador1 = interpreteMensaje.interpretarMensaje(2,QString(mensajeCliente));
        QString nombreJugador2 = interpreteMensaje.interpretarMensaje(3,QString(mensajeCliente));
        //QString mensaje = manejadorMensajes->iniciarJuego(nombreJugador1,nombreJugador2);
        //socket->write(mensaje.toUtf8().constData(),mensaje.size());
        return true;

    }
    else if (mensajeCliente.contains("finalizar")){
        if (mensajeCliente.contains("close")){/*server->close();server=nullptr;*/free(socket);QCoreApplication::quit();}
        else{
            QString mensaje = manejadorMensajes->finalizarJuego();
            socket->write(mensaje.toUtf8().constData(),mensaje.size());
            free(manejadorMensajes);
            manejadorMensajes = nullptr;
            return true;
        }
    } else{
        QString mensajeAenviar = manejadorMensajes->logicHandler(mensajeCliente);
        //socket->write(mensajeAenviar.toUtf8().constData(),mensajeAenviar.size());
        if (mensajeCliente.contains("segundaTarjeta")){
            QTimer::singleShot(1000,this,SLOT(enviarCambioTurno()));
            return true;
        }else if(mensajeCliente.contains("primeraTarjeta")){
            return true;
        }
    }
    return false;
}
void Servidor::enviarCambioTurno(){
    QString mensajeAenviar = manejadorMensajes->getResultadoJuego();
    socket->write(mensajeAenviar.toUtf8().constData(),mensajeAenviar.size());
}

