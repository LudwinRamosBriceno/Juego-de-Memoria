#ifndef MATRIZPAGINADA_H
#define MATRIZPAGINADA_H
#include <tarjeta.h>
#include <QHash>


class matrizpaginada{

public:
    matrizpaginada();
    void setTarjetaCargada(int,tarjeta);
    QHash<int,tarjeta>* getTarjetasCargadas();
    void liberarMatrizPaginada();

private:
    QHash <int,tarjeta> *tarjetasCargadas;

};

#endif // MATRIZPAGINADA_H
