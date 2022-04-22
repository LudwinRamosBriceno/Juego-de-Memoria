#include "powerups.h"

powerUps::powerUps() {

}

int powerUps::definirPowerUp(int jugador, informacioncliente* infoCliente){
    int resultado = 0;

    switch (infoCliente->getPuntosPowerUp(jugador)) {
        case 2:
            resultado = 5; // primer power up, se suman 5 puntos extras
            infoCliente->setPuntosPowerUp(jugador,true);
            break;
        case 4:
            if(jugador == 1){resultado=2;} // segundo power up, turno del mismo jugador nuevamente
            else{resultado = 1;}
            break;
        case 6:
            resultado = 15; // tercer power up, se suman 15 puntos extras
            infoCliente->setPuntosPowerUp(jugador,false);
            break;
        default:
            resultado = jugador;
            break;
    }
    return resultado;
}
