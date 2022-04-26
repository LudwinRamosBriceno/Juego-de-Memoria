#include "interfazserver.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>

using namespace std;

interfazServer::interfazServer(QObject *parent): QObject{parent} {
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT())
}
void interfazServer::actualizarTabla(matrizpaginada* matriz, informacioncliente* cliente){
    string separador = "---------->";
    if(limpiarTabla){
        endwin();
        system("clear");
    }
    curs_set(0);
    initscr();
    int Ymax,Xmax;
    getmaxyx(stdscr,Ymax,Xmax);

    WINDOW * tabla = newwin(12,40,Ymax/32,Xmax/32);
    box(tabla,0,0);

    // Se pintan el numero de tarjetas cargadas

    string cantidadTarjetasCargadas = "Tarjetas cargadas"+separador+to_string(matriz->getTarjetasCargadas()->size());
    auto parametro1 = cantidadTarjetasCargadas.c_str();
    mvwprintw(tabla,1,1,parametro1);

    // se pinta el consumo de memoria del programa
    double vm, rss;
    getUsoMemoria(vm, rss);
    mvwprintw(tabla,3,1,"Consumo:");

    string ConsumoMemoria ="VM"+separador+to_string(vm)+" bytes"; // toda la memoria a la que el programa puede acceder
    auto parametro2 = ConsumoMemoria.c_str();
    mvwprintw(tabla,4,1,parametro2);
    ConsumoMemoria ="RSS"+separador+ to_string(rss)+" bytes"; // memoria que el programa utiliza
    parametro2 = ConsumoMemoria.c_str();
    mvwprintw(tabla,5,1,parametro2);

    // se pinta el puntaje del jugador 1
    string puntajeJugador1 = "Puntaje de "+cliente->getNombreJugador1().toStdString()+separador+to_string(cliente->getPuntajeJugador1());
    auto parametro3 = puntajeJugador1.c_str();
    mvwprintw(tabla,7,1,"%s",parametro3);

    // se pinta el puntaje del jugador 2
    string puntajeJugador2 = "Puntaje de "+cliente->getNombreJugador2().toStdString()+separador+to_string(cliente->getPuntajeJugador2());
    auto parametro4 = puntajeJugador2.c_str();
    mvwprintw(tabla,9,1,"%s",parametro4);
    limpiarTabla = true;
    wrefresh(tabla);
}

void interfazServer::getUsoMemoria(double& vm_usage, double& resident_set){
   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   string pid;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;

   stat_stream >> pid >> pid >> pid >> pid >> pid >> pid >> pid
           >> pid >> pid >> pid >> pid >> pid >> pid
           >> pid >> pid >> pid >> pid >> pid >> pid
           >> pid >> pid >> pid >> vsize >> rss;
   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) ;/// 1024;
   vm_usage     = vsize ;/// 1024.0;
   resident_set = rss * page_size_kb;
}
