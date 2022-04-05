#include "identificadortarjetas.h"

identificadorTarjetas::identificadorTarjetas() {

}

void identificadorTarjetas::setListaTarjetas(QString nombreTarjeta, int size){
    for (int i=0;i<size;i++){
        listNombresTarjetas[i] = nombreTarjeta;
    }
    sizeListaTarjetas = size;
}

int identificadorTarjetas::encontrarIdentificador(QString nombreTarjetaSeleccionada) {
    int identificadorTarjeta = 0;
    for (int indextarjeta = 0;indextarjeta<sizeListaTarjetas;indextarjeta++){
        if(listNombresTarjetas[indextarjeta]==nombreTarjetaSeleccionada){
            identificadorTarjeta = indextarjeta;
        }
    }
    return identificadorTarjeta;
}
