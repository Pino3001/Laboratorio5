#include "Medico.h"



Medico ::Medico() : CategoriaUsuario()
{
    list<Actividad *> *actMedico = new list<Actividad *>;
    this->actividadMedico = actMedico;

    list<Socio *> *socAtendidos = new list<Socio *>;
    this->sociosAtendidos = socAtendidos;

    list<Historial *> *histCreados = new list<Historial *>;
    this->historialesCreados = histCreados;
}

Medico ::Medico(Medico &medico, CategoriaUsuario &catUsr) : CategoriaUsuario(catUsr)
{// VER SI ESTO ESTA BIEN
    for (Actividad *am : *medico.getActividadMedico())
    {
        this->actividadMedico->push_back(am);
    }
    for (Socio *sa : *medico.getSociosAtendidos())
    {
        this->sociosAtendidos->push_back(sa);
    }
    for (Historial *hc : *medico.getHistorialesCreados())
    {
        this->historialesCreados->push_back(hc);
    }
}

//Setters
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

//Getters
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

//Para implementar
void addActividad(Actividad actividad);
string verNombre();
string verCi();
TipoUsuario Medico :: obtenerTipo(){}
Consulta buscarConsulta(string idConsulta);
set<DTHistorial> mostrarHistorialSocio(Usuario usr);
set<DTConsulta> mostrarDatosConsulta(DTFecha fecha);

Medico ::~Medico(){}