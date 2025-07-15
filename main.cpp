#include <iostream>
#include "Cola/Cola.hpp"
#include "Caja.hpp"

#define INTERVALO_ATENCION_MIN 10
#define INTERVALO_ATENCION_MAX 15

using namespace std;

int main() {
    srand(time(0));

    const int intervaloAtencionTotal = 120 + (rand() % (140 - 120 + 1));

    Caja caja1, caja2, caja3;

    Cola<string> colaNombres;
    Cola<string> colaApellidos;
    
    return 0;
}