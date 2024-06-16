#include "DTReserva.h"

// Constructor
DTReserva::DTReserva()
{
    this->idConsulta = "";
    this->nombre = "";
    this->ci = "";
    this->medico = "";
    DTFecha fc = DTFecha();
    this->fechaReserva = fc;
    this->fechaConsulta = fc;
    DTHora hc = DTHora();
    this->horaConsulta = hc;
}

DTReserva::DTReserva(string idConsulta, string nombre, string ci, string medico, DTFecha fechaReserva, DTFecha fechaConsulta, DTHora horaConsulta) 
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
DTFecha DTReserva ::getFechaReserva()
{
    return this->fechaReserva;
}
DTFecha DTReserva ::getFechaConsulta()
{
    return this->fechaConsulta;
}
DTHora DTReserva ::getHoraConsulta()
{
    return this->horaConsulta;
}

void DTReserva::mostrarDatosReserva()
{
    std::cout << "mostrar" << std::endl;
}
DTReserva ::~DTReserva()
{
}