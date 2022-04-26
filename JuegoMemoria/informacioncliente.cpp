#include "informacioncliente.h"

InformacionCliente::InformacionCliente(QString jugador1,QString jugador2)
{
    nombreJugador1 = jugador1;
    nombreJugador2 = jugador2;

}
QString InformacionCliente::getNombreJugador1(){
    return nombreJugador1;

}
QString InformacionCliente::getNombreJugador2(){
    return nombreJugador2;

}
