#include "DTHora.h"

// Constructor
DTHora::DTHora() : hh(0), mm(0), ss(0){}
DTHora::DTHora(int hh, int mm, int ss) : hh(hh), mm(mm), ss(ss) {}
DTHora::DTHora(DTHora &dth) : hh(dth.getHora()), mm(dth.getMin()), ss(dth.getSeg()){}
// Método para imprimir la fecha
void DTHora::imprimirDTHora()
{
    std::cout << std::setw(2) << std::setfill('0') << hh << ":"
              << std::setw(2) << std::setfill('0') << mm << ":"
              << ss << std::endl;
}

// Getters
int DTHora::getHora()
{
    return hh;
}

int DTHora::getMin()
{
    return mm;
}

int DTHora::getSeg()
{
    return ss;
}
