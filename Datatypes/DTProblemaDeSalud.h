#ifndef DTPROBLEMADESALUD_H
#define DTPROBLEMADESALUD_H
#include <string>
using namespace std;

class DTProblemaDeSalud
{
private:
    string codigo;
    string etiqueta;
public:
    DTProblemaDeSalud();
    DTProblemaDeSalud(string codigo, string etiqueta);

    string getCodigo();
    string getEtiqueta();

    ~DTProblemaDeSalud();
};
#endif
