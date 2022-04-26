#ifndef INTERFAZSERVER_H
#define INTERFAZSERVER_H
#include <informacioncliente.h>
#include <matrizpaginada.h>
#include <QTimer>

#include <QObject>

class interfazServer : public QObject {
    Q_OBJECT
public:
    explicit interfazServer(QObject *parent = nullptr);
    void actualizarTabla(matrizpaginada*,informacioncliente*);

private:
    bool limpiarTabla;
    void getUsoMemoria(double&, double&);
    QTimer * timer;

signals:

};

#endif // INTERFAZSERVER_H
