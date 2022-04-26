#include "imgtarjetas.h"


imgtarjetas::imgtarjetas() {

    imgtarjetaA="recursos/Img_verduras.png";
    imgtarjetaB="recursos/Img_comida-rapida.png";
    imgtarjetaC="recursos/Img_bola-masa.png";
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
    }
    return imgTarjeta;
}
