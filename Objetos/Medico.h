#ifndef MEDICO_H
#define MEDICO_H
#include <string>
#include <set>
#include "iostream"
#include "CategoriaUsuario.h"
#include "Actividad.h"
#include "Historial.h"
class Usuario;
class Comun;
class Consulta;
using namespace std;

class Medico : public CategoriaUsuario
{
private:
    list <Actividad*> *actividadMedico;
    list <Socio*> *sociosAtendidos;
    list <Historial*> *historialesCreados;
public:
    Medico();
   /*  Medico(Medico &medico, CategoriaUsuario &catUsr); */

    void setActividadMedico(list <Actividad*> *actividadMedico);
    void setSociosAtendidos(list <Socio*> *sociosAtendidos);
    void setHistorialesCreados(list <Historial*> * historialesCreados);

    list <Actividad*> *getActividadMedico();
    list <Socio*> *getSociosAtendidos();
    list <Historial*> *getHistorialesCreados();

    string verNombre();
    string verCi();
    void addActividad(Comun *ConsComun);

    TipoUsuario obtenerTipo();
    Actividad *buscarConsulta(string idConsulta);
    set<DTHistorial> mostrarHistorialSocio(Usuario usr);
    set<DTConsulta> mostrarDatosConsulta(const DTFecha fecha);

    ~Medico();
};
#endif