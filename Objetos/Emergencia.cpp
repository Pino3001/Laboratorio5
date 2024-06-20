#include "Emergencia.h"


// Constructor con parámetros
Emergencia::Emergencia(string motivo, string idConsulta, const DTFecha fecha, const DTHora hora, Socio* socio, Medico* medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio)
    : Consulta(idConsulta, fecha, hora, socio, medico, nombreMedico, ciMedico, nombreSocio, ciSocio) {
    this->motivoConsulta = motivo;
}
/* // Constructor por defecto
Emergencia::Emergencia() : Consulta() {
    this->motivoConsulta = " ";
} */

// Setter para motivoConsulta
void Emergencia::setMotivoConsulta(string motivo) {this->motivoConsulta = motivo;}

// Getter para motivoConsulta
string Emergencia::getMotivoConsulta() {return this->motivoConsulta;}

// Métodos adicionales
DTConsulta Emergencia::getDatosConsulta() {
    // Implementación del método
    // Retornar un objeto DTConsulta con los datos correspondientes
}
Diagnostico Emergencia::crearDiagnostico(string descripcion, ProblemaDeSalud pds) {
    // Implementación del método
    // Crear y retornar un objeto Diagnostico
}
void Emergencia::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string>* listMedicamentos) {
    // Implementación del método
    // Agregar tratamiento farmacológico al diagnóstico
}
void Emergencia::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha) {
    // Implementación del método
    // Agregar tratamiento quirúrgico al diagnóstico
}
void Emergencia::agregarDiagnosticoAConsulta(Diagnostico diagnostico) {
    // Implementación del método
    // Agregar diagnóstico a la consulta
}


//de herencia
string Emergencia ::getNombreSocio()
{
}
string Emergencia ::getCiSocio()
{
}
string Emergencia ::getNombreMedico()
{
}
string Emergencia ::CiMedico()
{
}

// Destructor
Emergencia::~Emergencia() {
    // Liberar recursos si es necesario
}