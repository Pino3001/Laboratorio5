#ifndef DTCONSULTA_H
#define DTCONSULTA_H
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "definiciones.h"
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
    TipoConsulta tipo;
public:
    DTConsulta();
    DTConsulta(string nomSocio, string ciSocio, string nombreMedico, const DTFecha fechaConsul, const DTHora horaConsul, TipoConsulta tipo);

    string getNombreSocio();
    string getCiSocio();
    string getNombreMedico();
    DTFecha getFechaConsulta() const;
    DTHora getHoraConsulta()const;
    TipoConsulta getTipo();
};
#endif