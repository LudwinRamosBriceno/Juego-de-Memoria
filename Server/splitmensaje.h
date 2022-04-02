#ifndef SPLITMENSAJE_H
#define SPLITMENSAJE_H
#include <QString>

class splitMensaje {

public:
    splitMensaje();
    QString interpretarMensaje(int indiceDato, QString mensaje_a_separar);
};

#endif // SPLITMENSAJE_H
