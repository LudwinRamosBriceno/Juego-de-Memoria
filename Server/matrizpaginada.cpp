#include "matrizpaginada.h"

matrizpaginada::matrizpaginada() {

}

void matrizpaginada::setTarjetaCargada(int keyTarjeta,tarjeta nuevaTarjeta){
    tarjetasCargadas.insert(keyTarjeta,nuevaTarjeta);

}
QHash<int,tarjeta> matrizpaginada::getTarjetasCargadas(){
    return tarjetasCargadas;
}
void matrizpaginada::liberarMatrizPaginada(){


}
