#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

class handlerServer {
public:
    handlerServer();
    void iniciarJuego(QString nombreJugador1, QString nombreJugador2);
    void finalizarJuego();
    QString logicHandler(QString mensajeCliente);


private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
};

#endif // HANDLERSERVER_H
