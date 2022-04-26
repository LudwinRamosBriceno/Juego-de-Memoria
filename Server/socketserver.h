#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class socketServer : public QObject{
    Q_OBJECT
public:
    explicit socketServer(QObject *parent = nullptr);
    void limpiarMensaje();
    QString read();
    void escribir(QString mensajeEnviar);

private slots:
    void nuevaConexion();

public slots:
    void almacenarMensaje();

private:
    QTcpServer *server;
    QTcpSocket *socket;
    QString mensajeCliente;

signals:

};

#endif // SOCKETSERVER_H
