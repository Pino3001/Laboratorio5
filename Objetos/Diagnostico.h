#ifndef Diagnostico_H
#define Diagnostico_H
#include "DTFecha.h"
class Tratamiento;
class Quirurgico;
class Farmaco;
class ProblemaDeSalud;
#include <list>
#include <set>
#include <string>

using namespace std;

class Diagnostico {
private:
    string descripcion;
    set<Tratamiento*> *tratamientos;
    list <ProblemaDeSalud*> *problemaDeSalud;

public:
    // Constructores
    Diagnostico(string descripcion);
    Diagnostico();

    // Getters
    string getDescripcionDiagnostico();
    set<Tratamiento*>* getTratamientos(); 
    list <ProblemaDeSalud*> *getProblemaDeSalud();

    // Setters
    void setDescripcionDiagnostico(string descripcion);
    void setTratamiento(set <Tratamiento*> *tratamientos);
    void setProblemaDeSalud(list <ProblemaDeSalud*> *pds);

    // Métodos adicionales A CHEQUEAR!
    
    void agregarTratamientoQuirurgico(string descripcion, const DTFecha fecha);
    void agregarTratamientoFarmaco(list<string> *listMedicamentos, string descripcion);

    // Destructor
    ~Diagnostico();
};

#endif 