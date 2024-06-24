#include "Emergencia.h"
#include "Diagnostico.h"
#include "Usuario.h"
#include "Socio.h"
#include "Medico.h"
#include "DTConsulta.h"
#include <string>
#include <list>


// Constructor con parámetros
Emergencia::Emergencia(string motivo, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico)
    : Consulta(fecha, hora, socio, medico)
{
    this->motivoConsulta = motivo;
}
Emergencia::Emergencia(Emergencia &emergencia, Consulta &consulta, Actividad &actividad) : Consulta(consulta, actividad){
    this->motivoConsulta = emergencia.getMotivoConsulta();
}

// Setter
void Emergencia::setMotivoConsulta(string motivo)
{
    this->motivoConsulta = motivo;
}

// Getter
string Emergencia::getMotivoConsulta()const
{
    return this->motivoConsulta;
}
// Retorna un objeto DTConsulta con los datos correspondientes
DTConsulta Emergencia::getDatosConsulta()const
{
    Usuario * socio = this->getSocioConsulta()->getUsuarioVinculado();
    Usuario * medico = this->getMedicoRealiza()->getUsuarioVinculado();
    DTFecha fr;
    return DTConsulta(socio->getDatosUsuario(), medico->getDatosUsuario(), this->getDatosDiagnosticoConsulta(), this->motivoConsulta, this->getFechaConsulta(), this->getHoraConsulta(), fr, TipoConsulta::Tipo_Emergencia);
}

// Métodos adicionales

TipoConsulta Emergencia::obtenerTipoConsulta()const
{
    return TipoConsulta::Tipo_Emergencia;
}


// Destructor
Emergencia::~Emergencia(){}
