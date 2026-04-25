#ifndef INCIDENCIA_H
#define INCIDENCIA_H

#include <string>

class Incidencia {
private:
    std::string equipoId;
    int severidad;
    int dia;

public:
    Incidencia(const std::string& equipoId, int severidad, int dia);

    std::string getEquipoId() const;
    int getSeveridad() const;
    int getDia() const;
};

#endif