#include "crearArchivoBin.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

crearArchivoBin::crearArchivoBin() {

}
void crearArchivoBin::almacenarTarjetas(tarjeta nuevaTarjeta){
    struct tarjetaAAlmacenar tarjetaAdisco;
    tarjetaAdisco = {nuevaTarjeta.getIdentificador(),nuevaTarjeta.getTipoTarjeta(),nuevaTarjeta.getRevelada()};
    fstream file;

    file.open("://matrizPaginada.matriz",ios::app|ios::binary);

    if(file.fail()){
        cout<<"El archivo de la matriz no se pudo cargar";
    }
    else{
        file.write((char *)&tarjetaAdisco,sizeof(tarjetaAAlmacenar));
        file.close();
    }
}
