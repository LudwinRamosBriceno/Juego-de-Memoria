#include "sumadorPuntos.h"
#include <QDebug>

sumadorPuntos::sumadorPuntos() {

}

int sumadorPuntos::sumarPuntos(int puntajeActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2) {
    char tipoTarjeta1 = matriz->getTarjetasCargadas()->value(tarjeta1).getTipoTarjeta();
    char tipoTarjeta2 = matriz->getTarjetasCargadas()->value(tarjeta2).getTipoTarjeta();

    if (tipoTarjeta1 == tipoTarjeta2){
        QHash<int,tarjeta>::iterator iterador = matriz->getTarjetasCargadas()->begin();
        QHash<int,tarjeta>::iterator ultimoElemento;
        while(iterador!=matriz->getTarjetasCargadas()->end()){
            ultimoElemento = iterador;
            iterador++;
        }
        puntajeActualJugador++;
        matriz->getTarjetasCargadas()->value(tarjeta1).setRevelada(true);
        matriz->getTarjetasCargadas()->value(tarjeta2).setRevelada(true);
        matriz->getTarjetasCargadas()->erase(ultimoElemento);
    }
    return puntajeActualJugador;
}

int sumadorPuntos::sumarParTarjetasReveladas(int parTarjetasReveladasActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2){
    char tipoTarjeta1 = matriz->getTarjetasCargadas()->value(tarjeta1).getTipoTarjeta();
    char tipoTarjeta2 = matriz->getTarjetasCargadas()->value(tarjeta2).getTipoTarjeta();

    if (tipoTarjeta1 == tipoTarjeta2){
        parTarjetasReveladasActualJugador++;
    }
    return parTarjetasReveladasActualJugador;
}
