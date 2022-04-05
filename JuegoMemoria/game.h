#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QPushButton>
#include <identificadortarjetas.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_buttonComenzar_clicked();
    void leer_mensaje();
    void descubrirTarjeta();

private:
    Ui::Game *ui;
    QTcpSocket *socket;
    QPushButton *TarjetaRevelada;
    bool inicioTurno;
    identificadorTarjetas identificadorTarjetaSeleccionada;

};
#endif // GAME_H
