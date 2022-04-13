#include "imgtarjetas.h"


imgtarjetas::imgtarjetas() {

    QString imgtarjetaA=":/recursos/Img_verduras.png";
    QString imgtarjetaB=":/recursos/Img_comida-rapida.png";
    QString imgtarjetaC=":/recursos/Img_bola-masa.png";
    QString imgtarjetaDesabilitada = "";
}

QString imgtarjetas::getImgTarjeta(char tipoTarjeta){
    QString imgTarjeta = "";
    switch (tipoTarjeta){
        case 'A':
            imgTarjeta = imgtarjetaA;
            break;
        case 'B':
            imgTarjeta = imgtarjetaB;
            break;
        case 'C':
            imgTarjeta = imgtarjetaC;
            break;
        case 'D':
            imgTarjeta = imgDesabilitada;
    }
    return imgTarjeta;
}
