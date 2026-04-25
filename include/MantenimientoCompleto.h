#ifndef MANTENIMIENTOCOMPLETO_H
#define MANTENIMIENTOCOMPLETO_H

#include "MantenimientoStrategy.h"

class MantenimientoCompleto : public MantenimientoStrategy {
public:
    void aplicarMantenimiento(Equipo& equipo) override;
};

#endif