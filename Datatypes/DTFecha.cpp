#include "DTFecha.h"

// Constructor
DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

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
