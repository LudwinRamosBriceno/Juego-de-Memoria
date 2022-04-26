#include "splitmensaje.h"

splitMensaje::splitMensaje(){

}

// busqueda de un dato en un conjunto datos delimitados con comas, que provienen del mensaje del cliente.
QString splitMensaje::interpretarMensaje(int indiceDato, QString mensaje_a_separar){
    QString dato ="";
    char separadorDatos = ',';
    int contadorDatos =1;
    for(int i=0;i<mensaje_a_separar.length();i++){
        if (mensaje_a_separar[i]==separadorDatos && contadorDatos==indiceDato){
            return dato;

        }else if(mensaje_a_separar[i]==separadorDatos){
            dato = "";
            contadorDatos++;

        }else{
            dato+=mensaje_a_separar[i];
        }
    }
    return dato;
}
