#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QPushButton>

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
    void descubrirTarjeta(int numTarjeta);

private:
    Ui::Game *ui;
    QTcpSocket *socket;
    QPushButton *primerTarjetaRevelada;
    QPushButton *segundaTarjetaRevelada;

};
#endif // GAME_H
