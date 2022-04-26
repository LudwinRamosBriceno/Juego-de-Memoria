#include "socketserver.h"

socketServer::socketServer(QObject *parent): QObject{parent}{
    mensajeCliente = "";
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,2080);
    socket = new QTcpSocket(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(nuevaConexion()));
}

void socketServer::nuevaConexion(){
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(read()));
}

void socketServer::almacenarMensaje(){
    QByteArray bufferMensaje;
    bufferMensaje.resize(socket->bytesAvailable());
    socket->read(bufferMensaje.data(),bufferMensaje.size());
    mensajeCliente = bufferMensaje;
}
QString socketServer::read(){
    return mensajeCliente;
}

void socketServer::limpiarMensaje(){
    mensajeCliente = "";
}
