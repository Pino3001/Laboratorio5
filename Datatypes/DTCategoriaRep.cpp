#include "DTCategoriaRep.h"

DTCategoriaRep::DTCategoriaRep() : idCategoria(""), descripcion(""), problemasAsoc(){}

DTCategoriaRep::DTCategoriaRep(string id, string descripcion) : idCategoria(id), descripcion(descripcion), problemasAsoc() {}

DTCategoriaRep::DTCategoriaRep(string id, string descripcion, list<DTProblemaDeSalud> problemas) : idCategoria(id), descripcion(descripcion), problemasAsoc(problemas){}

string DTCategoriaRep::getIdCategoria(){
    return this->idCategoria;
}
string DTCategoriaRep::getDescripcion(){
    return this->descripcion;
}
list<DTProblemaDeSalud> DTCategoriaRep::getProblemaAsoc(){
    return this->problemasAsoc;
}

void DTCategoriaRep::mostrarCategoria(){
    //Imprimir solo id y descripcion!!!
}
