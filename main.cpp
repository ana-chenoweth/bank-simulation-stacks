#include <iostream>
#include "Cola/Cola.hpp"
#include "Caja.hpp"

#define INTERVALO_ATENCION_MIN 10
#define INTERVALO_ATENCION_MAX 15

using namespace std;

void pause() {
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

    pause();
    return 0;
}