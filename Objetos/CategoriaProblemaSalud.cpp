#include "CategoriaProblemaSalud.h"
#include "ProblemaDeSalud.h"

CategoriaProblemaSalud ::CategoriaProblemaSalud(string id, string descripcion) : idCategoria(id), descripcion(descripcion), problemas() {}

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
list<DTProblemaDeSalud> CategoriaProblemaSalud ::getDTProblemas(){
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



// Mostrar problemas de salud
set<DTProblemaDeSalud> *mostrarProblemasDeSalud()
{
}
// Selecciona un problema de salud
ProblemaDeSalud seleccionarProblemaDeSalud(string codigo, string etiqueta)
{
}

CategoriaProblemaSalud ::~CategoriaProblemaSalud() {}