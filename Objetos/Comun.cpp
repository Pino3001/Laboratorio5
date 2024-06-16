#include "Comun.h"


Comun::Comun(DTFecha fecha, EstadoConsulta estConsulta, string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio) : Consulta(idConsulta, fecha, hora, socio, medico, nombreMedico, ciMedico, nombreSocio, ciSocio)
{
    this->fechaReserva = fecha;
    this->estadoConsulta = estConsulta;
}
Comun::Comun(){
    DTFecha d = DTFecha();
    this->fechaReserva = f;
    this->estadoConsulta = Reservada;
}


// Setters
void Comun::setFechaReserva(DTFecha fechaReserva){this->fechaReserva = fechaReserva;}
void Comun::setEstadoConsulta(EstadoConsulta estadoConsulta){this->estadoConsulta = estadoConsulta;}

// Getters
DTFecha Comun::getFechaReserva(){return this->fechaReserva;}
EstadoConsulta Comun::getEstadoConsulta(){return this->estadoConsulta;}

// Métodos adicionales
DTConsulta Comun::getDatosConsulta()
{
    // Implementación del método
    // Retornar un objeto DTConsulta con los datos correspondientes
}

Diagnostico Comun::crearDiagnostico(std::string descripcion, ProblemaDeSalud *pds)
{
    // Implementación del método
    // Crear y retornar un objeto Diagnostico
}

void Comun::agregarTratamientoFarmaco(Diagnostico *diagnostico, std::string descripcion, std::list<std::string> *listMedicamentos)
{
    // Implementación del método
    // Agregar tratamiento farmacológico al diagnóstico
}

void Comun::agregarTratamientoQuirurgico(Diagnostico *diagnostico, std::string descripcion, DTFecha fecha)
{
    // Implementación del método
    // Agregar tratamiento quirúrgico al diagnóstico
}

void Comun::agregarDiagnosticoAConsulta(Diagnostico *diagnostico)
{
    // Implementación del método
    // Agregar diagnóstico a la consulta
}

std::set<DTReserva> Comun::getDatosReservas()
{
    // Implementación del método
    // Retornar un conjunto de DTReserva
}

// Destructor
Comun::~Comun()
{
    // Limpieza si es necesario
}