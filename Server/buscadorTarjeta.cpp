#include "buscadorTarjeta.h"
#include <cargardescargartarjeta.h>

buscadorTarjeta::buscadorTarjeta() {
    tarjetasEnMemoria = 0;
}

QImage buscadorTarjeta::buscarImgTarjeta(int keyTarjetaAcargar, matrizpaginada* matriz){

    QHash<int,tarjeta>* matrizCargada = matriz->getTarjetasCargadas();
    if (matrizCargada->find(keyTarjetaAcargar)!=matrizCargada->end()){
        tarjetasEnMemoria++;
        return matrizCargada->value(keyTarjetaAcargar).getImgTarjeta(); 
    }
    else{
        //se manda a llamar a cargarDescargar y se le envia la llave como entero, tambien se le manda la tarjeta que
        // debe descargar, de forma que si las dos tarjetas a buscar se cargan a memoria, una no remplace a la otra.

        CargarDescargarTarjeta cargarTarjetaAmatriz;
        /* Dado a que la tarjeta buscada se encuentra en disco, se debe remover una tarjeta de la matriz paginada
         * para cargar la tarjeta deseada a la matrizPaginada.*/
        cargarTarjetaAmatriz.cargarTarjeta(keyTarjetaAcargar,matriz);
        return matriz->getTarjetasCargadas()->value(keyTarjetaAcargar).getImgTarjeta();
    }
}

tarjeta buscadorTarjeta::buscarTarjeta(int keyTarjeta, matrizpaginada* matriz) {
    QHash<int,tarjeta>* matrizCargada = matriz->getTarjetasCargadas();
    if (matrizCargada->find(keyTarjeta)!=matrizCargada->end()){
        return matrizCargada->value(keyTarjeta);
    }
    else{
        //se manda a llamar a cargarDescargar y se le envia la llave de la tarjeta que debe cargar como entero.
        CargarDescargarTarjeta cargarTarjetaAmatriz;
        /* Dado a que la tarjeta buscada se encuentra en disco, se debe remover una tarjeta de la matriz paginada
         * para cargar la tarjeta deseada a la matrizPaginada.*/
        cargarTarjetaAmatriz.cargarTarjeta(keyTarjeta,matriz);
        return matriz->getTarjetasCargadas()->value(keyTarjeta);
    }
}

int buscadorTarjeta::getVerificadorPuntosAdicionales(){
    int temp = tarjetasEnMemoria;
    tarjetasEnMemoria = 0;
    return temp;
}
