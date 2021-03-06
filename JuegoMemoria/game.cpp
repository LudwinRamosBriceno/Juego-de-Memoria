#include "game.h"
#include "ui_game.h"
#include <splitmensaje.h>
#include <iostream>
#include <QVector>
#include <QTimer>
#include <QCoreApplication>

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game){
    ui->setupUi(this);

    manejadorMensajes = new handlerCliente;
    ui->AvisoCaracteres->setVisible(false);
    ui->buttonSalir->setVisible(false);
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost",2080);
    connect(socket,SIGNAL(readyRead()),this,SLOT(leer_mensaje()));
    QVector <QPushButton*> listaBotones {ui->button1,ui->button2,ui->button3,ui->button4,ui->button5,ui->button6,ui->button7,
                               ui->button8,ui->button9,ui->button10,ui->button11,ui->button12,ui->button13,
                               ui->button14,ui->button15,ui->button16,ui->button17,ui->button18,ui->button19,
                               ui->button20,ui->button21,ui->button22,ui->button23,ui->button24,ui->button25,
                               ui->button26,ui->button27,ui->button28,ui->button29,ui->button30,ui->button31,
                               ui->button32,ui->button33,ui->button34,ui->button35,ui->button36};
    for (int i=0;i<listaBotones.length();i++){
        connect(listaBotones[i],SIGNAL(clicked()),this,SLOT(descubrirTarjeta()));
        identificadorTarjetaSeleccionada.setListaTarjetas(listaBotones[i]->objectName(),i);
    }
}

void Game::on_buttonComenzar_clicked() {
    QString jugador1 = QString(ui->textJugador1->text());
    QString jugador2 = QString(ui->textJugador2->text());

    if (jugador1 !="" && jugador2 !="" && jugador1.length()<11 && jugador2.length()<11){
        QString nombresJugadores = "iniciar,"+jugador1+","+jugador2;

        // se envia al servidor la instruccion de iniciar el juego junto con los nombres de los jugadores;
        socket->write(nombresJugadores.toUtf8().constData(),nombresJugadores.size());
        ui->pantallas->setCurrentIndex(1);
        ui->namePJugador1->setText(jugador1);
        ui->namePJugador2->setText(jugador2);
    }
    else{
        ui->AvisoCaracteres->setVisible(true);
    }
}

void Game::leer_mensaje(){
    splitMensaje interpreteMensaje;
    QByteArray bufferMensaje;
    bufferMensaje.resize(socket->bytesAvailable());
    socket->read(bufferMensaje.data(),bufferMensaje.size());

    if (QString(bufferMensaje).contains("finalizar")){
        bool cerrarJuego= manejadorMensajes->finalizarJuego(QString(bufferMensaje),ui->AvisosPjuego,ui->puntajePJugador1,ui->puntajePJugador2,socket);
        if(cerrarJuego){free(manejadorMensajes); manejadorMensajes = nullptr;ui->buttonSalir->setVisible(true);}
        TarjetaRevelada1->setEnabled(false);
        TarjetaRevelada2->setEnabled(false);

    }else if(QString(bufferMensaje).contains("turnoJugador")){
        manejadorMensajes->seleccionTurno(QString(bufferMensaje),ui->AvisosPjuego,TarjetaRevelada1,TarjetaRevelada2,ui->puntajePJugador1,ui->puntajePJugador2);
        botonesEnabled = true;

    }else{
        manejadorMensajes->pintarImgTarjeta(QString(bufferMensaje),TarjetaReveladaActual);
    }
}

void Game::descubrirTarjeta(){
    QString mensajeEnviar;
    TarjetaReveladaActual = qobject_cast<QPushButton*>(sender()); // se castea el boton que dispara el evento
    int identificadorTarjetaRevelada = identificadorTarjetaSeleccionada.encontrarIdentificador(TarjetaReveladaActual->objectName());

    if (!inicioTurno && botonesEnabled){
        TarjetaRevelada1 = TarjetaReveladaActual;
        mensajeEnviar ="primeraTarjeta,"+QString::number(identificadorTarjetaRevelada);
        inicioTurno = true;
        socket->write(mensajeEnviar.toUtf8().constData(),mensajeEnviar.size());
    }else if(botonesEnabled && TarjetaReveladaActual!=TarjetaRevelada1){
        TarjetaRevelada2 = TarjetaReveladaActual;
        mensajeEnviar ="segundaTarjeta,"+QString::number(identificadorTarjetaRevelada);
        inicioTurno = false;
        botonesEnabled = false;
        socket->write(mensajeEnviar.toUtf8().constData(),mensajeEnviar.size());
    }
}
void Game::on_buttonSalir_clicked() {
    QCoreApplication::quit();
}
Game::~Game(){
    delete ui;
}
