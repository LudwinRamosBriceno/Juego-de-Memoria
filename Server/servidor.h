#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class Servidor : public QObject
{
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = nullptr);
    void enviar(const QString mensaje);
    void setNombresJugadores();
    void conectar();

private slots:
    void leer_mensaje();
    void conexion_nueva();
    QString splitMensajes(int indiceDato,QString mensaje_a_separar);

private:
    QTcpSocket *socket;
    QTcpServer *server;
    matrizpaginada *matrizTarjetasCargadas;
    informacioncliente *cliente;

signals:

};

#endif // SERVIDOR_H

