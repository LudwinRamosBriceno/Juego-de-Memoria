#include "sumadorPuntos.h"
#include <QDebug>

sumadorPuntos::sumadorPuntos() {

}

int sumadorPuntos::sumarPuntos(int puntajeActualJugador, matrizpaginada *matriz, int tarjeta1, int tarjeta2,int tarjetasEnMemoria) {
    char tipoTarjeta1 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1,matriz).getTipoTarjeta();
    char tipoTarjeta2 = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2,matriz).getTipoTarjeta();

    if (tipoTarjeta1 == tipoTarjeta2){
        puntajeActualJugador++;

        buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1,matriz); //se carga la tarjeta 1 a la matriz que se desea buscar
        matriz->getTarjetasCargadas()->value(tarjeta1).setRevelada(true);

        buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2,matriz); //se carga la tarjeta 2 a la matriz que se desea buscar
        matriz->getTarjetasCargadas()->value(tarjeta2).setRevelada(true);
        operadorMatriz.shuffleMatriz(matriz);
        if(tarjetasEnMemoria==2){
            puntajeActualJugador++;

        }
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
