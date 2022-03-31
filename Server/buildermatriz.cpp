#include "buildermatriz.h"
#include <tarjeta.h>
#include <crearArchivoBin.h>
#include <QString>
#include <time.h>
#include <stdlib.h>


builderMatriz::builderMatriz() {

}

tarjeta* builderMatriz::construirMatriz(){
    int numeroFilas = 6;
    int numeroColumnas = 6;
    int contadorTarjetasCargadas =0; // se lleva un contador de cuantas tarjetas ya estan cargadas
    int indiceTarjeta = 0; // asigna el identificador de cada tarjeta
    tarjeta *tarjetasCargadas = new tarjeta[(numeroFilas*numeroColumnas)/3];
    char tiposTarjetas[3] ={'A','B','C'};
    srand(time(NULL));
    crearArchivoBin *BIN = new crearArchivoBin();

    for (int fila = 0; fila < numeroFilas; fila++){
        for (int columna = 0; fila < numeroColumnas; fila++){

            int numRandom = rand()%3;
            if (contadorTarjetasCargadas<12){

                contadorTarjetasCargadas++;
                //tarjetasCargadas[indiceTarjeta].setFila(fila);
                //tarjetasCargadas[indiceTarjeta].setColumna(columna);
                tarjetasCargadas[indiceTarjeta].setIdentificador(contadorTarjetasCargadas);
                tarjetasCargadas[indiceTarjeta].setRevelada(false);
                tarjetasCargadas[indiceTarjeta].setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));

                BIN->almacenarTarjetas(tarjetasCargadas[indiceTarjeta]);
                indiceTarjeta++;

            }else{
                tarjeta nuevaTarjeta;
                BIN->almacenarTarjetas(nuevaTarjeta);
                indiceTarjeta++;
            }
        }
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
