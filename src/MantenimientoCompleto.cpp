#include "MantenimientoCompleto.h"
#include "Equipo.h"

void MantenimientoCompleto::aplicarMantenimiento(Equipo& equipo) {
    equipo.setEstado(100);
    equipo.setIncidencias(0);
    equipo.resetTiempoInactivo();
}