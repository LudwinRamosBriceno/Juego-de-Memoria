#include "cargardescargartarjeta.h"
#include <fstream>
#include <iostream>
using namespace std;

CargarDescargarTarjeta::CargarDescargarTarjeta(){

}

void CargarDescargarTarjeta::cargarTarjeta(int tarjetaAcargar,matrizpaginada* matriz, int numTarjetaAdescargar){


}

void CargarDescargarTarjeta::descargarTarjeta(matrizpaginada* matriz, int numTarjetaAdescargar){
    ofstream file;
    tarjeta tarjetaAdescargar;
    QHash matrizPaginada = matriz->getTarjetasCargadas();
    QHash<int,tarjeta>::Iterator iterador;
    int index = 0;

    for (iterador = matrizPaginada.begin();iterador!=matrizPaginada.end();iterador++ ){
        if (index == numTarjetaAdescargar){

            tarjetaAdescargar = iterador.value();
            iterador = matrizPaginada.end();
        }
        index++;
    }
    // se crea una estructura para guardarla en disco
    tarjetaDisco tarjeta = {tarjetaAdescargar.getIdentificador(),tarjetaAdescargar.getTipoTarjeta(),tarjetaAdescargar.getRevelada()};
    file.open("matrizPaginada.matriz",ios::|ios::out|ios::binary);
    if (file.fail()){
        cout<<"No se pudo descargar la tarjeta a disco";
    }else{
        file.seekp(tarjetaAdescargar.getIdentificador()*sizeof(tarjetaDisco));
        file.write((char *)&tarjeta, sizeof(tarjetaDisco));

    }

}
