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
        tarjeta2->setEnabled(false);

    }else if(mensaje.contains("NoCoincide")){
        tarjeta1->setIcon(QIcon());
        tarjeta2->setIcon(QIcon());
        tarjeta1->setStyleSheet("#"+tarjeta1->objectName()+"{image: url(:/Img_espalda.png);border: 4px solid gray;border-radius: 8px;}");
        tarjeta2->setStyleSheet("#"+tarjeta2->objectName()+"{image: url(:/Img_espalda.png);border: 4px solid gray;border-radius: 8px;}");
    }
    textAviso->adjustSize();
}
bool handlerCliente::finalizarJuego(QString mensajeServer,QLabel *textAviso,QLabel*puntajeJ1,QLabel*puntajeJ2,QTcpSocket* socket){
    splitMensaje interpreteMensaje;
    QString mensajeAenviar = "finalizar";

    if (mensajeServer.contains("turnoJugador2")){
        puntajeJ1->setText("Puntaje: "+interpreteMensaje.interpretarMensaje(2,mensajeServer));
    }
    else if(mensajeServer.contains("turnoJugador1")){
        puntajeJ2->setText("Puntaje: "+interpreteMensaje.interpretarMensaje(2,mensajeServer));
    }else{
        mensajeAenviar = "close,finalizar";
        textAviso->setText(interpreteMensaje.interpretarMensaje(1,mensajeServer));
        textAviso->move(330,50); textAviso->adjustSize();
        socket->write(mensajeAenviar.toUtf8().constData(),mensajeServer.size());
        socket->close();
        return true;
    }
    socket->write(mensajeAenviar.toUtf8().constData(),mensajeServer.size());
    return false;
}

QImage handlerCliente::decodeBase64Img(QString imgBase64) {
    QByteArray bytesImg = QByteArray::fromBase64(imgBase64.toUtf8());
    QImage image = QImage::fromData(bytesImg,"png");
    return image;
}
