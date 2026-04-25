#ifndef MANTENIMIENTOBASICO_H
#define MANTENIMIENTOBASICO_H

#include "MantenimientoStrategy.h"

class MantenimientoBasico : public MantenimientoStrategy {
public:
    void aplicarMantenimiento(Equipo& equipo) override;
};

#endif