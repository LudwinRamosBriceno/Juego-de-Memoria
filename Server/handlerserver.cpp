#include "handlerserver.h"
#include <splitmensaje.h>
#include <buildermatriz.h>


handlerServer::handlerServer()
{
    matrizPaginada = new matrizpaginada();
    cliente = new informacioncliente();
}

void handlerServer::iniciarJuego(QString nombreJugador1, QString nombreJugador2){
    builderMatriz constructorMatriz;

    tarjeta* construccionMatrizPaginada = constructorMatriz.construirMatriz();// se construye la matrizPaginada
    matrizPaginada->setTarjetasCargadas(construccionMatrizPaginada); /* se envia la matriz paginada a
                                                                               a la clase matriz paginada*/
    cliente->setNombreJugador1(nombreJugador1);
    cliente->setNombreJugador2(nombreJugador2);
    cliente->setPuntajeJugador1(0);
    cliente->setPuntajeJugador1(0);
    cliente->setparTarjetasReveladasJugador1(0);
    cliente->setparTarjetasReveladasJugador1(0);
    //qDebug()<<cliente->getNombreJugador1();

}
void handlerServer::finalizarJuego(){
    matrizPaginada->liberarMatrizPaginada();
    free(matrizPaginada);
    free(cliente);
    matrizPaginada = nullptr;
    cliente = nullptr;

}
QString handlerServer::logicHandler(QString mensajeCliente){

}




