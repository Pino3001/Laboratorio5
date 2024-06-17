#include "DTHistorial.h"


DTHistorial::DTHistorial(): nombreSocio(""), ciSocio(""), nombreMedico("") {
    DTConsulta c = DTConsulta();
    this->consulta = c;
    this->diagnosticos = new list<DTDiagnostico>;
}

DTHistorial ::DTHistorial(string nombreSocio, string ciSocio, string nombreMedico, DTConsulta consulta, list<DTDiagnostico> *diagnosticos)
    : nombreSocio(nombreSocio), ciSocio(ciSocio), nombreMedico(nombreMedico), consulta(consulta), diagnosticos(diagnosticos) {}

string DTHistorial::getNombreSocio() {
    return nombreSocio;
}

string DTHistorial::getCiSocio() {
    return ciSocio;
}

string DTHistorial::getNombreMedico() {
    return nombreMedico;
}

DTConsulta DTHistorial::getConsulta() {
    return consulta;
}

list<DTDiagnostico> *DTHistorial::getDiagnosticos() {
    return diagnosticos;
}

DTHistorial::~DTHistorial()
{
}

