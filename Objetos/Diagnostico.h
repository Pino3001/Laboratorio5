#ifndef Diagnostico_H
#define Diagnostico_H
#include "DTFecha.h"
#include "DTDiagnostico.h"
#include "DTProblemaDeSalud.h"
#include "DTTratamiento.h"
class Tratamiento;
class Quirurgico;
class Farmaco;
class ProblemaDeSalud;
class Medico;
#include <list>
#include <string>
using namespace std;

class Diagnostico
{
private:
    string descripcion;
    list<Tratamiento *> *tratamientos;
    list<ProblemaDeSalud *> *problemaDeSalud;

public:
    // Constructores
    Diagnostico(string descripcion, list<ProblemaDeSalud *> *problemaDeSalud);
    Diagnostico();

    // Setters
    void setDescripcionDiagnostico(string descripcion);
    void setTratamiento(list<Tratamiento *> *tratamientos);
    void setProblemaDeSalud(list<ProblemaDeSalud *> *pds);

    // Getters
    string getDescripcionDiagnostico();
    list<Tratamiento *> *getTratamientos();
    list<ProblemaDeSalud *> *getProblemaDeSalud();
    DTDiagnostico getDatosDiagnostico();
    list<DTProblemaDeSalud> getDatosProblemasAsociados();
    list<DTTratamiento> getDatosTratamientosAsocioados();

    // Métodos adicionales A CHEQUEAR!

    void agregarTratamientoQuirurgico(string descripcion, const DTFecha fecha, Medico *medico);
    void agregarTratamientoFarmaco(list<string> *listMedicamentos, string descripcion);

    // Destructor
    ~Diagnostico();
};

#endif