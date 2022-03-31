#ifndef TARJETA_H
#define TARJETA_H


class tarjeta {

public:
    tarjeta();
    void setIdentificador(int identificador);
    void setRevelada(bool revelada);
    void setTipoTarjeta(char tipoTarjeta);
    //void setFila(int fila);
    //void setColumna(int columna);
    int getIdentificador();
    char getTipoTarjeta();
    bool getRevelada();

private:
    int identificador;
    char tipoTarjeta;
    bool revelada;
    int fila;
    int columna;
};

#endif // TARJETA_H
