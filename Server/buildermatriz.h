#ifndef BUILDERMATRIZ_H
#define BUILDERMATRIZ_H


class builderMatriz {

public:
    builderMatriz();
    void construirMatriz();
    char verificarCantidadTipos(char tipoTarjeta);

private:
    int cantidadTarjetasTipoA = 0;
    int cantidadTarjetasTipoB =0;
    int cantidadTarjetasTipoC = 0;

};

#endif // BUILDERMATRIZ_H
