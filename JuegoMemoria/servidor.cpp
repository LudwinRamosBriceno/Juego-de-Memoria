#include "servidor.h"
#include <QTcpSocket>

Servidor::Servidor(QObject *parent)
    : QTcpServer(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,2080);
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(newConnection()),this,SLOT(conexion_nueva()));

}
void Servidor::conexion_nueva(){

    socket = server->nextPendingConnection();

}

