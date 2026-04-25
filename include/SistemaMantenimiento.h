#ifndef SISTEMA_MANTENIMIENTO_H
#define SISTEMA_MANTENIMIENTO_H

#include <vector>
#include <string>
#include "Equipo.h"

class SistemaMantenimiento {
private:
    std::vector<Equipo*> equipos;

    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

    int busquedaBinaria(const std::string& id);

public:
    SistemaMantenimiento();
    ~SistemaMantenimiento();

    void generarEquipos(int cantidad);
    void simular();

    Equipo* buscarEquipoPorId(const std::string& id);
};

#endif