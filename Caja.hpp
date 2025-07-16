/**
 * \file main.hpp
 * \brief Aplicación de una cola con strings. Clase que representa una caja de atención en un banco.
 * \author Ana Laura Chenoweth Galaz, Georgina Salcido Valenzuela
 * \date 17/03/2024
 */
#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include <string>
#include <fstream>
#include "Cola/Cola.hpp"
#include <iostream>
#define INTERVALO 10

class Caja {
private:
    Cola<std::string> colaEspera; /**< Cola de espera de clientes */
    Cola<std::string> colaAtendidos;  /**< Cola de clientes atendidos */
    int tiempoEspera; /**< Tiempo de espera para el siguiente cliente */
    int contadorAtencion; /**< Contador del tiempo de atención actual */

public:
    /**
     * @brief Constructor de la clase Caja.
     * Inicializa el tiempo de espera y el contador de atención.
     */
    Caja() {
        tiempoEspera = rand() % INTERVALO;
        contadorAtencion = 0;
    }
    /**
     * @brief Método para atender al cliente actual en la caja.
     */
    void atenderCliente() {
        if (!colaEspera.EstaVacia()) {
            std::cout << "Caja atendiendo a " << colaEspera.ObtenerFrente() << "\t\t";
            std::cout << "Tiempo de atención: " << contadorAtencion << "\n\n";
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
    /**
     * @brief Método para agregar un cliente a la cola de espera de la caja.
     * @param nombreCompleto Nombre completo del cliente a agregar.
     * @param tiempoActual Tiempo actual para calcular el tiempo de espera.
     */
    void agregarCliente(const std::string& nombreCompleto, int tiempoActual) {
        if (tiempoActual >= tiempoEspera) {
            colaEspera.Agregar(nombreCompleto);
            tiempoEspera = tiempoActual + (rand() % INTERVALO);
        }
    }
    /**
     * @brief Método para imprimir la cola de espera.
     */
    void imprimirEspera() {
        if (!colaEspera.EstaVacia())
            colaEspera.ImprimirSinFrente();
    }
    /**
     * @brief Método para imprimir la cola de clientes atendidos.
     */
    void imprimirAtendidos() {
        if (!colaAtendidos.EstaVacia())
            colaAtendidos.Imprimir();
    }
    /**
     * @brief Método para obtener el tama�o de la cola de espera.
     * @return Tama�o de la cola de espera.
     */
    int obtenerTamEspera() {
        return colaEspera.ObtenerTam();
    }

    int obtenerTamAtendidos() {
        return colaAtendidos.ObtenerTam();
    }
    /**
     * @brief Método para obtener el primer elemento de la cola de espera.
     * @return Primer elemento de la cola de espera.
     */
    std::string obtenerFrenteEspera() {
        return colaEspera.ObtenerFrente();
    }
};
/**
 * @brief Método para cargar datos desde un archivo a una cola.
 * @param cola Cola donde se cargarán los datos.
 * @param archivo Nombre del archivo del que se cargarán los datos.
 */
void cargarDatosEnCola(Cola<std::string>& cola, const std::string& archivo) {
    std::ifstream file(archivo);
    if (file.is_open()) {
        std::string dato;
        while (getline(file, dato)) {
            cola.Agregar(dato);
        }
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << archivo << std::endl;
    }
}
#endif // CAJA_HPP_INCLUDED
