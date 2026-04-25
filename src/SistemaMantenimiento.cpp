#include "SistemaMantenimiento.h"
#include "MantenimientoBasico.h"
#include "MantenimientoCompleto.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
SistemaMantenimiento::SistemaMantenimiento() {
    std::srand(std::time(nullptr));
}

SistemaMantenimiento::~SistemaMantenimiento() {
    for (auto e : equipos) delete e;
}

void SistemaMantenimiento::generarEquipos(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        std::string id = "EQ-" + std::to_string(i + 1);
        int criticidad = rand() % 10 + 1;
        double estado = rand() % 100;

        equipos.push_back(new Equipo(id, criticidad, estado));
    }
}

void SistemaMantenimiento::merge(int left, int mid, int right) {
    std::vector<Equipo*> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (equipos[i]->calcularPrioridad() > equipos[j]->calcularPrioridad())
            temp.push_back(equipos[i++]);
        else
            temp.push_back(equipos[j++]);
    }

    while (i <= mid) temp.push_back(equipos[i++]);
    while (j <= right) temp.push_back(equipos[j++]);

    for (int k = 0; k < temp.size(); k++)
        equipos[left + k] = temp[k];
}

void SistemaMantenimiento::mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

// Simulacion
void SistemaMantenimiento::simular() {

    MantenimientoBasico basico;
    MantenimientoCompleto completo;

    std::ofstream archivo("reporte.txt");

    for (int dia = 1; dia <= 30; dia++) {

        std::cout << "\n===== DIA " << dia << " =====\n";
        archivo << "\n===== DIA " << dia << " =====\n";

        for (auto e : equipos) {
            e->degradar();

            if (rand() % 4 == 0) {
                int nuevas = rand() % 2;
                e->setIncidencias(e->getIncidencias() + nuevas);
            }

            if (e->getIncidencias() > 0 && rand() % 5 == 0) {
                e->setIncidencias(e->getIncidencias() - 1);
            }
        }

        mergeSort(0, equipos.size() - 1);

        std::cout << "Top prioridad:\n";
        archivo << "Top prioridad:\n";

        for (int i = 0; i < 3; i++) {
            std::cout << equipos[i]->getId()
                      << " -> " << equipos[i]->calcularPrioridad() << std::endl;

            archivo << equipos[i]->getId()
                    << " -> " << equipos[i]->calcularPrioridad() << std::endl;
        }

        std::cout << "Asignados: ";
        archivo << "Asignados: ";

        for (int i = 0; i < 3; i++) {
            std::cout << equipos[i]->getId() << " ";
            archivo << equipos[i]->getId() << " ";
        }

        std::cout << std::endl;
        archivo << std::endl;

        for (int i = 0; i < 3; i++) {

            if (equipos[i]->getEstado() < 50) {
                completo.aplicarMantenimiento(*equipos[i]);
                equipos[i]->setIncidencias(0);
            } else {
                basico.aplicarMantenimiento(*equipos[i]);

                int inc = equipos[i]->getIncidencias();
                if (inc > 0)
                    equipos[i]->setIncidencias(inc - 1);
            }
        }

        int backlog = 0;
        for (auto e : equipos)
            if (e->getIncidencias() > 0) backlog++;

        std::cout << "Backlog: " << backlog << std::endl;
        archivo << "Backlog: " << backlog << std::endl;

        std::string riesgo =
            (backlog > 60) ? "ALTO" :
            (backlog > 30) ? "MEDIO" : "BAJO";

        std::cout << "Riesgo: " << riesgo << std::endl;
        archivo << "Riesgo: " << riesgo << std::endl;
    }

    archivo.close();
}

int SistemaMantenimiento::busquedaBinaria(const std::string& id) {
    int l = 0, r = equipos.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (equipos[m]->getId() == id) return m;
        else if (equipos[m]->getId() < id) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

Equipo* SistemaMantenimiento::buscarEquipoPorId(const std::string& id) {
    std::sort(equipos.begin(), equipos.end(),
        [](Equipo* a, Equipo* b) {
            return a->getId() < b->getId();
        });

    int pos = busquedaBinaria(id);
    return (pos == -1) ? nullptr : equipos[pos];
}