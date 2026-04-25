#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    std::string id;
    int criticidad;
    double estado;
    int incidencias;
    int tiempoInactivo;

public:
    Equipo(const std::string& id, int criticidad, double estado);

    std::string getId() const;
    int getCriticidad() const;
    double getEstado() const;
    int getIncidencias() const;
    int getTiempoInactivo() const;

    void setEstado(double nuevoEstado);
    void setIncidencias(int inc);
    void incrementarTiempoInactivo();
    void resetTiempoInactivo();

    void degradar();
    double calcularPrioridad() const;
};

#endif