#ifndef MATRIZPAGINADA_H
#define MATRIZPAGINADA_H
#include <tarjeta.h>


class matrizpaginada{

public:
    matrizpaginada();
    void setTarjetasCargadas(tarjeta* punteroTarjetasCargadas);
    tarjeta* getTarjetasCargadas();
    void liberarMatrizPaginada();

private:
    tarjeta *tarjetasCargadas;

};

#endif // MATRIZPAGINADA_H
