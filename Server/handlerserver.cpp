#include "handlerserver.h"
#include <splitmensaje.h>
#include <buildermatriz.h>
#include <splitmensaje.h>
#include <buscadorTarjeta.h>
#include <QBuffer>


handlerServer::handlerServer() {
    matrizPaginada = new matrizpaginada();
    cliente = new informacioncliente();
}

QString handlerServer::iniciarJuego(QString nombreJugador1, QString nombreJugador2){
    builderMatriz constructorMatriz;
    matrizPaginada = constructorMatriz.construirMatriz();// se construye la matrizPaginada
    cliente->setNombreJugador1(nombreJugador1);
    cliente->setNombreJugador2(nombreJugador2);
    cliente->setPuntajeJugador1(0);
    cliente->setPuntajeJugador1(0);
    cliente->setparTarjetasReveladasJugador1(0);
    cliente->setparTarjetasReveladasJugador1(0);
    numTarjetaAdescargar = 0;

    QString mensaje ="";
    int numRandom = rand()%2;
    switch (numRandom) {
        case 0:
            mensaje = "turnoJugador1";
        case 1:
            mensaje = "turnoJugador2";
    }
    return mensaje;
    //qDebug()<<cliente->getNombreJugador1();
}
void handlerServer::finalizarJuego(){
    matrizPaginada->liberarMatrizPaginada();
    free(matrizPaginada);
    free(cliente);
    matrizPaginada = nullptr;
    cliente = nullptr;

}
QString handlerServer::logicHandler(QString mensajeCliente){
    splitMensaje interpreteMensaje;
    QString mensaje;

    if(mensajeCliente.contains("primeraTarjeta")){
        numTarjetaAdescargar = 0; /* indice de la tarjeta que será removida en caso de que la tarjeta buscada no
                                   esté en la matriz paginada */
        buscadorTarjeta buscador;
        tarjeta1Presionada = interpreteMensaje.interpretarMensaje(2,mensajeCliente).toInt(); // key de la primera tarjeta
        QImage imgTarjetaBuscada= buscador.buscarImgTarjeta(tarjeta1Presionada,matrizPaginada,numTarjetaAdescargar);
        QString imgTarjetaBase64 = convetirBase64(imgTarjetaBuscada);
        mensaje = /*"imgTarjeta," +*/ imgTarjetaBase64;
    }

    return mensaje;
}
QString handlerServer::convetirBase64(QImage imgTarjetaBuscada) {
    QByteArray bytesImg;
    QBuffer buffer(&bytesImg);
    imgTarjetaBuscada.save(&buffer,"png");
    QString imgTarjetaBuscada64 = QString::fromUtf8(bytesImg.toBase64().data());

    return imgTarjetaBuscada64;
}



