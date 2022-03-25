#include <QCoreApplication>
#include <servidor.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Servidor server;
    server.conectar();

    return a.exec();
}
