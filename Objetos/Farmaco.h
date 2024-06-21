#ifndef Farmaco_H
#define Farmaco_H
#include "Tratamiento.h"
#include "DTTratamiento.h"
#include "DTFecha.h"
#include <list>
#include <string>
using namespace std;

class Farmaco : public Tratamiento {
private:
    list <string> *nombreMedicamento;

public:
    // Constructores
    Farmaco();
    Farmaco(string descripcion, list <string> *nombreMedicamento);

    // Setters
    void setListaMedicamentos(list <string> *nombreMedicamento);
        // Getters
    list<string>* getListaMedicamentos();
    DTTratamiento getDatoTratamiento();

    // Destructor
     ~Farmaco();
};

#endif