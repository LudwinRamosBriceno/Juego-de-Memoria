#ifndef HANDLERCLIENTE_H
#define HANDLERCLIENTE_H
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QTcpSocket>

class handlerCliente {
public:
    handlerCliente();
    void pintarImgTarjeta(QString,QPushButton*);
    void seleccionTurno(QString, QLabel*,QPushButton*,QPushButton*,QLabel*,QLabel*);
    QImage decodeBase64Img(QString);
    void actualizarPuntajePantalla();
    bool finalizarJuego(QString,QLabel*,QLabel*,QLabel*,QTcpSocket*);
private:
    QString estiloPredeterminadoTarjeta;
};

#endif // HANDLERCLIENTE_H
