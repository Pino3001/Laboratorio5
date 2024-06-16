#ifndef Tratamiento_H
#define Tratamiento_H

#include <string>
using namespace std;

class Tratamiento {
private:
    string descripcion;

public:
    // Constructores
    Tratamiento();
    Tratamiento(string descripcion);
    
    // Getters
    string getDescripcionTratamiento();

    // Setters
    void setDescripcionTratamiento(string descripcion);

    // Destructor
    virtual ~Tratamiento() = 0;
};
#endif 