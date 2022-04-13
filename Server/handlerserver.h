#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

class handlerServer {
public:
    handlerServer();
    QString iniciarJuego(QString nombreJugador1, QString nombreJugador2);
    QString logicHandler(QString mensajeCliente);

private:
    void finalizarJuego();
    QString convetirBase64(QImage);

private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
    int numTarjetaAdescargar;
    int tarjeta1Presionada;
    int tarjeta2Presionada;
};

#endif // HANDLERSERVER_H
