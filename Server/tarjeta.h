#ifndef TARJETA_H
#define TARJETA_H


class tarjeta {

public:
    tarjeta();
    void setIdentificador(int identificador);
    void setRevelada(bool revelada);
    void setTipoTarjeta(char tipoTarjeta);
    void setFila(int fila);
    void setColumna(int columna);

private:
    int identificador;
    bool revelada;
    char tipoTarjeta;
    int fila;
    int columna;
};

#endif // TARJETA_H
