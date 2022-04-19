#ifndef CREARARCHIVOBIN_H
#define CREARARCHIVOBIN_H
#include <QString>
#include <tarjeta.h>


struct tarjetaAAlmacenar{
    int identificador;
    char tipoTarjeta;
    bool revelada;
};

class crearArchivoBin {

public:
    crearArchivoBin();
    void almacenarTarjetas(tarjeta nuevaTarjeta);
};

#endif // CREARARCHIVOBIN_H
