#include "Historial.h"

#include "Usuario.h"
#include "Socio.h"
#include "Medico.h"

#include "string.h"
using namespace std;


Historial ::Historial()
{
    this->historialSocio = NULL;
    this->medicoRealiza = NULL;
    DTConsulta dtCons = DTConsulta();
    this->consulta = dtCons;
    list <DTDiagnostico> *diagnosticos = new list <DTDiagnosticos>;
    this->listaDiagnosticos = diagnosticos;
}

Historial ::Historial(Socio socio, Medico medico, DTConsulta consulta, list <DTDiagnosticos> *diagnosticos)
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
void Historial ::setDiagnostico(list <DTDiagnosticos>  *diagnostico)
{
    this->listaDiagnosticos = diagnostico;
}

Socio *Historial ::getHistorialSocio(){
    return this->historialSocio;
}
Medico *Historial ::gerMedicoRealiza(){
    return this->medicoRealiza;
}
DTConsulta Historial ::getConsulta(){
    return this-> consulta;
}
list <DTDiagnosticos> *Historial ::getDiagnostico(){
    return this->listaDiagnosticos;
}

DTHistorial getDatosHistorial();

~Historial();