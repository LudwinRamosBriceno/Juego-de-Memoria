#include "cargardescargartarjeta.h"
#include <fstream>
#include <iostream>
#include <tarjeta.h>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
using namespace std;

CargarDescargarTarjeta::CargarDescargarTarjeta(){

}

void CargarDescargarTarjeta::cargarTarjeta(int IDtarjetaAcargar,matrizpaginada* matriz){
    QHash<int,tarjeta>::Iterator tarjetaEliminar = descargarTarjeta(matriz); //se actualiza la tarjeta que sera removida de la matrizPaginada
    matriz->getTarjetasCargadas()->erase(tarjetaEliminar); // se elimina la tarjeta ya actualizada en disco

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
QHash<int,tarjeta>::iterator CargarDescargarTarjeta::descargarTarjeta(matrizpaginada* matriz){
    srand(time(NULL));
    ofstream file;
    qDebug()<<"crashea";
    tarjeta tarjetaAdescargar;
    QHash<int,tarjeta>::iterator elementoEliminar;
    QHash<int,tarjeta>::iterator iterador = matriz->getTarjetasCargadas()->begin();
    int indexTarjetaAdescargar = rand()%matriz->getTarjetasCargadas()->size();
    int index = 0;
    bool end = false;
    qDebug()<<"despues de crashea";
    while(!end){
        if (index == indexTarjetaAdescargar){
            tarjetaAdescargar = iterador.value();
            elementoEliminar = iterador;
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
    return elementoEliminar;
}
