#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTcpSocket>

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

private:
    Ui::Game *ui;
    QTcpSocket *socket;

};
#endif // GAME_H
