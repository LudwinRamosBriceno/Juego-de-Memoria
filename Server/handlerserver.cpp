#include "handlerserver.h"
#include <splitmensaje.h>
#include <buildermatriz.h>
#include <splitmensaje.h>
#include <buscadorTarjeta.h>
#include <QBuffer>
#include <QDebug>
#include <actualizardatosjugadores.h>

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

    QString mensaje;
    int numRandom = rand()%2;
    switch (numRandom) {
        case 0:
            mensaje = "turnoJugador1,0";
            turnoJugador = 1;
            break;
        case 1:
            mensaje = "turnoJugador2,0";
            turnoJugador = 2;
            break;
    }
    return mensaje;
}
QString handlerServer::finalizarJuego(){
    QString mensaje= verificadorEstadoJuego.definirResultadoFinalJuego(cliente);
    matrizPaginada->liberarMatrizPaginada();
    free(matrizPaginada);
    free(cliente);
    matrizPaginada = nullptr;
    cliente = nullptr;

    return mensaje;
}

QString handlerServer::logicHandler(QString mensajeCliente){
    splitMensaje interpreteMensaje;
    QString mensaje;

    if(mensajeCliente.contains("primeraTarjeta")){
        numTarjetaAdescargar = 0; /* indice de la tarjeta que será removida en caso de que la tarjeta buscada no
                                   esté en la matriz paginada */
        tarjeta1Presionada = interpreteMensaje.interpretarMensaje(2,mensajeCliente).toInt(); // key de la primera tarjeta
        QImage imgTarjetaBuscada= buscadorTarjetaSeleccionada.buscarImgTarjeta(tarjeta1Presionada,matrizPaginada);
        QString imgTarjetaBase64 = convetirBase64(imgTarjetaBuscada);
        mensaje = imgTarjetaBase64;

    }else if(mensajeCliente.contains("segundaTarjeta")){
        numTarjetaAdescargar = 1; /* indice de la tarjeta que será removida en caso de que la tarjeta buscada no
                                   esté en la matriz paginada */
        ActualizarDatosJugadores actualizadorInfoCliente;
        tarjeta2Presionada = interpreteMensaje.interpretarMensaje(2,mensajeCliente).toInt(); // key de la primera tarjeta
        QImage imgTarjetaBuscada= buscadorTarjetaSeleccionada.buscarImgTarjeta(tarjeta2Presionada,matrizPaginada);
        QString imgTarjetaBase64 = convetirBase64(imgTarjetaBuscada);
        mensaje = imgTarjetaBase64;
        actualizadorInfoCliente.actualizarDatos(turnoJugador,matrizPaginada,cliente,tarjeta1Presionada,tarjeta2Presionada);
        operadorMatriz.reducirMatriz(cliente,matrizPaginada,tarjeta1Presionada,tarjeta2Presionada);
    }else{

    }
    return mensaje;
}
QString handlerServer::getResultadoJuego() {
    char tipoTarjeta1Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1Presionada,matrizPaginada).getTipoTarjeta();
    char tipoTarjeta2Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2Presionada,matrizPaginada).getTipoTarjeta();

    QString mensaje = verificadorEstadoJuego.definirResultadoJuego(turnoJugador,cliente,tipoTarjeta1Presionada,tipoTarjeta2Presionada);
    if (turnoJugador == 1){
        turnoJugador = 2;
    }else{
        turnoJugador = 1;
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

