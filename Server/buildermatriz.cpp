#include "buildermatriz.h"
#include <tarjeta.h>
#include <crearArchivoBin.h>
#include <QString>
#include <time.h>
#include <stdlib.h>


builderMatriz::builderMatriz() {

}

tarjeta* builderMatriz::construirMatriz(){
    int totalTarjetas =36;
    //int numeroFilas = 6;
    //int numeroColumnas = 6;
    int contadorTarjetasCargadas =0; // se lleva un contador de cuantas tarjetas ya estan cargadas
    //int indiceTarjeta = 0;  asigna el identificador de cada tarjeta
    tarjeta *tarjetasCargadas = new tarjeta[totalTarjetas/3];
    char tiposTarjetas[3] ={'A','B','C'};
    srand(time(NULL));
    crearArchivoBin *BIN = new crearArchivoBin();

    // Cada tarjeta estara enumerada del 0 al 35, es decir las tarjetas en juego son 36
    for (int identificadorTarjeta = 0; identificadorTarjeta < totalTarjetas; identificadorTarjeta++){
        //for (int columna = 0; fila < numeroColumnas; fila++){
        int numRandom = rand()%3;

        // se almacenan las tarjetas en la matriz paginada
        if (contadorTarjetasCargadas<12){

            contadorTarjetasCargadas++;
            //tarjetasCargadas[indiceTarjeta].setFila(fila);
            //tarjetasCargadas[indiceTarjeta].setColumna(columna);
            tarjetasCargadas[identificadorTarjeta].setIdentificador(identificadorTarjeta);
            tarjetasCargadas[identificadorTarjeta].setRevelada(false);
            tarjetasCargadas[identificadorTarjeta].setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));

            BIN->almacenarTarjetas(tarjetasCargadas[identificadorTarjeta]);
            //indiceTarjeta++;

        }else{
            tarjeta nuevaTarjeta;
            nuevaTarjeta.setIdentificador(identificadorTarjeta);
            nuevaTarjeta.setRevelada(false);
            nuevaTarjeta.setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));
            BIN->almacenarTarjetas(nuevaTarjeta);
            //indiceTarjeta++;
            }
        //}
    }
    return tarjetasCargadas;
}

char builderMatriz::verificarCantidadTipos(char tipoTarjeta){
    char tipoTarjetaResultado =' ';
    srand(time(NULL));
    int numRandom = rand()%2;

    if (cantidadTarjetasTipoA>=12 && tipoTarjeta=='A'){
        char tiposTarjetasRestantes[2] ={'B','C'};

        if (tiposTarjetasRestantes[numRandom]=='B' && cantidadTarjetasTipoB<12){
            tipoTarjetaResultado = 'B';
            cantidadTarjetasTipoB++;
        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC<12){
            tipoTarjetaResultado = 'C';
            cantidadTarjetasTipoC++;
        }
    }
    if (cantidadTarjetasTipoB>=12 && tipoTarjeta=='B'){
        char tiposTarjetasRestantes[2] ={'A','C'};

        if (tiposTarjetasRestantes[numRandom]=='A' && cantidadTarjetasTipoA<12){
            tipoTarjetaResultado = 'A';
            cantidadTarjetasTipoA++;
        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC<12){
            tipoTarjetaResultado = 'C';
            cantidadTarjetasTipoC++;
        }
    }
    if (cantidadTarjetasTipoC>=12 && tipoTarjeta=='C'){
        char tiposTarjetasRestantes[2] ={'A','B'};

        if (tiposTarjetasRestantes[numRandom]=='A' && cantidadTarjetasTipoA<12){
            tipoTarjetaResultado = 'A';
            cantidadTarjetasTipoA++;
        }else if(tiposTarjetasRestantes[numRandom]=='B'&& cantidadTarjetasTipoB<12){
            tipoTarjetaResultado = 'B';
            cantidadTarjetasTipoB++;
        }
    }
    return tipoTarjetaResultado;
}
