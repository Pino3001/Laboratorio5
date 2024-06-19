#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
#include <iomanip> // Para std::setw y std::setfill

using namespace std;

class DTFecha
{

private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(DTFecha &dtf);
    DTFecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    void imprimirDTFecha();
};
#endif