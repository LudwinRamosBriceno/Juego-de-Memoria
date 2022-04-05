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
    QPushButton *listaBotones [36] = {ui->button1,ui->button2,ui->button3,ui->button4,ui->button5,ui->button6,ui->button7,
                               ui->button8,ui->button9,ui->button10,ui->button11,ui->button12,ui->button13,
                               ui->button14,ui->button15,ui->button16,ui->button17,ui->button18,ui->button19,
                               ui->button20,ui->button21,ui->button22,ui->button23,ui->button24,ui->button25,
                               ui->button26,ui->button27,ui->button28,ui->button29,ui->button30,ui->button31,
                               ui->button32,ui->button33,ui->button34,ui->button35,ui->button36};

    for (int i=0;i<2;i++){
        connect(listaBotones[i],SIGNAL(clicked(numTarjeta)),this,SLOT(descubrirTarjeta()));
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
void Game::descubrirTarjeta(int numTarjeta){
    qDebug()<<"todo bien";
    //se castea el boton

}
Game::~Game()
{
    delete ui;
}
