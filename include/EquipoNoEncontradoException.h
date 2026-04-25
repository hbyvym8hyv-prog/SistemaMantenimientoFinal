#ifndef EQUIPO_NO_ENCONTRADO_EXCEPTION_H
#define EQUIPO_NO_ENCONTRADO_EXCEPTION_H

#include <exception>

class EquipoNoEncontradoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Equipo no encontrado";
    }
};

#endif