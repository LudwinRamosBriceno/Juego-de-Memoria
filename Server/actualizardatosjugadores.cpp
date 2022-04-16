#include "actualizardatosjugadores.h"
#include <sumadorPuntos.h>

ActualizarDatosJugadores::ActualizarDatosJugadores() {

}

void ActualizarDatosJugadores::actualizarDatos(int jugador, matrizpaginada *matriz, informacioncliente *infoCliente, int tarjeta1, int tarjeta2) {
    sumadorPuntos sumador;
    if(jugador == 1){
        int PuntajeJugador1Actualizado= sumador.sumarPuntos(infoCliente->getPuntajeJugador1(),matriz,tarjeta1,tarjeta2);
        int ParTarjetasReveladasJugador1Actualizada= sumador.sumarPuntos(infoCliente->getparTarjetasReveladasJugador1()
                                                                         ,matriz,tarjeta1,tarjeta2);
        infoCliente->setPuntajeJugador1(PuntajeJugador1Actualizado);
        infoCliente->setparTarjetasReveladasJugador1(ParTarjetasReveladasJugador1Actualizada);
    }else{
        int PuntajeJugador2Actualizado= sumador.sumarPuntos(infoCliente->getPuntajeJugador2(),matriz,tarjeta1,tarjeta2);
        int ParTarjetasReveladasJugador2Actualizada= sumador.sumarPuntos(infoCliente->getparTarjetasReveladasJugador2()
                                                                         ,matriz,tarjeta1,tarjeta2);
        infoCliente->setPuntajeJugador1(PuntajeJugador2Actualizado);
        infoCliente->setparTarjetasReveladasJugador1(ParTarjetasReveladasJugador2Actualizada);
    }
}
