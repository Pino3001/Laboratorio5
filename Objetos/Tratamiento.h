#ifndef Tratamiento_H
#define Tratamiento_H
#include <string>
#include "DTTratamiento.h"
using namespace std;

class Tratamiento
{
private:
    string descripcion;

public:
    // Constructores
    Tratamiento();
    Tratamiento(string descripcion);

    // Setters
    void setDescripcionTratamiento(string descripcion);
    // Getters
    string getDescripcionTratamiento();
    virtual DTTratamiento getDatoTratamiento() = 0;

    // Destructor
    virtual ~Tratamiento() = 0;
};
#endif