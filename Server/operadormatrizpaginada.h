#ifndef OPERADORMATRIZPAGINADA_H
#define OPERADORMATRIZPAGINADA_H
#include <matrizpaginada.h>
#include <informacioncliente.h>
#include <buscadorTarjeta.h>

class operadorMatrizPaginada {

public:
    operadorMatrizPaginada();
    void reducirMatriz(informacioncliente*,matrizpaginada*,int,int);
    void barajarMatriz();
    void shuffleMatriz(matrizpaginada*);
private:
     buscadorTarjeta buscadorTarjetaSeleccionada;
};

#endif // OPERADORMATRIZPAGINADA_H
