#include "operadormatrizpaginada.h"
#include <cargardescargartarjeta.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

operadorMatrizPaginada::operadorMatrizPaginada(){

}

void operadorMatrizPaginada::reducirMatriz(informacioncliente*infoCliente,matrizpaginada* matrizPaginada, int keyTarjeta1, int keyTarjeta2) {
    int totalTarjetasReveladas = infoCliente->getparTarjetasReveladasJugador1()+infoCliente->getparTarjetasReveladasJugador2();
    char tipoTarjeta1Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(keyTarjeta1,matrizPaginada).getTipoTarjeta();
    char tipoTarjeta2Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(keyTarjeta2,matrizPaginada).getTipoTarjeta();

    if(totalTarjetasReveladas%2==0 && (tipoTarjeta1Presionada==tipoTarjeta2Presionada)){
        CargarDescargarTarjeta actualizadorTarjetaDisco;
        QHash<int,tarjeta>::Iterator tarjetaEliminar = actualizadorTarjetaDisco.descargarTarjeta(matrizPaginada);
        matrizPaginada->getTarjetasCargadas()->erase(tarjetaEliminar);
    }
}

void operadorMatrizPaginada::shuffleMatriz(matrizpaginada* matriz){
    srand(time(NULL));
    CargarDescargarTarjeta actualizadorTarjetaDisco;

    for (int i=0;i<matriz->getTarjetasCargadas()->size();i++){
        int IDtarjetaRandom = rand()%36;
        if (matriz->getTarjetasCargadas()->find(IDtarjetaRandom)==matriz->getTarjetasCargadas()->end()){
            actualizadorTarjetaDisco.cargarTarjeta(IDtarjetaRandom,matriz);
        }
    }

}
