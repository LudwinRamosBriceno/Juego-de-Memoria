#include "game.h"
#include "ui_game.h"
#include <splitmensaje.h>

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game){
    ui->setupUi(this);

    ui->tituloGanador->setVisible(false);
    ui->AvisoCaracteres->setVisible(false);
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost",2080);
    connect(socket,SIGNAL(readyRead()),this,SLOT(leer_mensaje()));
}

void Game::on_buttonComenzar_clicked() {
    QString jugador1 = QString(ui->textJugador1->text());
    QString jugador2 = QString(ui->textJugador2->text());

    if (jugador1 !="" && jugador2 !="" && jugador1.length()<11 && jugador2.length()<11){
        QString nombresJugadores = "iniciar,"+jugador1+","+jugador2;

        // se envia al servidor la instruccion de iniciar el juego junto con los nombres de los jugadores;
        socket->write(nombresJugadores.toUtf8().constData(),nombresJugadores.size());
        ui->pantallas->setCurrentIndex(1);
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

    if (QString(bufferMensaje).contains("ganador")){
        ui->tituloGanador->setText("El Ganador es: "+interpreteMensaje.interpretarMensaje(2,QString(bufferMensaje)));

    }else{

    }

}
Game::~Game()
{
    delete ui;
}
