cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(untitled4
        src/main.cpp
        src/Equipo.cpp
        src/Incidencia.cpp
        src/MantenimientoBasico.cpp
        src/MantenimientoCompleto.cpp
        include/Equipo.h
        src/Equipo.cpp
        include/Incidencia.h
        src/Incidencia.cpp
        include/MantenimientoStrategy.h
        include/MantenimientoBasico.h
        src/MantenimientoBasico.cpp
        include/MantenimientoCompleto.h
        src/MantenimientoCompleto.cpp
        src/Main.cpp
        include/SistemaMantenimiento.h
        src/SistemaMantenimiento.cpp
        include/EquipoNoEncontradoException.h

)
