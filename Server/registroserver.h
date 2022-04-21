#ifndef REGISTROSERVER_H
#define REGISTROSERVER_H
#include <matrizpaginada.h>
#include <informacioncliente.h>


class registroServer
{
public:
    registroServer();
    void actualizarTabla(matrizpaginada*,informacioncliente*);
    void estadoFinal();

private:
    bool limpiarTabla;
    void getUsoMemoria(double&, double&);
};

#endif // REGISTROSERVER_H
