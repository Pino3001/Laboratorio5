#ifndef DTHISTORIAL_H
#define DTHISTORIAL_H
#include "DTConsulta.h"
#include "DTDiagnostico.h"
#include <list>
#include <string>
using namespace std;

class DTHistorial
{
private:
    string nombreSocio;
    string ciSocio;
    string nombreMedico;
    DTConsulta consulta;
    list <DTDiagnostico> *diagnosticos;
public:
    DTHistorial ();
    DTHistorial(string nombreSocio, string ciSocio, string nombreMedico, DTConsulta consulta, list <DTDiagnostico> diagnostico);

    string getNombreSocio();
    string getCiSocio();
    string getNombreMedico();
    DTConsulta getConsulta();
    list<DTDiagnostico> *getDiagnosticos();

    ~DTHistorial();
};
#endif