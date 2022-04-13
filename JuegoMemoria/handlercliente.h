#ifndef HANDLERCLIENTE_H
#define HANDLERCLIENTE_H
#include <QString>
#include <QPushButton>
#include <QLabel>

class handlerCliente {
public:
    handlerCliente();
    void logicCliente(QString,QPushButton*);
    void seleccionTurno(QString, QLabel*);
    QImage decodeBase64Img(QString);
};

#endif // HANDLERCLIENTE_H
