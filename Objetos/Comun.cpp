#include "Comun.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
#include "Consulta.h"
#include "Socio.h"
#include "Medico.h"
#include "Usuario.h"
#include "DTConsulta.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "definiciones.h"
#include <string>

Comun::Comun(const DTFecha fechaReserva, EstadoConsulta estConsulta, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico) : Consulta(fecha, hora, socio, medico)
{

    this->fechaReserva = fechaReserva;
    this->estadoConsulta = estConsulta;
}
Comun::Comun(Comun &comun) : Consulta(comun)
{
    this->fechaReserva = comun.getFechaReserva();
    this->estadoConsulta = comun.getEstadoConsulta();
}

// Setters
void Comun::setFechaReserva(const DTFecha fechaReserva)
{
    this->fechaReserva = fechaReserva;
}
void Comun::setEstadoConsulta(EstadoConsulta estadoConsulta)
{
    this->estadoConsulta = estadoConsulta;
}

// Getters
DTFecha Comun::getFechaReserva() const
{
    return this->fechaReserva;
}
EstadoConsulta Comun::getEstadoConsulta()const
{
    return this->estadoConsulta;
}
DTConsulta Comun::getDatosConsulta()const
{
    Usuario * socio = this->getSocioConsulta()->getUsuarioVinculado();
    Usuario * medico = this->getMedicoRealiza()->getUsuarioVinculado();
    return DTConsulta(socio->getDatosUsuario(), medico->getDatosUsuario(), this->getDatosDiagnosticoConsulta(), "", this->getFechaConsulta(), this->getHoraConsulta(), this->fechaReserva, TipoConsulta::Tipo_Comun);
}

TipoConsulta Comun::obtenerTipoConsulta()const
{
    return TipoConsulta::Tipo_Comun;
}

// Destructor
Comun::~Comun(){}
