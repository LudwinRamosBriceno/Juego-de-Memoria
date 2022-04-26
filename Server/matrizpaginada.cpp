#include "matrizpaginada.h"

matrizpaginada::matrizpaginada() {
    tarjetasCargadas = new QHash<int,tarjeta>;
}

void matrizpaginada::setTarjetaCargada(int keyTarjeta,tarjeta nuevaTarjeta){
    tarjetasCargadas->insert(keyTarjeta,nuevaTarjeta);
}

QHash<int,tarjeta> *matrizpaginada::getTarjetasCargadas(){
    return tarjetasCargadas;
}
void matrizpaginada::liberarMatrizPaginada(){
    free(tarjetasCargadas);
    tarjetasCargadas = nullptr;
}
