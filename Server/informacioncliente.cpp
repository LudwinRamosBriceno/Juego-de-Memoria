#include "informacioncliente.h"

informacioncliente::informacioncliente() {

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
