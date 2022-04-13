#include "tarjeta.h"
#include <QImage>
#include <imgtarjetas.h>
#include <QDebug>

tarjeta::tarjeta() {

}

void tarjeta::setIdentificador(int identificador){
    identificadorTarjeta =identificador;
}

void tarjeta::setRevelada(bool revelada){
    tarjetaRevelada = revelada;
}

void tarjeta::setTipoTarjeta(char tipoImg){
    tipoTarjeta=tipoImg;

}
int tarjeta::getIdentificador(){
    return identificadorTarjeta;
}

char tarjeta::getTipoTarjeta(){
    return tipoTarjeta;
}

bool tarjeta::getRevelada(){
    return tarjetaRevelada;
}

void tarjeta::setImgTarjeta() {
    imgtarjetas img;
    QString rutaImagen = img.getImgTarjeta(tipoTarjeta);
    qDebug()<<"Es";
    imagenTarjeta.load(rutaImagen);
    qDebug()<<"Aqui";
}

QImage tarjeta::getImgTarjeta() {
    return imagenTarjeta;
}

