#include "crearArchivoBin.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QDebug>

using namespace std;

crearArchivoBin::crearArchivoBin() {

}
void crearArchivoBin::almacenarTarjetas(tarjeta nuevaTarjeta){
    struct tarjetaAAlmacenar tarjetaAdisco;
    tarjetaAdisco = {nuevaTarjeta.getIdentificador(),nuevaTarjeta.getTipoTarjeta(),nuevaTarjeta.getRevelada()};
    ofstream file;

    file.open("matrizPaginada.matriz",ios::app|ios::out|ios::binary);

    if(file.fail()){
        cout<<"El archivo de la matriz no se pudo cargar";
    }
    else{
        file.write((char *)&tarjetaAdisco,sizeof(tarjetaAAlmacenar));
        file.close();
    }
}

