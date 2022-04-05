#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <handlerserver.h>

class Servidor : public QObject {
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = nullptr);
    void enviar(const QString mensaje);
    void conectar();

private slots:
    void leer_mensaje();
    void conexion_nueva();

private:
    QTcpSocket *socket;
    QTcpServer *server;
    handlerServer *manejadorMensajes;

signals:

};

#endif // SERVIDOR_H

