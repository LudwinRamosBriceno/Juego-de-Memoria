#ifndef HANDLERSERVER_H
#define HANDLERSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <QTcpSocket>
#include <buscadorTarjeta.h>
#include <operadormatrizpaginada.h>
#include <resultadojuego.h>
#include <registroserver.h>
#include <thread>
#include <iostream>
using namespace std;

class handlerServer {
public:
    handlerServer();
    QString iniciarJuego(QString , QString );
    QString logicHandler(QString);
    QString getResultadoJuego();
    QString finalizarJuego();

private:
    QString convetirBase64(QImage);

private:
    matrizpaginada *matrizPaginada;
    informacioncliente *cliente;
    int tarjeta1Presionada;
    int tarjeta2Presionada;
    int turnoJugador;
    buscadorTarjeta buscadorTarjetaSeleccionada;
    operadorMatrizPaginada operadorMatriz;
    resultadoJuego verificadorEstadoJuego;
    registroServer* tablaParametros;
};

#endif // HANDLERSERVER_H
