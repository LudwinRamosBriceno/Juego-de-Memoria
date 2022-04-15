#ifndef CARGARDESCARGARTARJETA_H
#define CARGARDESCARGARTARJETA_H
#include <matrizpaginada.h>
#include <tarjeta.h>

struct tarjetaDisco{
    int identificador;
    char tipoTarjeta;
    bool revelada;
};

class CargarDescargarTarjeta {

public:
    CargarDescargarTarjeta();
    void cargarTarjeta(int,matrizpaginada*,int);
    void descargarTarjeta(matrizpaginada*,int);

};

#endif // CARGARDESCARGARTARJETA_H
