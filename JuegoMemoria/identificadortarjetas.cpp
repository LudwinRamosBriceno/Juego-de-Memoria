#include "identificadortarjetas.h"

identificadorTarjetas::identificadorTarjetas() {

}

void identificadorTarjetas::setListaTarjetas(QString nombreTarjeta, int identificador){
    listTarjetas.insert(nombreTarjeta,identificador);
}

int identificadorTarjetas::encontrarIdentificador(QString nombreTarjetaSeleccionada) {
    return listTarjetas.value(nombreTarjetaSeleccionada);
}

