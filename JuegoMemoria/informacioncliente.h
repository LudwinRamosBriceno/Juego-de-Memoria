#ifndef INFORMACIONCLIENTE_H
#define INFORMACIONCLIENTE_H
#include <QString>

class InformacionCliente {

public:
    InformacionCliente(QString jugador1,QString jugador2);
    QString getNombreJugador1();
    QString getNombreJugador2();

private:
    QString nombreJugador1;
    QString nombreJugador2;
};

#endif // INFORMACIONCLIENTE_H
