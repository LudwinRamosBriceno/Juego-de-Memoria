#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class Servidor : public QObject {
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = nullptr);
    void enviar(const QString mensaje);
    void setNombresJugadores();
    void conectar();

private slots:
    void leer_mensaje();
    void conexion_nueva();

private:
    QTcpSocket *socket;
    QTcpServer *server;
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;

signals:

};

#endif // SERVIDOR_H

