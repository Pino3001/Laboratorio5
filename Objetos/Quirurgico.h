#ifndef Quirurgico_H
#define Quirurgico_H
#include "DTFecha.h"
class Tratamiento;
class Medico;

class Quirurgico : public Tratamiento
{
private:
    DTFecha fechaCirugia;
    Medico *cirujanoOperacion;

public:
    // Constructores
    Quirurgico(string descripcion, DTFecha fechaCirugia, Medico *cirujano);
    Quirurgico(string descripcion, DTFecha fechaCirugia);

    // Getters
    DTFecha getFechaCirugia();
    Medico *getCirujanoOperacion();

    // Setters
    void setFechaCirugia(DTFecha fechaCirugia);
    void setCirujanoOperacion(Medico *cirujano);

    // Destructor
    ~Quirurgico();
};
#endif