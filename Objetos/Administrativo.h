#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "CategoriaUsuario.h"
class Actividad;


class Administrativo : public CategoriaUsuario
{
private:

public:
    Administrativo();

    string verNombre();
    string verCi();
    Actividad *buscarConsulta(string idConsulta);

    ~Administrativo();
};
#endif