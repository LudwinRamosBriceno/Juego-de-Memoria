#ifndef IDENTIFICADORTARJETAS_H
#define IDENTIFICADORTARJETAS_H
#include <QPushButton>

class identificadorTarjetas
{
public:
    identificadorTarjetas();
    void setListaTarjetas(QString nombreTarjeta,int size);
    int encontrarIdentificador(QString nombreTarjetaSeleccionada);

private:
    QString listNombresTarjetas[36];
    int sizeListaTarjetas;
};

#endif // IDENTIFICADORTARJETAS_H
