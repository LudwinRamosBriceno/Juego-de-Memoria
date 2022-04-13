#include "handlercliente.h"

handlerCliente::handlerCliente() {

}

void handlerCliente::pintarImgTarjeta(QString mensajeServer, QPushButton* tarjetaPresionada) {
   //if (mensajeServer.contains("imgTarjeta")){
   //}
   tarjetaPresionada->setStyleSheet("#"+tarjetaPresionada->objectName()+"{}");
   QImage imgTarjeta = decodeBase64Img(mensajeServer);
   QPixmap pixmap = QPixmap::fromImage(imgTarjeta);
   QIcon iconTarjeta(pixmap);
   tarjetaPresionada->setIcon(iconTarjeta);
}

void handlerCliente::seleccionTurno(QString mensaje, QLabel *textAviso) {
    textAviso->setText("¡Tu turno!");
    if (mensaje.contains("turnoJugador1")){
        textAviso->move(90,50);
    }
    else if(mensaje.contains("turnoJugador2")){
        textAviso->move(650,50);
    }
    textAviso->adjustSize();
}

QImage handlerCliente::decodeBase64Img(QString imgBase64) {
    QByteArray bytesImg = QByteArray::fromBase64(imgBase64.toUtf8());
    QImage image = QImage::fromData(bytesImg,"png");
    return image;
}
