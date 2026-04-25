#ifndef MANTENIMIENTOSTRATEGY_H
#define MANTENIMIENTOSTRATEGY_H

class Equipo;

class MantenimientoStrategy {
public:
    virtual void aplicarMantenimiento(Equipo& equipo) = 0;
    virtual ~MantenimientoStrategy() = default;
};

#endif