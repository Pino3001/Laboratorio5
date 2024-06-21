#include "Diagnostico.h"
#include "Tratamiento.h"
#include "Quirurgico.h"
#include "Medico.h"
#include "Farmaco.h"
#include "ProblemaDeSalud.h"
#include "DTProblemaDeSalud.h"
#include "DTTratamiento.h"
#include <list>
#include <set>
#include <string>
using namespace std;

/* // Constructor por defecto
Diagnostico::Diagnostico()
{
    this->descripcion = " ";
    this->tratamientos = new set<Tratamiento *>;
} */
// Constructor con parametros
Diagnostico::Diagnostico(string descripcion, list<ProblemaDeSalud *> *problemaDeSalud)
{
    this->descripcion = descripcion;
    this->tratamientos = new list<Tratamiento *>;
    this->problemaDeSalud = problemaDeSalud;
}

// Setter
void Diagnostico::setDescripcionDiagnostico(string descripcion)
{
    this->descripcion = descripcion;
}
void Diagnostico::setTratamiento(list<Tratamiento *> *tratamientos)
{

    this->tratamientos = tratamientos;
}
void Diagnostico::setProblemaDeSalud(list<ProblemaDeSalud *> *pds)
{
    this->problemaDeSalud = pds;
}

// Getters
string Diagnostico::getDescripcionDiagnostico()
{
    return this->descripcion;
}
list<Tratamiento *> *Diagnostico::getTratamientos()
{
    return this->tratamientos;
}
list<ProblemaDeSalud *> *Diagnostico::getProblemaDeSalud()
{
    return this->problemaDeSalud;
}
DTDiagnostico Diagnostico::getDatosDiagnostico()
{
    DTDiagnostico dtd(this->descripcion, this->getDatosProblemasAsociados(), this->getDatosTratamientosAsocioados());
}
list<DTProblemaDeSalud> Diagnostico::getDatosProblemasAsociados()
{
    list<DTProblemaDeSalud> listPDS;
    for (ProblemaDeSalud *ps : *this->problemaDeSalud)
    {
        DTProblemaDeSalud dps = ps->getDatoProblema();
        listPDS.push_back(dps);
    }
    return listPDS;
}
list<DTTratamiento> Diagnostico::getDatosTratamientosAsocioados()
{
    list<DTTratamiento> lTra;
    for (Tratamiento *t : *this->tratamientos)
    {
        DTTratamiento dtt = t->getDatoTratamiento();
        lTra.push_back(dtt);
    }
    return lTra;
}

// Destructor
Diagnostico::~Diagnostico()
{
    // Liberar memoria de todos los tratamientos
}

// A CHEQUEAR!

// Método para agregar tratamiento quirúrgico
void Diagnostico::agregarTratamientoQuirurgico(string descripcion, const DTFecha fecha, Medico *med)
{
    Quirurgico *tratamiento = new Quirurgico(descripcion, fecha, med);
    this->tratamientos->push_back(tratamiento);
}

// Método para agregar tratamiento fármaco
void Diagnostico::agregarTratamientoFarmaco(list<string> *listMedicamentos, string descripcion)
{
    Farmaco *tratamiento = new Farmaco(descripcion, listMedicamentos);
    tratamientos->push_back(tratamiento);
}
