#ifndef INFORMACIONCLIENTE_H
#define INFORMACIONCLIENTE_H
#include <QString>

class informacioncliente {
public:
    informacioncliente();
    void setNombreJugador1(QString nombre);
    void setNombreJugador2(QString nombre);
    QString getNombreJugador1();
    QString getNombreJugador2();
    void setPuntajeJugador1(int puntaje);
    void setPuntajeJugador2(int puntaje);
    int getPuntajeJugador1();
    int getPuntajeJugador2();
    void setparTarjetasReveladasJugador1(int cantidadParTarjetasReveladas);
    void setparTarjetasReveladasJugador2(int cantidadParTarjetasReveladas);
    int getparTarjetasReveladasJugador1();
    int getparTarjetasReveladasJugador2();

private:
    int puntajeJugador1;
    int puntajeJugador2;
    QString nombreJugador1;
    QString nombreJugador2;
    int parTarjetasReveladasJugador1;
    int parTarjetasReveladasJugador2;
};

#endif // INFORMACIONCLIENTE_H
