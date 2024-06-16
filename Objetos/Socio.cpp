#include "Socio.h"

// Constructores
Socio ::Socio(Usuario *usr) : CategoriaUsuario(usr)
{
    this->cantConsultas = 0;

    map<string, list<Actividad *>> *actSocio = new map<string, list<Actividad *>>;
    this->actividadesSocioXmedico = actSocio;
    list<Medico *> *medConsult = new list<Medico *>;
    this->medicosConsultados = medConsult;
    list<Historial *> *histSocio = new list<Historial *>;
    this->historialSocio = histSocio;
}

Socio ::Socio(Socio &socio, CategoriaUsuario &catUsr) : CategoriaUsuario(catUsr)
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

    for (Actividad *ac : socio.getActividadesSocio())
    {
        this->actividadesSocio->push_back(ac);
    }
    for (Medico *mc : socio.getMedicosConsultados())
    {
        this->medicosConsultados->push_back(mc);
    }
    for (Historial *hs : socio.getHistorialSocio())
    {
        this->historialSocio->push_back(hs);
    }
}

// Setters
void Socio ::setCantConsultas(int cantConsultas)
{
    this->cantConsultas = cantConsultas;
}
void Socio ::setActividadesSocio(list<Actividad *> *actividadesSocio)
{
    this->actividadesSocio = actividadesSocio;
}
void Socio ::setMedicosConsultados(list<Medico *> *medicosConsultados)
{
    this->medicosConsultados = medicosConsultados;
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
map <string, list <Actividad*>> *Socio ::getActividadesSocio()
{
    return this->actividadesSocio;
}
list<Medico *> *Socio ::getMedicosConsultados()
{
    return this->medicosConsultados;
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

set<DTHistorial> mostrarHistorialPorMedico(Usuario *usr)
{
    for (auto **listactividades : this->medicosConsultados)
    {
    }
}
// Para implementar
void addActividad(Actividad actividad);

string verCi();
TipoUsuario Socio ::obtenerTipo() {}
Consulta buscarConsulta(string idConsulta);
void registrarAsistencia(EstadoConsulta estC, string idConsulta);
Actividad AltaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
set(DTReserva) mostrarReservasActivas();
void cancelarReserva(string idConsulta);

~Socio();