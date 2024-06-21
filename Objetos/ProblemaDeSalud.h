#ifndef PROBLEMADeSALUD_H
#define PROBLEMADeSALUD_H
#include "DTProblemaDeSalud.h"
#include <string>

using namespace std;

class ProblemaDeSalud {
private:
    string codigo;
    string etiqueta;

public:
    ProblemaDeSalud();
    ProblemaDeSalud(string codigo, string etiqueta);
 
    void setCodigo(string codigo);
    void setEtiqueta(string etiqueta);

    string getCodigo();
    string getEtiqueta();
    DTProblemaDeSalud getDatoProblema();

    ~ProblemaDeSalud();
};
#endif 