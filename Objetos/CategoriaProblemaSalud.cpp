#include "CategoriaProblemaSalud.h"
#include "ProblemaDeSalud.h"
#include <list>
#include <string>
#include "DTProblemaDeSalud.h"

CategoriaProblemaSalud ::CategoriaProblemaSalud(string id, string descripcion) : idCategoria(id), descripcion(descripcion), problemas(new list<ProblemaDeSalud *> ) {}

// Setters
void CategoriaProblemaSalud ::setIdCategoria(string id)
{
    this->idCategoria = id;
}
void CategoriaProblemaSalud ::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
void CategoriaProblemaSalud ::setProblemas(list<ProblemaDeSalud *> *problemas)
{
    this->problemas = problemas;
}

// Getters
string CategoriaProblemaSalud ::getIdCategoria()
{
    return this->idCategoria;
}
string CategoriaProblemaSalud ::getDescripcion()
{
    return this->descripcion;
}
list<ProblemaDeSalud *> *CategoriaProblemaSalud ::getProblemas()
{
    return this->problemas;
}
DTCategoriaRep CategoriaProblemaSalud ::getDatosCategoria()
{
}

//Revisar!!
list<DTProblemaDeSalud> CategoriaProblemaSalud ::getDTProblemasAsoc(){
    list<DTProblemaDeSalud> ldtProb;
    for (ProblemaDeSalud *p : *this->problemas)
    {
        DTProblemaDeSalud dp = DTProblemaDeSalud(p->getCodigo(), p->getEtiqueta());
        ldtProb.push_back(dp);
    }
    return ldtProb;
    

}
// Crear problema de salud
void CategoriaProblemaSalud ::altaProblemas(string codigo, string etiqueta)
{
    ProblemaDeSalud *pds = new ProblemaDeSalud(codigo, etiqueta);
    this->problemas->push_back(pds);
}
// Selecciona un problema de salud
ProblemaDeSalud *CategoriaProblemaSalud ::seleccionarProblemaDeSalud(string codigo)
{
    for (ProblemaDeSalud *p : *this->problemas)
    {
        if (p->getCodigo() == codigo)
        {
            return p;
        }
    }
    return nullptr;
}


// Mostrar problemas de salud
set<DTProblemaDeSalud> *CategoriaProblemaSalud ::mostrarProblemasDeSalud()
{
}


CategoriaProblemaSalud ::~CategoriaProblemaSalud() {}