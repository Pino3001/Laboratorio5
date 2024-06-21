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
    list<Historial *> *histSocio = new list<Historial *>;
    this->historialSocio = histSocio;
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
void Socio ::setHistorialSocio(list<Historial *> *historialSocio)
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
list<Historial *> *Socio ::getHistorialSocio()
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
void Socio ::addActividad(Comun *ConsComun, string ciMedico)
{
    auto itAct = this->actividadesSocio->find(ciMedico);
    if (itAct != this->actividadesSocio->end())
    {
        itAct->second.push_back(ConsComun);
    }
    else
    {
        list<Actividad *> *a = new list<Actividad *>;
        a->push_back(ConsComun);
        this->actividadesSocio->insert(make_pair(ciMedico, *a));
    }
}

set<DTHistorial> Socio ::mostrarHistorialPorMedico(Usuario *usr)
{
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