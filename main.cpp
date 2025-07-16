/**
 * \file main.hpp
 * \brief Aplicaci&oacute;n de una cola con strings. Para simular una cola de banco con tres cajas.
 * \author Ana Laura Chenoweth Galaz, Georgina Salcido Valenzuela
 * \date 17/03/2024
 */
#include <iostream>
#include "Cola/Cola.hpp"
#include "Caja.hpp"
#include <unistd.h> 

#define INTERVALO_ATENCION_MIN 10
#define INTERVALO_ATENCION_MAX 15

using namespace std;

void pausee() {
    std::cout << "Presiona Enter para continuar...";
    std::cin.get();
}

void LimpiarPantalla() {
    system("clear");
}
/** \brief M&eacute;todo que selecciona un dato al azar de una cola.
 *
 * \param cola Cola<string>& Cola de la que se seleccionan los datos.
 * \return string Dato seleccionado al azar
 *
 */
string seleccionarAleatorio(Cola<string>& cola) {
    int indice = rand() % cola.ObtenerTam();
    for (int i = 0; i < indice; ++i) {
        cola.Agregar(cola.ObtenerFrente());
        cola.Eliminar();
    }
    return cola.ObtenerFrente();
}
 /** \brief M&eacute;todo que concatena dos datos seleccionados al azar.
 *
 * \param nombres Cola<string>& Cola de nombres extra&iacute;dos de un archivo.
 * \param apellidos Cola<string>& Cola de apellidos extra&iacute;dos de un archivo.
 * \return string Nombre completo
 *
 */
string generarNombreCompleto(Cola<string>& nombres, Cola<string>& apellidos) {
    string nombreCompleto;
    string nombreAleatorio = seleccionarAleatorio(nombres);
    string apellidoAleatorio = seleccionarAleatorio(apellidos);
    nombreCompleto = nombreAleatorio + " " + apellidoAleatorio;
    return nombreCompleto;
}

int main() {
    srand(time(0));

    const int intervaloAtencionTotal = 120 + (rand() % (140 - 120 + 1));

    Caja caja1, caja2, caja3;

    Cola<string> colaNombres;
    Cola<string> colaApellidos;
    cargarDatosEnCola(colaNombres, "names/nombres.txt");
    cargarDatosEnCola(colaApellidos, "names/apellidos.txt");

    int segundos = 0;

    cout << "La caja atenderá a cuantas personas pueda en " << intervaloAtencionTotal << " minutos.\n\n";
    cout << "El tiempo de atención por persona es aleatorio\n\n\n";

    pausee();
    while (segundos <= intervaloAtencionTotal) {
        LimpiarPantalla();
        try {
            cout << "La caja atenderá a cuantas personas pueda en " << intervaloAtencionTotal << " minutos.\n";
            cout << "Reloj: " << segundos <<  endl << endl;

            caja1.atenderCliente();
            caja2.atenderCliente();
            caja3.atenderCliente();

            cout << "En espera: \n\n";
            cout << "Caja 1: \n";
            caja1.imprimirEspera();

            cout << "Caja 2: \n";
            caja2.imprimirEspera();

            cout << "Caja 3: \n";
            caja3.imprimirEspera();

            cout << endl;

            caja1.agregarCliente(generarNombreCompleto(colaNombres, colaApellidos), segundos);
            caja2.agregarCliente(generarNombreCompleto(colaNombres, colaApellidos), segundos);
            caja3.agregarCliente(generarNombreCompleto(colaNombres, colaApellidos), segundos);

            segundos++;
        } catch(const char* e) {
            cerr << "Error: " << e << endl;
        }

        sleep(1);
    }
    cout << "\n\n\nTerminó el tiempo de atención de las cajas.\n\n";

    //CAJA 1
    cout << "Caja 1 atendió en total a " << caja1.obtenerTamAtendidos() << " personas, cuyos nombres, en orden de atención, son: \n";
    caja1.imprimirAtendidos();

    cout << "Quedaron " << caja1.obtenerTamEspera() << " personas en espera en Caja 1.\n";
    caja1.imprimirEspera();

    cout << "La caja terminó de atender a " << caja1.obtenerFrenteEspera();

    //CAJA 2
    cout << "\n\nCaja 2 atendió en total a " << caja2.obtenerTamAtendidos() << " personas, cuyos nombres, en orden de atención, son: \n";
    caja2.imprimirAtendidos();

    cout << "Quedaron " << caja2.obtenerTamEspera() << " personas en espera en Caja 2.\n";
    caja2.imprimirEspera();

    cout << "La caja terminó de atender a " << caja2.obtenerFrenteEspera();

    //CAJA 3
    cout << "\n\nCaja 3 atendió en total a " << caja3.obtenerTamAtendidos() << " personas, cuyos nombres, en orden de atención, son: \n";
    caja3.imprimirAtendidos();

    cout << "Quedaron " << caja3.obtenerTamEspera() << " personas en espera en Caja 3.\n";
    caja3.imprimirEspera();

    cout << "La caja terminó de atender a " << caja3.obtenerFrenteEspera();
    return 0;
}