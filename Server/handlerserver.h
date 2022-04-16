#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpSocket>

class handlerServer {
public:
    handlerServer();
    QString iniciarJuego(QString , QString );
    QString logicHandler(QString);
    QString getParametrosActualizados();

private:
    void finalizarJuego();
    QString convetirBase64(QImage);

private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
    int numTarjetaAdescargar;
    int tarjeta1Presionada;
    int tarjeta2Presionada;
    int turnoJugador;
};

#endif // HANDLERSERVER_H
