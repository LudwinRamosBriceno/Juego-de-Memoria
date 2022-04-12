#include "buscadorTarjeta.h"
#include <cargardescargartarjeta.h>

buscadorTarjeta::buscadorTarjeta() {

}

QImage buscadorTarjeta::buscarTarjeta(QString keyTarjeta, matrizpaginada* matriz, int numTarjetaAdescargar){

    QHash matrizCargada = matriz->getTarjetasCargadas();
    if (matrizCargada.find(keyTarjeta.toInt())!=matrizCargada.end()){
        return matrizCargada.value(keyTarjeta.toInt()).getImgTarjeta();
    }
    else{
        //se manda a llamar a cargarDescargar y se le envia la llave como entero, tambien se le manda la tarjeta que
        // debe descargar, de forma que si las dos tarjetas a buscar se cargan a memoria, una no remplace a la otra.

        CargarDescargarTarjeta cargarTarjetaAmatriz;
        cargarTarjetaAmatriz.cargarTarjeta(keyTarjeta.toInt(),matriz,numTarjetaAdescargar);

    }
}
