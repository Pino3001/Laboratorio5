#include "Historial.h"
#include "Consulta.h"
#include "Diagnostico.h"
#include "Medico.h"
#include "Socio.h"



/* Historial ::Historial() : listaDiagnosticos()
{
    this->historialSocio = NULL;
    this->medicoRealiza = NULL;
    DTConsulta dtCons;
    this->consulta = dtCons;
} */

Historial ::Historial(Socio *socio, Medico *medico, Consulta *consulta, list <Diagnostico*> *diagnosticos)
{
    this->historialSocio = socio;
    this->medicoRealiza = medico;
    this->consulta = consulta;
    this->listaDiagnosticos = diagnosticos;
}
Historial ::Historial(Historial &historial) : historialSocio(historial.getHistorialSocio()), medicoRealiza(historial.getMedicoRealiza()), consulta(historial.getConsulta()), listaDiagnosticos(historial.getDiagnostico()){}
//Setters
void Historial ::setHistorialSocio(Socio *socio)
{
    this->historialSocio = socio;
}
void Historial ::setMedicoRealiza(Medico *medico)
{
    this->medicoRealiza = medico;
}
void Historial ::setConsulta(Consulta *consulta)
{
    this->consulta = consulta;
}
void Historial ::setDiagnostico(list <Diagnostico*>  *diagnostico)
{
    this->listaDiagnosticos = diagnostico;
}
//Getters
Socio *Historial ::getHistorialSocio(){
    return this->historialSocio;
}
Medico *Historial ::getMedicoRealiza(){
    return this->medicoRealiza;
}
Consulta* Historial ::getConsulta(){
    return this-> consulta;
}
list <Diagnostico*> *Historial ::getDiagnostico(){
    return this->listaDiagnosticos;
}



DTHistorial Historial ::getDatosHistorial(){
    DTHistorial dth(this->historialSocio->verNombre(), this->historialSocio->verNombre(), this->medicoRealiza->verNombre(), this->consulta->getDatosConsulta(), this->consulta->getDatosDiagnosticoConsulta());
    return dth;
}


bool Historial::operator<(const Historial &hist) const
{
    if (this->medicoRealiza->verCi() != hist.medicoRealiza->verCi())
    {
        return this->medicoRealiza->verCi() < hist.medicoRealiza->verCi();
    }
    return this->consulta->getFechaConsulta() < hist.consulta->getFechaConsulta();
}

Historial ::~Historial(){}