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
    void atenderCliente() {
        if (!colaEspera.EstaVacia()) {
            std::cout << "\tCaja atendiendo a " << colaEspera.ObtenerFrente() << "\t\t";
            std::cout << "Tiempo de atenci&oacute;n: " << contadorAtencion << "\n\n";
            contadorAtencion++;
            if (contadorAtencion >= colaEspera.ObtenerFrente().length()) {
                colaAtendidos.Agregar(colaEspera.ObtenerFrente());
                colaEspera.Eliminar();
                contadorAtencion = 0;
                tiempoEspera = contadorAtencion + (rand() % INTERVALO);
            }
        } else {
            std::cout << "\tCaja desocupada \n\n\n";
        }
    }
    void agregarCliente(const std::string& nombreCompleto, int tiempoActual) {
        if (tiempoActual >= tiempoEspera) {
            colaEspera.Agregar(nombreCompleto);
            tiempoEspera = tiempoActual + (rand() % INTERVALO);
        }
    }
    void imprimirEspera() {
        if (!colaEspera.EstaVacia())
            colaEspera.ImprimirSinFrente();
    }
    void imprimirAtendidos() {
        if (!colaAtendidos.EstaVacia())
            colaAtendidos.Imprimir();
    }
    int obtenerTamEspera() {
        return colaEspera.ObtenerTam();
    }

    int obtenerTamAtendidos() {
        return colaAtendidos.ObtenerTam();
    }
    std::string obtenerFrenteEspera() {
        return colaEspera.ObtenerFrente();
    }
}
#endif // CAJA_HPP_INCLUDED
