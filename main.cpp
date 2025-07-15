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

string seleccionarAleatorio(Cola<string>& cola) {
    int indice = rand() % cola.ObtenerTam();
    for (int i = 0; i < indice; ++i) {
        cola.Agregar(cola.ObtenerFrente());
        cola.Eliminar();
    }
    return cola.ObtenerFrente();
}

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
    cargarDatosEnCola(colaNombres, "nombres.txt");
    cargarDatosEnCola(colaApellidos, "apellidos.txt");

    int segundos = 0;

    cout << "La caja atender\240 a cuantas personas pueda en " << intervaloAtencionTotal << " minutos.\n\n";
    cout << "El tiempo de atenci\242n por persona es aleatorio\n\n\n";

    pausee();
    while (segundos <= intervaloAtencionTotal) {
        LimpiarPantalla();
        try {
            cout << "La caja atender\240 a cuantas personas pueda en " << intervaloAtencionTotal << " minutos.\n";
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
    return 0;
}