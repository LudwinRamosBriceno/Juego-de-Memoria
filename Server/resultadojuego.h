#ifndef RESULTADOJUEGO_H
#define RESULTADOJUEGO_H
#include <informacioncliente.h>

class resultadoJuego
{
public:
    resultadoJuego();
    QString definirResultadoJuego(int,informacioncliente*,char,char);
    QString definirResultadoFinalJuego(informacioncliente*);
};

#endif // RESULTADOJUEGO_H
