#include "actualizardatosjugadores.h"
#include <sumadorPuntos.h>
#include <cargardescargartarjeta.h>
#include <powerups.h>

ActualizarDatosJugadores::ActualizarDatosJugadores() {

}

void ActualizarDatosJugadores::actualizarDatos(int jugador,int tarjetasEnMemoria, matrizpaginada *matriz, informacioncliente *infoCliente, int tarjeta1, int tarjeta2) {
    sumadorPuntos sumador;

    if(jugador == 1){
        // se manda a aumentar los puntos y los pares de tarjetas reveladas del jugador en caso de que haya acertado las
        //   dos tarjetas seleccionadas
        int PuntajeJugador1Actualizado= sumador.sumarPuntos(infoCliente->getPuntajeJugador1(),matriz,tarjeta1,tarjeta2,tarjetasEnMemoria);
        int ParTarjetasReveladasJugador1Actualizada= sumador.sumarParTarjetasReveladas(infoCliente->getparTarjetasReveladasJugador1(),matriz,tarjeta1,tarjeta2);

        int puntosExtras = verificarCambioPuntos(jugador,infoCliente->getPuntajeJugador1(),PuntajeJugador1Actualizado,infoCliente);
        infoCliente->setPuntajeJugador1(PuntajeJugador1Actualizado + puntosExtras);
        infoCliente->setparTarjetasReveladasJugador1(ParTarjetasReveladasJugador1Actualizada);

    }else{
        // se manda a aumentar los puntos y los pares de tarjetas reveladas del jugador en caso de que haya acertado las
        //   dos tarjetas seleccionadas
        int PuntajeJugador2Actualizado= sumador.sumarPuntos(infoCliente->getPuntajeJugador2(),matriz,tarjeta1,tarjeta2,tarjetasEnMemoria);
        int ParTarjetasReveladasJugador2Actualizada= sumador.sumarParTarjetasReveladas(infoCliente->getparTarjetasReveladasJugador2(),matriz,tarjeta1,tarjeta2);

        int puntosExtras = verificarCambioPuntos(jugador,infoCliente->getPuntajeJugador2(),PuntajeJugador2Actualizado,infoCliente);
        infoCliente->setPuntajeJugador2(PuntajeJugador2Actualizado + puntosExtras);
        infoCliente->setparTarjetasReveladasJugador2(ParTarjetasReveladasJugador2Actualizada);
    }
}

int ActualizarDatosJugadores::verificarCambioPuntos(int jugador,int puntosActual,int puntosActualizados,informacioncliente* infoCliente){
    powerUps potenciador;
    int puntosExtras = 0;

    if(puntosActual != puntosActualizados){ // si hubo un cambio en los puntos significa que el usuario acert??
        infoCliente->setPuntosPowerUp(jugador,true);
    }else{
        infoCliente->setPuntosPowerUp(jugador,false);
    }
    // Se verifican si el jugador puede obtener el power up 1 o el 3
    if (puntosActual != puntosActualizados && (infoCliente->getPuntosPowerUp(jugador)==2 ||infoCliente->getPuntosPowerUp(jugador)==6)){
        puntosExtras = potenciador.definirPowerUp(jugador,infoCliente);
    }
    return puntosExtras;
}
