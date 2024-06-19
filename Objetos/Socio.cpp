#include "Socio.h"
#include "CategoriaUsuario.h"
#include "Consulta.h"
#include "Actividad.h"


// Constructores
Socio ::Socio() : CategoriaUsuario()
{
    this->cantConsultas = 0;

    map<string, list<Actividad *>> *actSocio = new map<string, list<Actividad *>>;
    this->actividadesSocioXmedico = actSocio;
    list<Historial *> *histSocio = new list<Historial *>;
    this->historialSocio = histSocio;
}

/* Socio ::Socio(Socio &socio, CategoriaUsuario &catUsr) : CategoriaUsuario(catUsr)
{
    this->cantConsultas = socio.getCantConsultas();
    //creo un nuevo map
    map<string, list<Actividad *>> *actSocio = new map<string, list<Actividad *>>;
    //recorro el map del objeto pasado por referencia
    for (auto it = socio.getActividadesSocioXmedico()->begin(); it != socio.getActividadesSocioXmedico()->end(); ++it)
    {
        list<Actividad *> actividades = it->second;
        //Creo una nueva lista de actividades.
        list<Actividad *> *nuevaAct = new list<Actividad *>;
        //Hago una copia de la lista
        *nuevaAct = actividades;
        // Asigno la clave y la nueva lista al map creado anteriormente
        (*actSocio)[it->first] = actividades;
    }

    for (Actividad *ac : *socio.getActividadesSocioXmedico())
    {
        this->actividadesSocioXmedico->push_back(ac);
    }
    for (Medico *mc : *socio.getMedicosConsultados())
    {
        this->medicosConsultados->push_back(mc);
    }
    for (Historial *hs : *socio.getHistorialSocio())
    {
        this->historialSocio->push_back(hs);
    }
} */

// Setters
void Socio ::setCantConsultas(int cantConsultas)
{
    this->cantConsultas = cantConsultas;
}
void Socio ::setActividadesSocioXmedico(map <string, list <Actividad*>> *actividadXmedico)
{
    this->actividadesSocioXmedico = actividadXmedico;
}
void Socio ::setHistorialSocio(list<Historial *> *historialSocio)
{
    this->historialSocio = historialSocio;
}

// Getters
int Socio ::getCantConsultas()
{
    return this->cantConsultas;
}
map <string, list <Actividad*>> *Socio ::getActividadesSocioXmedico()
{
    return this->actividadesSocioXmedico;
}
list<Historial *> *Socio ::getHistorialSocio()
{
    return this->historialSocio;
}

string Socio ::verNombre()
{
    return this->usuarioVinculado->getNombre();
}

string Socio ::verCi()
{
    return this->usuarioVinculado->getCedula();
}

set<DTHistorial> Socio ::mostrarHistorialPorMedico(Usuario *usr)
{

} 
// Para implementar
void Socio ::addActividad(Actividad actividad){}
TipoUsuario Socio ::obtenerTipo() {}
Actividad *Socio ::buscarConsulta(string idConsulta){}
void Socio ::registrarAsistencia(EstadoConsulta estC, string idConsulta){}
Actividad Socio ::AltaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion){}
set<DTReserva> Socio ::mostrarReservasActivas(){}
void Socio ::cancelarReserva(string idConsulta){}

Socio ::~Socio(){}