#ifndef DTCATEGORIAREP_H
#define DTCATEGORIAREP_H
#include "DTProblemaDeSalud.h"
#include <string>
#include <list>
using namespace std;

class DTCategoriaRep
{
private:
    string idCategoria;
    string descripcion;
    list<DTProblemaDeSalud> problemasAsoc;

public:
    DTCategoriaRep();
    DTCategoriaRep(string id, string descripcion);
    DTCategoriaRep(string id, string descripcion, list<DTProblemaDeSalud> problemas);

    string getIdCategoria();
    string getDescripcion();
    list<DTProblemaDeSalud> getProblemaAsoc();

    void mostrarCategoria();

};
#endif


