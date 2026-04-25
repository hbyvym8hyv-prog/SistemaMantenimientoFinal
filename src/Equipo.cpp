//
// Created by jimen on 18/4/2026.
//

// implementacion inicial de la clase Equipo


#include "Equipo.h"
#include <algorithm>

Equipo::Equipo(const std::string& id, int criticidad, double estado)
        : id(id), criticidad(criticidad), estado(estado), incidencias(0), tiempoInactivo(0) {}

std::string Equipo::getId() const { return id; }
int Equipo::getCriticidad() const { return criticidad; }
double Equipo::getEstado() const { return estado; }
int Equipo::getIncidencias() const { return incidencias; }
int Equipo::getTiempoInactivo() const { return tiempoInactivo; }

void Equipo::setEstado(double nuevoEstado) {
    estado = std::clamp(nuevoEstado, 0.0, 100.0);
}

void Equipo::setIncidencias(int inc) {
    incidencias = inc;
}

void Equipo::incrementarTiempoInactivo() {
    tiempoInactivo++;
}

void Equipo::resetTiempoInactivo() {
    tiempoInactivo = 0;
}

void Equipo::degradar() {
    estado -= 1.5;
    if (estado < 0) estado = 0;

    tiempoInactivo++;
}

double Equipo::calcularPrioridad() const {
    return (criticidad * 0.5) +
           (incidencias * 0.3) +
           (tiempoInactivo * 0.2);
}