#ifndef MEDICO_H
#define MEDICO_H

#include "CategoriaUsuario.h"
#include "Actividad.h"
#include "Socio.h"
// #include "Historial.h"
#include <string>
#include "iostream"

using namespace std;

class Medico : public CategoriaUsuario
{
private:
    list <Actividad*> *actividadMedico;
    list <Socio*> *sociosAtendidos;
    list <Historial*> *historialesCreados;
public:
    Medico();
    Medico(Medico &medico, CategoriaUsuario &catUsr);

    void setActividadMedico(list <Actividad*> *actividadMedico);
    void setSociosAtendidos(list <Socio*> *sociosAtendidos);
    void setHistorialesCreados(list <Historial*> * historialesCreados);

    list <Actividad*> getActividadMedico();
    list <Socio*> getSociosAtendidos();
    list <Historial*> getHistorialesCreados();


    void addActividad(Actividad actividad);
    string verNombre();
    string verCi();
    TipoUsuario obtenerTipo();
    Consulta buscarConsulta(string idConsulta);
    set(DTHistorial) mostrarHistorialSocio(Usuario usr);
    set(DTConsulta) mostrarDatosConsulta(DTFecha fecha);

    ~Medico();
};

#endif