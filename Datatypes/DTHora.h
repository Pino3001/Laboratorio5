#ifndef DTHORA_H
#define DTHORA_H
#include <iostream>
#include <iomanip> // Para std::setw y std::setfill
#include <string>
using namespace std;

class DTHora
{

private:
    int hh;
    int mm;
    int ss;

public:
    DTHora();
    DTHora(const DTHora &dth);
    DTHora(int hh, int mm, int ss);

    int getHora() const;
    int getMin() const;
    int getSeg() const;

    void imprimirDTHora() const;

    // Operador de asignación
    DTHora &operator=(const DTHora &other);
};
#endif