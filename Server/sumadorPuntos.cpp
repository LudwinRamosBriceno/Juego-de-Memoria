#include "sumadorPuntos.h"
#include <QDebug>

sumadorPuntos::sumadorPuntos() {

}

int sumadorPuntos::sumarPuntos(int puntajeActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2) {

    char tipoTarjeta1 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1,matriz).getTipoTarjeta();
    char tipoTarjeta2 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2,matriz).getTipoTarjeta();

    if (tipoTarjeta1 == tipoTarjeta2){
        puntajeActualJugador++;

        buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1,matriz);
        matriz->getTarjetasCargadas()->value(tarjeta1).setRevelada(true);

        buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2,matriz);
        matriz->getTarjetasCargadas()->value(tarjeta2).setRevelada(true);

    }
    return puntajeActualJugador;
}

int sumadorPuntos::sumarParTarjetasReveladas(int parTarjetasReveladasActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2){
    char tipoTarjeta1 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1,matriz).getTipoTarjeta();
    char tipoTarjeta2 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2,matriz).getTipoTarjeta();

    if (tipoTarjeta1 == tipoTarjeta2){
        parTarjetasReveladasActualJugador++;
    }
    return parTarjetasReveladasActualJugador;
}
