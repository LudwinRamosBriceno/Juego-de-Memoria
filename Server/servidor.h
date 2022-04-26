/**
 * @file resultadojuego.h
 * @version 1.0
 * @date 22/04/2022
 * @author Ludwin Ramos
 * @brief Gestiona la principal lógica del servidor
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <handlerserver.h>
#include <socketserver.h>

/**
 * @brief The Servidor class Gestiona las conexiones con el cliente y la principal lógica del servidor
 */
class Servidor : public QObject {
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = nullptr);
    Servidor(socketServer* server);
    bool leer_mensaje();
private slots:
    void enviarCambioTurno();
    void abrirConexion();

private:
    handlerServer *manejadorMensajes;
    socketServer *socketserver;
    QTcpSocket* socket;
    QTcpServer* server;
    QString mensajeCliente;
    bool finalizarJuego;

signals:

};

#endif // SERVIDOR_H

