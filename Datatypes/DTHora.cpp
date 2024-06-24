#include "DTHora.h"

// Constructor
DTHora::DTHora() : hh(0), mm(0), ss(0) {}
DTHora::DTHora(int hh, int mm, int ss) : hh(hh), mm(mm), ss(ss) {}
DTHora::DTHora(const DTHora &dth) : hh(dth.getHora()), mm(dth.getMin()), ss(dth.getSeg()) {}
// Método para imprimir la fecha
void DTHora::imprimirDTHora() const
{
    std::cout << std::setw(2) << std::setfill('0') << hh << ":"
              << std::setw(2) << std::setfill('0') << mm << ":"
              << std::setw(2) << std::setfill('0') << ss << std::endl;
}

// Getters
int DTHora::getHora() const
{
    return hh;
}

int DTHora::getMin() const
{
    return mm;
}

int DTHora::getSeg() const
{
    return ss;
}

// operador de asignación
DTHora &DTHora::operator=(const DTHora &other)
{
    if (this != &other)
    { // Evita la auto-asignación
        this->hh = other.hh;
        this->mm = other.mm;
        this->ss = other.ss;
    }
    return *this;
}