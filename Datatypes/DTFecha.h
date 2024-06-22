#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>


using namespace std;

class DTFecha
{

private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(const DTFecha &dtf);
    DTFecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Declaración de operadores de comparación
    bool operator==(const DTFecha& other) const;
    bool operator!=(const DTFecha& other) const;
    bool operator<(const DTFecha& other) const;
    bool operator<=(const DTFecha& other) const;
    bool operator>(const DTFecha& other) const;
    bool operator>=(const DTFecha& other) const;

    void imprimirDTFecha();
};
#endif