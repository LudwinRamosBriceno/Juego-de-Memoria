#include "handlerserver.h"
#include <splitmensaje.h>
#include <buildermatriz.h>
#include <splitmensaje.h>
#include <buscadorTarjeta.h>
#include <QBuffer>
#include <actualizardatosjugadores.h>
#include <iostream>
#include <powerups.h>

handlerServer::handlerServer() {
    matrizPaginada = new matrizpaginada();
    cliente = new informacioncliente();
    tablaParametros = new registroServer();
}

QString handlerServer::iniciarJuego(QString nombreJugador1, QString nombreJugador2){
    builderMatriz constructorMatriz;
    matrizPaginada = constructorMatriz.construirMatriz();// se construye la matrizPaginada
    cliente->setNombreJugador1(nombreJugador1);
    cliente->setNombreJugador2(nombreJugador2);

    QString mensaje;
    int numRandom = rand()%2;
    switch (numRandom) {
        case 0:
            mensaje = "turnoJugador1,0"; turnoJugador = 1;
            break;
        case 1:
            mensaje = "turnoJugador2,0"; turnoJugador = 2;
            break;
    }
    tablaParametros->actualizarTabla(matrizPaginada,cliente);
    return mensaje;
}
QString handlerServer::finalizarJuego(){
    QString mensaje= verificadorEstadoJuego.definirResultadoFinalJuego(cliente);
    matrizPaginada->liberarMatrizPaginada();
    free(matrizPaginada);
    free(cliente);
    matrizPaginada = nullptr;
    cliente = nullptr;
    tablaParametros->estadoFinal();
    free(tablaParametros);
    tablaParametros = nullptr;
    return mensaje;
}

QString handlerServer::logicHandler(QString mensajeCliente){
    splitMensaje interpreteMensaje;
    QString mensaje;

    if(mensajeCliente.contains("primeraTarjeta")){
        tarjeta1Presionada = interpreteMensaje.interpretarMensaje(2,mensajeCliente).toInt(); // key de la primera tarjeta
        QImage imgTarjetaBuscada= buscadorTarjetaSeleccionada.buscarImgTarjeta(tarjeta1Presionada,matrizPaginada);
        QString imgTarjetaBase64 = convetirBase64(imgTarjetaBuscada);
        mensaje = imgTarjetaBase64;

    }else if(mensajeCliente.contains("segundaTarjeta")){
        ActualizarDatosJugadores actualizadorInfoCliente;
        tarjeta2Presionada = interpreteMensaje.interpretarMensaje(2,mensajeCliente).toInt(); // key de la primera tarjeta
        QImage imgTarjetaBuscada= buscadorTarjetaSeleccionada.buscarImgTarjeta(tarjeta2Presionada,matrizPaginada);
        QString imgTarjetaBase64 = convetirBase64(imgTarjetaBuscada);
        mensaje = imgTarjetaBase64;
        actualizadorInfoCliente.actualizarDatos(turnoJugador,buscadorTarjetaSeleccionada.getVerificadorPuntosAdicionales(),matrizPaginada,cliente,tarjeta1Presionada,tarjeta2Presionada);
        operadorMatriz.reducirMatriz(cliente,matrizPaginada,tarjeta1Presionada,tarjeta2Presionada);
    }
    tablaParametros->actualizarTabla(matrizPaginada,cliente);
    return mensaje;
}

QString handlerServer::getResultadoJuego() {
    powerUps potenciador;
    char tipoTarjeta1Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta1Presionada,matrizPaginada).getTipoTarjeta();
    char tipoTarjeta2Presionada = buscadorTarjetaSeleccionada.buscarTarjeta(tarjeta2Presionada,matrizPaginada).getTipoTarjeta();
    turnoJugador = potenciador.definirPowerUp(turnoJugador,cliente);

    QString mensaje = verificadorEstadoJuego.definirResultadoJuego(turnoJugador,cliente,tipoTarjeta1Presionada,tipoTarjeta2Presionada);
    if (turnoJugador == 1){
        turnoJugador = 2;
    }else{
        turnoJugador = 1;
    }
    tablaParametros->actualizarTabla(matrizPaginada,cliente);
    return mensaje;
}

QString handlerServer::convetirBase64(QImage imgTarjetaBuscada) {
    QByteArray bytesImg;
    QBuffer buffer(&bytesImg);
    imgTarjetaBuscada.save(&buffer,"png");
    QString imgTarjetaBuscada64 = QString::fromUtf8(bytesImg.toBase64().data());

    return imgTarjetaBuscada64;
}
