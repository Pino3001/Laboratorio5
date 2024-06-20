#ifndef DTCONSULTA_H
#define DTCONSULTA_H
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
using namespace std;

class DTConsulta
{
private:
    string idConsulta;
    string nombreSocio;
    string ciSocio;
    string nombreMedico;
    DTFecha fechaConsulta;
    DTHora horaConsulta;
public:
    DTConsulta();
    DTConsulta(string id, string nomSocio, string ciSocio, string nombreMedico, const DTFecha fechaConsul, const DTHora horaConsul);

    string getIdConsulta();
    string getNombreSocio();
    string getCiSocio();
    string getNombreMedico();
    DTFecha getFechaConsulta() const;
    DTHora getHoraConsulta()const;
};
#endif