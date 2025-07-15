#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include <string>
#include <fstream>
#include "Cola/Cola.hpp"
#include <iostream>
#define INTERVALO 10

class Caja {
private:
    Cola<std::string> colaEspera;
    Cola<std::string> colaAtendidos;
    int tiempoEspera;
    int contadorAtencion;

public:
    Caja() {
        tiempoEspera = rand() % INTERVALO;
        contadorAtencion = 0;
    }
}
#endif // CAJA_HPP_INCLUDED
