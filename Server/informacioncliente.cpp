#include "informacioncliente.h"

informacioncliente::informacioncliente() {
    acumuladoJugador1 = 0;
    acumuladoJugador2 = 0;
    puntajeJugador1 = 0;
    puntajeJugador2 = 0;
    parTarjetasReveladasJugador1 = 0;
    parTarjetasReveladasJugador2 = 0;
}

void informacioncliente::setNombreJugador1(QString nombre){
    nombreJugador1 = nombre;
}
void informacioncliente::setNombreJugador2(QString nombre){
    nombreJugador2 = nombre;
}
QString informacioncliente::getNombreJugador1(){
    return nombreJugador1;
}
QString informacioncliente::getNombreJugador2(){
    return nombreJugador2;
}
void informacioncliente::setPuntajeJugador1(int puntaje){
    puntajeJugador1 = puntaje;
}
void informacioncliente::setPuntajeJugador2(int puntaje){
    puntajeJugador2 = puntaje;
}
int informacioncliente::getPuntajeJugador1(){
    return puntajeJugador1;
}
int informacioncliente::getPuntajeJugador2(){
    return puntajeJugador2;
}
void informacioncliente::setparTarjetasReveladasJugador1(int cantidadParTarjetasReveladas){
    parTarjetasReveladasJugador1 = cantidadParTarjetasReveladas;
}
void informacioncliente::setparTarjetasReveladasJugador2(int cantidadParTarjetasReveladas){
    parTarjetasReveladasJugador2 = cantidadParTarjetasReveladas;
}
int informacioncliente::getparTarjetasReveladasJugador1(){
    return parTarjetasReveladasJugador1;
}
int informacioncliente::getparTarjetasReveladasJugador2(){
    return parTarjetasReveladasJugador2;
}
void informacioncliente::setPuntosPowerUp(int jugador,bool sumapuntos){
    if(jugador == 1 && sumapuntos){
        acumuladoJugador1+=1;
    }
    else if(jugador == 1 && sumapuntos == false){
        acumuladoJugador1=0;
    }
    else if(jugador == 2 && sumapuntos){
        acumuladoJugador2+=1;
    }
    else if(jugador == 2 && sumapuntos == false){
        acumuladoJugador2=0;
    }
}
int informacioncliente::getPuntosPowerUp(int jugador){
    int resultado = 0;
    switch (jugador) {
        case 1:
            resultado = acumuladoJugador1;
            break;
        case 2:
            resultado = acumuladoJugador2;
            break;
    }
    return resultado;
}
