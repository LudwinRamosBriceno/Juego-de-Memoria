#include <QCoreApplication>
#include <servidor.h>
#include <QDebug>
#include <socketserver.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    socketServer *socketserver = new socketServer();
    Servidor server = Servidor(socketserver);
    server.nuevaConexion();

    return a.exec();
}
