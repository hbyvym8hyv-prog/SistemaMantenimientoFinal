#include "MantenimientoBasico.h"
#include "Equipo.h"
#include <algorithm>

void MantenimientoBasico::aplicarMantenimiento(Equipo& equipo) {
    equipo.setEstado(equipo.getEstado() + 10);
    equipo.setIncidencias(std::max(0, equipo.getIncidencias() - 1));
    equipo.resetTiempoInactivo();
}