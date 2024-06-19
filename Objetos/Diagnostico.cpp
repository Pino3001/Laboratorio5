#include "Diagnostico.h"
#include "Tratamiento.h"
#include "Quirurgico.h"
#include "Farmaco.h"
#include "ProblemaDeSalud.h"
#include <list>
#include <set>
#include <string>
using namespace std;

// Constructor por defecto
Diagnostico::Diagnostico()
{
    this->descripcion = " ";
    this->tratamientos = new set<Tratamiento *>;
}
// Constructor con parametros
Diagnostico::Diagnostico(string descripcion)
{
    this->descripcion = descripcion;
    this->tratamientos = new set<Tratamiento *>;
    this->problemaDeSalud = new list<ProblemaDeSalud *>;
}

// Getters
string Diagnostico::getDescripcionDiagnostico()
{
    return this->descripcion;
}
set<Tratamiento *> *Diagnostico::getTratamientos()
{
    return this->tratamientos;
}
list<ProblemaDeSalud *> *Diagnostico::getProblemaDeSalud()
{
    return this->problemaDeSalud;
}


// Setter
void Diagnostico::setDescripcionDiagnostico(string descripcion)
{
    this->descripcion = descripcion;
}
void Diagnostico::setTratamiento(set<Tratamiento *> *tratamientos)
{

    this->tratamientos = tratamientos;
}
void Diagnostico::setProblemaDeSalud(list<ProblemaDeSalud *> *pds){
    this->problemaDeSalud = pds;
}

// Destructor
Diagnostico::~Diagnostico()
{
    // Liberar memoria de todos los tratamientos
}

// A CHEQUEAR!

// Método para agregar tratamiento quirúrgico
void Diagnostico::agregarTratamientoQuirurgico(string descripcion, DTFecha fecha)
{
    Quirurgico *tratamiento = new Quirurgico(descripcion, fecha);
    this->tratamientos->insert(tratamiento);
}

// Método para agregar tratamiento fármaco
void Diagnostico::agregarTratamientoFarmaco(list<string> *listMedicamentos, string descripcion)
{
        Farmaco *tratamiento = new Farmaco(descripcion, listMedicamentos);
        tratamientos->insert(tratamiento);
}
