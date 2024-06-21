#include "DTConsulta.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
using namespace std;

DTConsulta::DTConsulta() : idConsulta(""), nombreSocio(""), ciSocio(""), nombreMedico("")
{
    DTFecha fc;
    this->fechaConsulta = fc;
    DTHora hc;
    this->horaConsulta = hc;
}
DTConsulta::DTConsulta(string nomSocio, string ciSocio, string nombreMedico, const DTFecha fechaConsul, const DTHora horaConsul)
    : nombreSocio(nomSocio), ciSocio(ciSocio), nombreMedico(nombreMedico), fechaConsulta(fechaConsul), horaConsulta(horaConsul) {}


string DTConsulta::getNombreSocio()
{
    return this->nombreSocio;
}

string DTConsulta::getCiSocio()
{
    return this->ciSocio;
}

string DTConsulta::getNombreMedico()
{
    return this->nombreMedico;
}

DTFecha DTConsulta::getFechaConsulta() const
{
    return this->fechaConsulta;
}

DTHora DTConsulta::getHoraConsulta() const
{
    return this->horaConsulta;
}
