#include "cargardescargartarjeta.h"
#include <fstream>
#include <iostream>
#include <tarjeta.h>
#include <QDebug>
using namespace std;

CargarDescargarTarjeta::CargarDescargarTarjeta(){

}

void CargarDescargarTarjeta::cargarTarjeta(int IDtarjetaAcargar,matrizpaginada* matriz, int numTarjetaAdescargar){
    descargarTarjeta(matriz,numTarjetaAdescargar); //se actualiza la tarjeta que sera removida de la matrizPaginada
    tarjeta tarjetaAcargar; // tarjeta que será añadida a la matriz paginada
    tarjetaDisco tarjetaAmatriz; // se crea la estructura que se leerá del archivo binario que tiene los datos de la tarjeta
    ifstream file;

    file.open("matrizPaginada.matriz",ios::in|ios::binary);
    if(file.fail()){
        cout<<"El archivo de la matriz no se pudo leer";
    }
    else{
        file.seekg(IDtarjetaAcargar*sizeof (tarjetaDisco));
        file.read((char *)&tarjetaAmatriz,sizeof(tarjetaDisco));
        file.close();
    }
    tarjetaAcargar.setIdentificador(tarjetaAmatriz.identificador);
    tarjetaAcargar.setTipoTarjeta(tarjetaAmatriz.tipoTarjeta);
    tarjetaAcargar.setRevelada(tarjetaAmatriz.revelada);
    tarjetaAcargar.setImgTarjeta();
    matriz->setTarjetaCargada(tarjetaAcargar.getIdentificador(),tarjetaAcargar);

}
// se actualiza la tarjeta a disco que será removida de la matriz paginada
void CargarDescargarTarjeta::descargarTarjeta(matrizpaginada* matriz, int numTarjetaAdescargar){
    ofstream file;
    tarjeta tarjetaAdescargar;
    QHash <int,tarjeta> matrizPaginada = matriz->getTarjetasCargadas();
    QHash<int,tarjeta>::Iterator iterador = matrizPaginada.begin();
    int index = 0;
    bool end = false;

    while(!end){
        if (index == numTarjetaAdescargar){
            tarjetaAdescargar = iterador.value();
            end = true;
        }else{
            index++;
            iterador++;
        }
    }
    // se crea una estructura para guardar una tarjeta en disco
    tarjetaDisco tarjeta = {tarjetaAdescargar.getIdentificador(),tarjetaAdescargar.getTipoTarjeta(),tarjetaAdescargar.getRevelada()};
    file.open("matrizPaginada.matriz",ios::in|ios::out|ios::binary);
    if (file.fail()){
        cout<<"No se pudo descargar la tarjeta a disco";
    }else{
        file.seekp(tarjetaAdescargar.getIdentificador()*sizeof(tarjetaDisco));
        file.write((char *)&tarjeta, sizeof(tarjetaDisco));
        file.close();
    }
    matriz->getTarjetasCargadas().erase(matrizPaginada.find(tarjetaAdescargar.getIdentificador()));
}
