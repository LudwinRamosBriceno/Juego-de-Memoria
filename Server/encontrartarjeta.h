#ifndef ENCONTRARTARJETA_H
#define ENCONTRARTARJETA_H
#include <QImage>
#include <matrizpaginada.h>


class encontrarTarjeta
{
public:
    encontrarTarjeta();
    QImage buscarTarjeta(QString,matrizpaginada*);

};

#endif // ENCONTRARTARJETA_H
