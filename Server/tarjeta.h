#ifndef TARJETA_H
#define TARJETA_H
#include <QImage>


class tarjeta {

public:
    tarjeta();
    void setIdentificador(int identificador);
    void setRevelada(bool revelada);
    void setTipoTarjeta(char tipoImg);
    //void setFila(int fila);
    //void setColumna(int columna);
    int getIdentificador();
    char getTipoTarjeta();
    bool getRevelada();
    void setImgTarjeta();
    QImage getImgTarjeta();

private:
    int identificadorTarjeta;
    char tipoTarjeta;
    bool tarjetaRevelada;
    QImage imagenTarjeta;
    //int fila;
    //int columna;
};

#endif // TARJETA_H
