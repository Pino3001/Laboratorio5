#ifndef CATEGORIAPROBLEMASALUD_H
#define CATEGORIAPROBLEMASALUD_H
#include "DTCategoriaRep.h"
#include "DTProblemaDeSalud.h"
#include <string>
#include <set>
#include <list>
class ProblemaDeSalud;
using namespace std;

class CategoriaProblemaSalud
{
private:
    string idCategoria;
    string descripcion;
    list <ProblemaDeSalud*> *problemas;
public:
    CategoriaProblemaSalud(string id, string descr);

    void setIdCategoria(string id);
    void setDescripcion(string descripcion);
    void setProblemas(list<ProblemaDeSalud*> * problemas);

    string getIdCategoria();
    string getDescripcion();
    list<ProblemaDeSalud*> * getProblemas();
    DTCategoriaRep getDatosCategoria();
    list <DTProblemaDeSalud> getDTProblemasAsoc();

    void altaProblemas(string codigo, string etiqueta);
    set<DTProblemaDeSalud> *mostrarProblemasDeSalud();
    ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo);


    ~CategoriaProblemaSalud();
};
#endif