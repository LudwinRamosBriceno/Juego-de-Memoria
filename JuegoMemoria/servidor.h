#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QTcpServer>
#include <QTcpSocket>

class QTcpSocket;

class Servidor :public QTcpServer {
    Q_OBJECT
public:
    explicit Servidor(QObject *parent =0);
    void enviar(const QString mensaje);
private slots:
    void conexion_nueva();

private:
    QTcpSocket *socket;
    QTcpServer *server;
};

#endif // SERVIDOR_H
