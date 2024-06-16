#ifndef Diagnostico_H
#define Diagnostico_H

#include "DTFecha.h"
#include "Tratamiento.h"
#include "Quirurgico.h"
#include "Farmaco.h"
#include <list>
#include <set>
#include <string>

using namespace std;

class Diagnostico {
private:
    string descripcion;
    set<Tratamiento*> *tratamientos;
    list <ProblemaDeSalud*> problemaDeSalud;

public:
    // Constructores
    Diagnostico(string descripcion);
    Diagnostico();

    // Getters
    string getDescripcionDiagnostico();
    set<Tratamiento*>* getTratamientos(); 
    list <ProblemaDeSalud*> getProblemaDeSalud();

    // Setters
    void setDescripcionDiagnostico(string descripcion);
    void setTratamiento(set <Tratamiento*> *tratamientos);
    void setProblemaDeSalud(list <ProblemaDeSalud*> *pds);

    // Métodos adicionales A CHEQUEAR!
    
    Tratamiento agregarTratamientoQuirurgico(string descripcion, DTFecha fecha);
    void agregarTratamientoFarmaco(set<string> listMedicamentos);

    // Destructor
    ~Diagnostico();
};

#endif 