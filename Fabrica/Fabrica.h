#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "IRegistroMedico.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    IUsuario* getIUsuario();
    IRegistroMedico *getIRegistroMedico();
    ~Fabrica();
};

#endif 