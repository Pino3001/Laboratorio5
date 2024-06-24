#include "DTCategoriaRep.h"
#include <string>
#include "iostream"
#include <iomanip>

DTCategoriaRep::DTCategoriaRep() : idCategoria(""), descripcion(""), problemasAsoc() {}

DTCategoriaRep::DTCategoriaRep(string id, string descripcion) : idCategoria(id), descripcion(descripcion), problemasAsoc() {}

DTCategoriaRep::DTCategoriaRep(string id, string descripcion, list<DTProblemaDeSalud> problemas) : idCategoria(id), descripcion(descripcion), problemasAsoc(problemas) {}

string DTCategoriaRep::getIdCategoria()
{
    return this->idCategoria;
}
string DTCategoriaRep::getDescripcion()
{
    return this->descripcion;
}
list<DTProblemaDeSalud> DTCategoriaRep::getProblemaAsoc()
{
    return this->problemasAsoc;
}

void DTCategoriaRep::mostrarCategoria()
{

    cout << "\n\t" << this->idCategoria << ": " << this->descripcion << "\n\n";
    for(DTProblemaDeSalud pds : this->problemasAsoc)
    {
        cout << "\t\t" <<pds.getCodigo() << " " << pds.getEtiqueta() << "\n";
    }
}
