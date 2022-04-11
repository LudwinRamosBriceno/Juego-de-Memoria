#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

class handlerServer {
public:
    handlerServer();
    void iniciarJuego(QString nombreJugador1, QString nombreJugador2);
    QString logicHandler(QString mensajeCliente);

private:
    void finalizarJuego();

private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
    int numTarjetaAdescargar;
};

#endif // HANDLERSERVER_H
