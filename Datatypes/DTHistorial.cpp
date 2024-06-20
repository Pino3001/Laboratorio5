#include "DTHistorial.h"
#include "DTConsulta.h"
#include "DTDiagnostico.h"
#include "DTHora.h"
#include "DTFecha.h"
#include <list>
#include <string>
using namespace std;

DTHistorial::DTHistorial(): nombreSocio(""), ciSocio(""), nombreMedico(""), diagnosticos() {
    DTConsulta c;
    this->consulta = c;
}

DTHistorial ::DTHistorial(string nombreSocio, string ciSocio, string nombreMedico, DTConsulta consulta, list<DTDiagnostico> diagnosticos)
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

list<DTDiagnostico> DTHistorial::getDiagnosticos() {
    return diagnosticos;
}



