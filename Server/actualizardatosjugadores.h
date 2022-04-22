#ifndef ACTUALIZARDATOSJUGADORES_H
#define ACTUALIZARDATOSJUGADORES_H
#include <matrizpaginada.h>
#include <informacioncliente.h>

class ActualizarDatosJugadores {

public:
    ActualizarDatosJugadores();
    void actualizarDatos(int,int,matrizpaginada*,informacioncliente*,int,int);
    int verificarCambioPuntos(int,int,int,informacioncliente*);
};

#endif // ACTUALIZARDATOSJUGADORES_H
