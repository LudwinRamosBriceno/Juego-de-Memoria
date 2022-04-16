#ifndef SUMADORPUNTOS_H
#define SUMADORPUNTOS_H
#include <informacioncliente.h>
#include <matrizpaginada.h>

class sumadorPuntos
{
public:
    sumadorPuntos();
    int sumarPuntos(int,matrizpaginada*,int,int);
    int sumarParTarjetasReveladas(int, matrizpaginada*,int,int);
};

#endif // SUMADORPUNTOS_H
