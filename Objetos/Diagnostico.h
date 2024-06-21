#ifndef Diagnostico_H
#define Diagnostico_H
#include "DTFecha.h"
class Tratamiento;
class Quirurgico;
class Farmaco;
class ProblemaDeSalud;
class Medico;
#include <list>
#include <set>
#include <string>

using namespace std;

class Diagnostico {
private:
    string descripcion;
    list<Tratamiento*> *tratamientos;
    list <ProblemaDeSalud*> *problemaDeSalud;

public:
    // Constructores
    Diagnostico(string descripcion, list <ProblemaDeSalud*> *problemaDeSalud);
    Diagnostico();

    // Getters
    string getDescripcionDiagnostico();
    list<Tratamiento*>* getTratamientos(); 
    list <ProblemaDeSalud*> *getProblemaDeSalud();

    // Setters
    void setDescripcionDiagnostico(string descripcion);
    void setTratamiento(list <Tratamiento*> *tratamientos);
    void setProblemaDeSalud(list <ProblemaDeSalud*> *pds);

    // Métodos adicionales A CHEQUEAR!
    
    void agregarTratamientoQuirurgico(string descripcion, const DTFecha fecha, Medico *medico);
    void agregarTratamientoFarmaco(list<string> *listMedicamentos, string descripcion);

    // Destructor
    ~Diagnostico();
};

#endif 