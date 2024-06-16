#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    IUsuario* getIUsuarior();
    ~Fabrica();
};

#endif 