#include "Incidencia.h"

Incidencia::Incidencia(const std::string& equipoId, int severidad, int dia)
        : equipoId(equipoId), severidad(severidad), dia(dia) {}

std::string Incidencia::getEquipoId() const { return equipoId; }
int Incidencia::getSeveridad() const { return severidad; }
int Incidencia::getDia() const { return dia; }