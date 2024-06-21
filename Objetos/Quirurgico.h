#ifndef Quirurgico_H
#define Quirurgico_H
#include "DTFecha.h"
#include "Tratamiento.h"
class Medico;

class Quirurgico : public Tratamiento
{
private:
    DTFecha fechaCirugia;
    Medico *cirujanoOperacion;

public:
    // Constructores
    Quirurgico(string descripcion, const DTFecha fechaCirugia, Medico *cirujano);
    Quirurgico(string descripcion, DTFecha fechaCirugia);

    // Setters
    void setFechaCirugia(const DTFecha fechaCirugia);
    void setCirujanoOperacion(Medico *cirujano);
    // Getters
    DTFecha getFechaCirugia()const;
    Medico *getCirujanoOperacion();
    DTTratamiento getDatoTratamiento();

    // Destructor
    ~Quirurgico();
};
#endif