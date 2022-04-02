#ifndef IMGTARJETAS_H
#define IMGTARJETAS_H
#include <QString>


class imgtarjetas {

public:
    imgtarjetas();
    //QString gettarjetaTipoA();
    //QString gettarjetaTipoB();
    //QString gettarjetaTipoC();
    QString getImgTarjeta(char tipoTarjeta);

private:
    QString imgtarjetaA;
    QString imgtarjetaB;
    QString imgtarjetaC;
};

#endif // IMGTARJETAS_H
