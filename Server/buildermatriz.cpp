#include "buildermatriz.h"
#include <tarjeta.h>
#include <QString>
#include <time.h>
#include <stdlib.h>


builderMatriz::builderMatriz() {

}

void builderMatriz::construirMatriz(){
    int numeroFilas = 6;
    int numeroColumnas = 6;
    int contadorTarjetasCargadas =0;
    int indiceTarjeta = 0;
    tarjeta *tarjetasCargadas = new tarjeta[(numeroFilas*numeroColumnas)/3];
    char tiposTarjetas[3] ={'A','B','C'};
    srand(time(NULL));

    for (int fila = 0; fila < numeroFilas; fila++){
        for (int columna = 0; fila < numeroColumnas; fila++){

            if (contadorTarjetasCargadas<12){
                int numRandom = rand()%5;
                contadorTarjetasCargadas++;
                tarjetasCargadas[indiceTarjeta].setFila(fila);
                tarjetasCargadas[indiceTarjeta].setColumna(columna);
                tarjetasCargadas[indiceTarjeta].setIdentificador(contadorTarjetasCargadas);
                tarjetasCargadas[indiceTarjeta].setRevelada(false);
                tarjetasCargadas[indiceTarjeta].setTipoTarjeta(verificarCantidadTipos(tiposTarjetas[numRandom]));
                indiceTarjeta++;
            }

        }
    }
}
char builderMatriz::verificarCantidadTipos(char tipoTarjeta){
    char tipoTarjetaResultado =' ';
    if (cantidadTarjetasTipoA>=12 && tipoTarjeta=='A'){
        srand(time(NULL));
        char tiposTarjetasRestantes[2] ={'B','C'};
        int numRandom = rand()%3;

        if (tiposTarjetasRestantes[numRandom]=='B' && cantidadTarjetasTipoB<12){
            tipoTarjetaResultado = 'B';
            cantidadTarjetasTipoB++;
        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC<12){
            tipoTarjetaResultado = 'C';
            cantidadTarjetasTipoC++;
        }
    }
    if (cantidadTarjetasTipoB>=12 && tipoTarjeta=='B'){
        srand(time(NULL));
        char tiposTarjetasRestantes[2] ={'A','C'};
        int numRandom = rand()%3;

        if (tiposTarjetasRestantes[numRandom]=='A' && cantidadTarjetasTipoA<12){
            tipoTarjetaResultado = 'A';
            cantidadTarjetasTipoA++;
        }else if(tiposTarjetasRestantes[numRandom]=='C'&& cantidadTarjetasTipoC<12){
            tipoTarjetaResultado = 'C';
            cantidadTarjetasTipoC++;
        }
    }
    if (cantidadTarjetasTipoC>=12 && tipoTarjeta=='C'){
        srand(time(NULL));
        char tiposTarjetasRestantes[2] ={'A','B'};
        int numRandom = rand()%3;

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
