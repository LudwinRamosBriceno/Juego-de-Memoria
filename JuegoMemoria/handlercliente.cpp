#include "handlercliente.h"
#include <splitmensaje.h>

handlerCliente::handlerCliente() {

}

void handlerCliente::pintarImgTarjeta(QString mensajeServer, QPushButton* tarjetaPresionada) {

   tarjetaPresionada->setStyleSheet("#"+tarjetaPresionada->objectName()+"{}");
   QImage imgTarjeta = decodeBase64Img(mensajeServer);
   QPixmap pixmap = QPixmap::fromImage(imgTarjeta);
   QIcon iconTarjeta(pixmap);
   tarjetaPresionada->setIcon(iconTarjeta);
   tarjetaPresionada->setIconSize(QSize(100,50));

}

void handlerCliente::seleccionTurno(QString mensaje,QLabel *textAviso,QPushButton*tarjeta1,QPushButton*tarjeta2,QLabel*puntajeJ1,QLabel*puntajeJ2) {
    splitMensaje interpreteMensaje;
    bool coinciden = false;
    textAviso->setText("¡Tu turno!");
    if (mensaje.contains("turnoJugador1")){
        puntajeJ2->setText("Puntaje: "+interpreteMensaje.interpretarMensaje(2,mensaje));
        textAviso->move(95,50);
    }
    else if(mensaje.contains("turnoJugador2")){
        puntajeJ1->setText("Puntaje: "+interpreteMensaje.interpretarMensaje(2,mensaje));
        textAviso->move(650,50);
    }
    if (mensaje.contains("coincide")){
        tarjeta1->setEnabled(false);
        tarjeta1->setStyleSheet("");
        tarjeta2->setEnabled(false);
        tarjeta2->setStyleSheet("");
        coinciden = true;
    }else{
        tarjeta1->setStyleSheet("");
        tarjeta2->setStyleSheet("");
    }
    textAviso->adjustSize();
}

QImage handlerCliente::decodeBase64Img(QString imgBase64) {
    QByteArray bytesImg = QByteArray::fromBase64(imgBase64.toUtf8());
    QImage image = QImage::fromData(bytesImg,"png");
    return image;
}
void handlerCliente::reiniciarTarjetas(QPushButton*,QPushButton*){

}
