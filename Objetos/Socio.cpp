#include "Socio.h"
#include "CategoriaUsuario.h"
#include "Consulta.h"
#include "Comun.h"
#include "Emergencia.h"
#include "Actividad.h"

// Constructores
Socio ::Socio() : CategoriaUsuario()
{
    this->cantConsultas = 0;
    map<string, list<Actividad *>> *actSocio = new map<string, list<Actividad *>>;
    this->actividadesSocio = actSocio;
    this->historialSocio = new set<Historial *>;
}

// Setters
void Socio ::setCantConsultas(int cantConsultas)
{
    this->cantConsultas = cantConsultas;
}
void Socio ::setActividadesSocio(map<string, list<Actividad *>> *actividadesSocio)
{
    this->actividadesSocio = actividadesSocio;
}
void Socio ::setHistorialSocio(set<Historial *> *historialSocio)
{
    this->historialSocio = historialSocio;
}

// Getters
int Socio ::getCantConsultas()
{
    return this->cantConsultas;
}
map<string, list<Actividad *>> *Socio ::getActividadesSocio()
{
    return this->actividadesSocio;
}
set<Historial *> *Socio ::getHistorialSocio()
{
    return this->historialSocio;
}

// Metodos Socio
string Socio ::verNombre()
{
    return this->usuarioVinculado->getNombre();
}

string Socio ::verCi()
{
    return this->usuarioVinculado->getCedula();
}

void Socio::addHistorialSocio(Historial *h)
{
    this->historialSocio->insert(h);
}

void Socio ::addActividad(Consulta* cons)
{
    auto itAct = this->actividadesSocio->find(cons->cedulaMedico());
    if (itAct != this->actividadesSocio->end())
    {
        itAct->second.push_back(cons);
    }
    else
    {
        list<Actividad *> *a = new list<Actividad *>;
        a->push_back(cons);
        this->actividadesSocio->insert(make_pair(cons->cedulaMedico(), *a));
    }
}

list<DTHistorial> Socio ::mostrarHistorialPorMedico()
{
    list<DTHistorial> listDth;
    for (Historial *h : *this->historialSocio)
    {
        DTHistorial dth = h->getDatosHistorial();
        listDth.push_back(dth);
    }
    return listDth;
}

// Para implementar
/* void Socio ::addActividad( actividad){} */
TipoUsuario Socio ::obtenerTipo() {}
Actividad *Socio ::buscarConsulta(string idConsulta) {}
void Socio ::registrarAsistencia(EstadoConsulta estC, string idConsulta) {}
Emergencia *Socio ::AltaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion) {}
set<DTReserva> Socio ::mostrarReservasActivas() {}
void Socio ::cancelarReserva(string idConsulta) {}

Socio ::~Socio() {}