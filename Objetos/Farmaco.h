#ifndef Farmaco_H
#define Farmaco_H

#include "Tratamiento.h"
#include "DTFecha.h"

class Farmaco : public Tratamiento {
private:
    string nombreMedicamento;

public:
    // Constructores
    Farmaco();
    Farmaco(string nombreMedicamento);
    Farmaco(string descripcion, string nombreMedicamento);
    
    // Getters
    string getNombreMedicamento();

    // Setters
    void setNombreMedicamento(string nombreMedicamento);

    // Destructor
    virtual ~Farmaco();
};

#endif