#include "Medico.h"
#include "Socio.h"
#include "CategoriaUsuario.h"
#include "Usuario.h"
#include "Consulta.h"
#include "Comun.h"

Medico ::Medico() : CategoriaUsuario()
{
    list<Actividad *> *actMedico = new list<Actividad *>;
    this->actividadMedico = actMedico;

    list<Socio *> *socAtendidos = new list<Socio *>;
    this->sociosAtendidos = socAtendidos;

    list<Historial *> *histCreados = new list<Historial *>;
    this->historialesCreados = histCreados;
}

// Setters
void Medico ::setActividadMedico(list<Actividad *> *actividadMedico)
{
    this->actividadMedico = actividadMedico;
}
void Medico ::setSociosAtendidos(list<Socio *> *sociosAtendidos)
{
    this->sociosAtendidos = sociosAtendidos;
}
void Medico ::setHistorialesCreados(list<Historial *> *historialesCreados)
{
    this->historialesCreados = historialesCreados;
}

// Getters
list<Actividad *> *Medico ::getActividadMedico()
{
    return this->actividadMedico;
}
list<Socio *> *Medico ::getSociosAtendidos()
{
    return this->sociosAtendidos;
}
list<Historial *> *Medico ::getHistorialesCreados()
{
    return this->historialesCreados;
}

// Metodos medico
string Medico::verNombre()
{
    this->usuarioVinculado->getCedula();
}
string Medico ::verCi()
{
    this->usuarioVinculado->getCedula();
}
void Medico::addActividad(Consulta *Cons)
{
    this->actividadMedico->push_back(Cons);
}

TipoUsuario Medico ::obtenerTipo() {}
Actividad *Medico ::buscarConsulta(string idConsulta) {}
set<DTHistorial> Medico ::mostrarHistorialSocio(Usuario usr) {}
set<DTConsulta> Medico ::mostrarDatosConsulta(const DTFecha fecha) {}

Medico ::~Medico() {}