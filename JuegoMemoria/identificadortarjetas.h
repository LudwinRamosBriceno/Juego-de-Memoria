#ifndef IDENTIFICADORTARJETAS_H
#define IDENTIFICADORTARJETAS_H
#include <QPushButton>
#include <QHash>

class identificadorTarjetas
{
public:
    identificadorTarjetas();
    void setListaTarjetas(QString,int);
    int encontrarIdentificador(QString nombreTarjetaSeleccionada);

private:
    //QString listNombresTarjetas[36];
    QHash <QString, int> listTarjetas;
    int sizeListaTarjetas;
};

#endif // IDENTIFICADORTARJETAS_H
