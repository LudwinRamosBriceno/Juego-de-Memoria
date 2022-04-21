#include "buildermatriz.h"
#include <tarjeta.h>
#include <crearArchivoBin.h>
#include <QString>
#include <stdlib.h>
#include <time.h>


builderMatriz::builderMatriz() {

}

matrizpaginada* builderMatriz::construirMatriz(){
    int totalTarjetas =36;
    int contadorTarjetasCargadas =0; // se lleva un contador de cuantas tarjetas ya estan cargadas
    remove("matrizPaginada.matriz"); // se elimina el archivo para no acumular los datos que se guardan en ese archivo
    matrizpaginada* matrizPaginada = new matrizpaginada();
    char tiposTarjetas[3] ={'A','B','C'};
    srand(time(NULL));
    crearArchivoBin BIN;

    // Cada tarjeta estara enumerada del 0 al 35, es decir las tarjetas en juego son 36
    for (int identificadorTarjeta = 0; identificadorTarjeta < totalTarjetas; identificadorTarjeta++){
        int numRandom = rand()%3;
        tarjeta nuevaTarjeta;

        // se almacenan las tarjetas en la matriz paginada
        if (contadorTarjetasCargadas<12){

            contadorTarjetasCargadas++;
            nuevaTarjeta.setIdentificador(identificadorTarjeta);
            nuevaTarjeta.setRevelada(false);
            nuevaTarjeta.setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));
            nuevaTarjeta.setImgTarjeta();
            matrizPaginada->setTarjetaCargada(identificadorTarjeta,nuevaTarjeta);
            BIN.almacenarTarjetas(nuevaTarjeta);

        }else{
            nuevaTarjeta.setIdentificador(identificadorTarjeta);
            nuevaTarjeta.setRevelada(false);
            nuevaTarjeta.setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));
            BIN.almacenarTarjetas(nuevaTarjeta);
        }
    }
    return matrizPaginada;
}

char builderMatriz::verificarCantidadTipos(char tipoTarjeta){
    char tipoTarjetaResultado =tipoTarjeta;
    int numRandom = rand()%2;

    if (cantidadTarjetasTipoA>=12 && tipoTarjeta=='A'){
        char tiposTarjetasRestantes[2] ={'B','C'};

        if (tiposTarjetasRestantes[numRandom]=='B' && cantidadTarjetasTipoB >=12){
            tipoTarjetaResultado ='C';

        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC >=12){
            tipoTarjetaResultado ='B';

        }else{tipoTarjetaResultado = tiposTarjetasRestantes[numRandom];}
    }
    if (cantidadTarjetasTipoB>=12 && tipoTarjeta=='B'){
        char tiposTarjetasRestantes[2] ={'A','C'};

        if (tiposTarjetasRestantes[numRandom]=='A' && cantidadTarjetasTipoA >=12){
            tipoTarjetaResultado ='C';

        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC>=12){
            tipoTarjetaResultado ='A';

        } else{tipoTarjetaResultado = tiposTarjetasRestantes[numRandom];}
    }
    if (cantidadTarjetasTipoC>=12 && tipoTarjeta=='C'){
        char tiposTarjetasRestantes[2] ={'A','B'};

        if (tiposTarjetasRestantes[numRandom]=='A' && cantidadTarjetasTipoA>=12){
            tipoTarjetaResultado ='B';

        }else if(tiposTarjetasRestantes[numRandom]=='B'&& cantidadTarjetasTipoB>=12){
            tipoTarjetaResultado ='A';

        }else{tipoTarjetaResultado = tiposTarjetasRestantes[numRandom];}
    }
    switch (tipoTarjetaResultado) {
        case 'A': cantidadTarjetasTipoA++;break;
        case 'B': cantidadTarjetasTipoB++;break;
        case 'C': cantidadTarjetasTipoC++;break;
    }
    return tipoTarjetaResultado;
}
