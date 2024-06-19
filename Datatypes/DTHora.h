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
    DTHora(DTHora &dth);
    DTHora(int hh, int mm, int ss);

    int getHora();
    int getMin();
    int getSeg();

    void imprimirDTHora();
};
#endif