#ifndef PROBLEMADeSALUD_H
#define PROBLEMADeSALUD_H

#include "Diagnostico.h"
#include <string>

using namespace std;

class ProblemaDeSalud {
private:
    string codigo;
    string etiqueta;

public:
    ProblemaDeSalud();
    ProblemaDeSalud(string codigo, string etiqueta);

    string getCodigo();
    string getEtiqueta();
    
    void setCodigo(string codigo);
    void setEtiqueta(string etiqueta);

    ~Problema_Salud();
};

#endif 