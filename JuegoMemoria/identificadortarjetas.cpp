#include "identificadortarjetas.h"

identificadorTarjetas::identificadorTarjetas() {

}

void identificadorTarjetas::setListaTarjetas(QString nombreTarjeta, int identificador){
    listTarjetas.insert(nombreTarjeta,identificador);
}

int identificadorTarjetas::encontrarIdentificador(QString nombreTarjetaSeleccionada) {

    /*int identificadorTarjeta = 0;
    for (int indextarjeta = 0;indextarjeta<sizeListaTarjetas;indextarjeta++){
        if(listNombresTarjetas[indextarjeta]==nombreTarjetaSeleccionada){
            identificadorTarjeta = indextarjeta;
        }
    }*/
    return listTarjetas.value(nombreTarjetaSeleccionada);
}

