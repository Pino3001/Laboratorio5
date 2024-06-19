#include "DTConsulta.h"

DTConsulta::DTConsulta() : idConsulta(""), nombreSocio(""), ciSocio(""), nombreMedico("")
{
    DTFecha fc;
    this->fechaConsulta = fc;
    DTHora hc;
    this->horaConsulta = hc;
}
DTConsulta::DTConsulta(string id, string nomSocio, string ciSocio, string nombreMedico, DTFecha fechaConsul, DTHora horaConsul)
    : idConsulta(id), nombreSocio(nomSocio), ciSocio(ciSocio), nombreMedico(nombreMedico), fechaConsulta(fechaConsul), horaConsulta(horaConsul) {}

string DTConsulta::getIdConsulta()
{
    return this->idConsulta;
}

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

DTFecha DTConsulta::getFechaConsulta()
{
    return this->fechaConsulta;
}

DTHora DTConsulta::getHoraConsulta()
{
    return this->horaConsulta;
}
