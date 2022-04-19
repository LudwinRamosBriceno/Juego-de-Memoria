#ifndef TARJETA_H
#define TARJETA_H
#include <QImage>


class tarjeta {

public:
    tarjeta();
    void setIdentificador(int identificador);
    void setRevelada(bool revelada);
    void setTipoTarjeta(char tipoImg);
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

};

#endif // TARJETA_H
