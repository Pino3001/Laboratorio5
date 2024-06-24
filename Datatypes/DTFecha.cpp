#include "DTFecha.h"
#include <iomanip> // Para std::setw y std::setfill

// Constructor
DTFecha::DTFecha() : dia(0), mes(0), anio(0) {}
DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
DTFecha::DTFecha(const DTFecha &dtf) : dia(dtf.getDia()), mes(dtf.getMes()), anio(dtf.getAnio()) {}

// Getters
int DTFecha::getDia() const
{
    return dia;
}

int DTFecha::getMes() const
{
    return mes;
}

int DTFecha::getAnio() const
{
    return anio;
}

// Implementacion operadores de comparacion.
bool DTFecha::operator==(const DTFecha &other) const
{
    return (this->dia == other.dia && this->mes == other.mes && this->anio == other.anio);
}
bool DTFecha::operator!=(const DTFecha &other) const
{
    return !(*this == other);
}
bool DTFecha::operator<(const DTFecha &other) const
{
    if (this->anio < other.anio)
        return true;
    if (this->anio > other.anio)
        return false;
    if (this->mes < other.mes)
        return true;
    if (this->mes > other.mes)
        return false;
    return dia < other.dia;
}
bool DTFecha::operator<=(const DTFecha &other) const
{
    return (*this < other || *this == other);
}
bool DTFecha::operator>(const DTFecha &other) const
{
    return !(*this <= other);
}
bool DTFecha::operator>=(const DTFecha &other) const
{
    return !(*this < other);
}

// operador de asignación
DTFecha &DTFecha::operator=(const DTFecha &other)
{
    if (this != &other)
    { // Evita la auto-asignación
        this->dia = other.dia;
        this->mes = other.mes;
        this->anio = other.anio;
    }
    return *this;
}

// Método para imprimir la fecha
void DTFecha::imprimirDTFecha() const
{
    std::cout << std::setw(2) << std::setfill('0') << dia << "/"
              << std::setw(2) << std::setfill('0') << mes << "/"
              << anio << std::endl;
}