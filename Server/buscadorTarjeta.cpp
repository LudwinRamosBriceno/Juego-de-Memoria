#include "buscadorTarjeta.h"
#include <cargardescargartarjeta.h>

buscadorTarjeta::buscadorTarjeta() {

}

QImage buscadorTarjeta::buscarImgTarjeta(int keyTarjeta, matrizpaginada* matriz, int numTarjetaAdescargar){

    QHash matrizCargada = matriz->getTarjetasCargadas();
    if (matrizCargada.find(keyTarjeta)!=matrizCargada.end()){
        return matrizCargada.value(keyTarjeta).getImgTarjeta();
    }
    else{
        //se manda a llamar a cargarDescargar y se le envia la llave como entero, tambien se le manda la tarjeta que
        // debe descargar, de forma que si las dos tarjetas a buscar se cargan a memoria, una no remplace a la otra.

        CargarDescargarTarjeta cargarTarjetaAmatriz;

        /* Dado a que la tarjeta buscada se encuentra en disco, se debe remover una tarjeta de la matriz paginada
         * para cargar la tarjeta deseada a la matrizPaginada.*/
        cargarTarjetaAmatriz.cargarTarjeta(keyTarjeta,matriz,numTarjetaAdescargar);
        return matriz->getTarjetasCargadas().value(keyTarjeta).getImgTarjeta();
    }
}
