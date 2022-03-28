#include "matrizpaginada.h"

matrizpaginada::matrizpaginada()
{

}


void matrizpaginada::setTarjetasCargadas(tarjeta* punteroTarjetasCargadas){
    tarjetasCargadas = punteroTarjetasCargadas;

}
tarjeta* matrizpaginada::getTarjetasCargadas(){
    return tarjetasCargadas;
}
