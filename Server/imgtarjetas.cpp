#include "imgtarjetas.h"

imgtarjetas::imgtarjetas() {

    QString imgtarjetaA="://Img_verduras.png";
    QString imgtarjetaB="://Img_comida-rapida.png";
    QString imgtarjetaC="://Img_bola-masa.png";

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
