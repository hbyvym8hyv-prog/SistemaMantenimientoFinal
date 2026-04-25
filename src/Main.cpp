#include <iostream>
#include "SistemaMantenimiento.h"
#include "EquipoNoEncontradoException.h"

int main() {
    try {
        SistemaMantenimiento sistema;

        sistema.generarEquipos(100);
        sistema.simular();

        // 🔍 búsqueda
        std::string idBuscar = "EQ-10";
        Equipo* e = sistema.buscarEquipoPorId(idBuscar);

        if (!e) {
            throw EquipoNoEncontradoException();
        }

        std::cout << "\nBusqueda exitosa: " << e->getId() << std::endl;

    } catch (const EquipoNoEncontradoException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Error inesperado\n";
    }

    return 0;
}