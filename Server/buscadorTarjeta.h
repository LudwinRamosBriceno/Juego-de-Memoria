#ifndef BUSCADORTARJETA_H
#define BUSCADORTARJETA_H
#include <QImage>
#include <matrizpaginada.h>


class buscadorTarjeta {

public:
    buscadorTarjeta();
    QImage buscarImgTarjeta(int,matrizpaginada*,int);
    void buscarTarjeta();

};

#endif // BUSCADORTARJETA_H
