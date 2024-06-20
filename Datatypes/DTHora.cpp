#include "DTHora.h"

// Constructor
DTHora::DTHora() : hh(0), mm(0), ss(0){}
DTHora::DTHora(int hh, int mm, int ss) : hh(hh), mm(mm), ss(ss) {}
DTHora::DTHora(const DTHora &dth) : hh(dth.getHora()), mm(dth.getMin()), ss(dth.getSeg()){}
// Método para imprimir la fecha
void DTHora::imprimirDTHora()
{
    std::cout << std::setw(2) << std::setfill('0') << hh << ":"
              << std::setw(2) << std::setfill('0') << mm << ":"
              << ss << std::endl;
}

// Getters
int DTHora::getHora()const
{
    return hh;
}

int DTHora::getMin()const
{
    return mm;
}

int DTHora::getSeg()const
{
    return ss;
}
