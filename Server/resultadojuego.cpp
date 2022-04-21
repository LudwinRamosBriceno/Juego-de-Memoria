#include "resultadojuego.h"

resultadoJuego::resultadoJuego() {

}
QString resultadoJuego::definirResultadoJuego(int turnoJugador,informacioncliente* infoCliente, char tipoTarjeta1Presionada, char tipoTarjeta2Presionada){
    QString mensaje;
    int totalParTarjetasReveladas = infoCliente->getparTarjetasReveladasJugador1()+infoCliente->getparTarjetasReveladasJugador2();

    if (turnoJugador == 1){
        mensaje = "turnoJugador2,"+QString::number(infoCliente->getPuntajeJugador1());
    }else{
        mensaje = "turnoJugador1,"+QString::number(infoCliente->getPuntajeJugador2());
    } if (totalParTarjetasReveladas==18){
        mensaje += ",finalizar";
    }
    else if (tipoTarjeta1Presionada==tipoTarjeta2Presionada){mensaje +=",coincide";}else{mensaje+=",NoCoincide";}

    return mensaje;
}

QString resultadoJuego::definirResultadoFinalJuego(informacioncliente* infoCliente){
    QString mensaje = "El ganador es ";

    if(infoCliente->getPuntajeJugador1()>infoCliente->getPuntajeJugador2()){
        mensaje +=infoCliente->getNombreJugador1()+",finalizar";
    }else if(infoCliente->getPuntajeJugador2()>infoCliente->getPuntajeJugador1()){
        mensaje +=infoCliente->getNombreJugador2()+",finalizar";
    }else{
        mensaje ="Es un empate,finalizar";
    }
    return mensaje;
}
