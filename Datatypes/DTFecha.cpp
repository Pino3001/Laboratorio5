#include "DTFecha.h"

// Constructor
DTFecha::DTFecha() : dia(0), mes(0), anio(0) {}
DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
DTFecha::DTFecha(DTFecha &dtf) : dia(dtf.getDia()), mes(dtf.getMes()), anio(dtf.getAnio()) {}

// Método para imprimir la fecha
void DTFecha::imprimirDTFecha()
{
    std::cout << std::setw(2) << std::setfill('0') << dia << "/"
              << std::setw(2) << std::setfill('0') << mes << "/"
              << anio << std::endl;
}

// Getters
int DTFecha::getDia()
{
    return dia;
}

int DTFecha::getMes()
{
    return mes;
}

int DTFecha::getAnio()
{
    return anio;
}
