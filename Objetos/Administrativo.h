#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "CategoriaUsuario.h"


class Administrativo : public CategoriaUsuario
{
private:

public:
    Administrativo();

    string verNombre();
    ~Administrativo();
};
#endif