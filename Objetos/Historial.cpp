#include "Historial.h"



Historial ::Historial() : listaDiagnosticos()
{
    this->historialSocio = NULL;
    this->medicoRealiza = NULL;
    DTConsulta dtCons = DTConsulta();
    this->consulta = dtCons;
}

Historial ::Historial(Socio *socio, Medico *medico, DTConsulta consulta, list <DTDiagnostico> diagnosticos)
{
    this->historialSocio = socio;
    this->medicoRealiza = medico;
    this->consulta = consulta;
    this->listaDiagnosticos = diagnosticos;
}
Historial ::Historial(Historial &historial)
{
    this->historialSocio = historial.getHistorialSocio();
    this->medicoRealiza = historial.getMedicoRealiza();
    this->consulta = historial.getConsulta();
    this->listaDiagnosticos = historial.getDiagnostico();
}

void Historial ::setHistorialSocio(Socio *socio)
{
    this->historialSocio = socio;
}
void Historial ::setMedicoRealiza(Medico *medico)
{
    this->medicoRealiza = medico;
}
void Historial ::setConsulta(DTConsulta consulta)
{
    this->consulta = consulta;
}
void Historial ::setDiagnostico(list <DTDiagnostico>  diagnostico)
{
    this->listaDiagnosticos = diagnostico;
}

Socio *Historial ::getHistorialSocio(){
    return this->historialSocio;
}
Medico *Historial ::getMedicoRealiza(){
    return this->medicoRealiza;
}
DTConsulta Historial ::getConsulta(){
    return this-> consulta;
}
list <DTDiagnostico> Historial ::getDiagnostico(){
    return this->listaDiagnosticos;
}

DTHistorial Historial ::getDatosHistorial(){}

Historial ::~Historial(){}