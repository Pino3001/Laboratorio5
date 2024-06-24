#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "CategoriaUsuario.h"
class Actividad;


class Administrativo : public CategoriaUsuario
{
private:

public:
    Administrativo();
    Actividad *buscarConsulta(string idConsulta);

    ~Administrativo();
};
#endif
