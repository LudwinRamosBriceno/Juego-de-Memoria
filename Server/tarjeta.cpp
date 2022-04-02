#include "tarjeta.h"

tarjeta::tarjeta() {

}

void tarjeta::setIdentificador(int identificador){
    identificadorTarjeta =identificador;
}

void tarjeta::setRevelada(bool revelada){
    tarjetaRevelada = revelada;
}

void tarjeta::setTipoTarjeta(char tipo){
    tipoTarjeta=tipo;
}
int tarjeta::getIdentificador(){
    return identificadorTarjeta;
}

char tarjeta::getTipoTarjeta(){
    return tipoTarjeta;
}

bool tarjeta::getRevelada(){
    return tarjetaRevelada;
}
/*void tarjeta::setFila(int fila){

}

void tarjeta::setColumna(int columna){

}*/
