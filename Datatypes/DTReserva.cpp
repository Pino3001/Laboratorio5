#include "DTReserva.h"

// Constructor
DTReserva::DTReserva()
{
    this->idConsulta = "";
    this->nombre = "";
    this->ci = "";
    this->medico = "";
    DTFecha fc;
    this->fechaReserva = fc;
    this->fechaConsulta = fc;
    DTHora hc;
    this->horaConsulta = hc;
}

DTReserva::DTReserva(string idConsulta, string nombre, string ci, string medico, const DTFecha fechaReserva, const DTFecha fechaConsulta, const DTHora horaConsulta) 
: idConsulta(idConsulta), nombre(nombre), ci(ci), medico(medico), fechaReserva(fechaReserva), fechaConsulta(fechaConsulta), horaConsulta(horaConsulta)
{}

DTReserva::DTReserva(DTReserva &dtr)
{
    this->idConsulta = dtr.idConsulta;
    this->nombre = dtr.nombre;
    this->ci = dtr.ci;
    this->medico = dtr.medico;
    this->fechaReserva = dtr.fechaReserva;
    this->fechaConsulta = dtr.fechaConsulta;
    this->horaConsulta = dtr.horaConsulta;
}

// Getters
string DTReserva ::getIdConsulta()
{
    return this->idConsulta;
}
string DTReserva ::getNombre()
{
    return this->nombre;
}
string DTReserva ::getCi()
{
    return this->ci;
}
string DTReserva ::getMedico(){
    return this->medico;
}
DTFecha DTReserva ::getFechaReserva()const
{
    return this->fechaReserva;
}
DTFecha DTReserva ::getFechaConsulta()const
{
    return this->fechaConsulta;
}
DTHora DTReserva ::getHoraConsulta()const
{
    return this->horaConsulta;
}

void DTReserva::mostrarDatosReserva()
{
    std::cout << "mostrar" << std::endl;
}
