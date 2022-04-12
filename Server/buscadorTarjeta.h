#ifndef BUSCADORTARJETA_H
#define BUSCADORTARJETA_H
#include <QImage>
#include <matrizpaginada.h>


class buscadorTarjeta {

public:
    buscadorTarjeta();
    QImage buscarTarjeta(int,matrizpaginada*,int);

};

#endif // BUSCADORTARJETA_H
