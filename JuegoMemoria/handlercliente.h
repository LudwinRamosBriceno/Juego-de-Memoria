#ifndef HANDLERCLIENTE_H
#define HANDLERCLIENTE_H
#include <QString>
#include <QPushButton>
#include <QLabel>

class handlerCliente {
public:
    handlerCliente();
    void pintarImgTarjeta(QString,QPushButton*);
    void seleccionTurno(QString, QLabel*,QPushButton*,QPushButton*,QLabel*,QLabel*);
    QImage decodeBase64Img(QString);
    void actualizarPuntajePantalla();

};

#endif // HANDLERCLIENTE_H
