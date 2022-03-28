#include "creartxt.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

creartxt::creartxt()
{

}
void creartxt::almacenarTarjetas(char tipoTarjeta,int identificadorTarjeta){
    fstream file;
    file.open("://matriz.txt",fstream::app);

    if(file.fail()){
        cout<<"El archivo de la matriz no se pudo cargar";
    }

    else if ((identificadorTarjeta+1)%6==0){
        file<<tipoTarjeta+to_string(identificadorTarjeta);
        file.close();

    }else{
        file<<tipoTarjeta+to_string(identificadorTarjeta)+",";
        file.close();
    }
}
