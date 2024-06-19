#ifndef SOCIO_H
#define SOCIO_H
#include <list>
#include <set>
#include <map>
#include <string>
#include "CategoriaUsuario.h"
#include "Actividad.h"
#include "Historial.h"
#include "DTReserva.h"
class Consulta;
using namespace std;


class Socio : public CategoriaUsuario
{
private:
    int cantConsultas;
    map <string, list <Actividad*>> *actividadesSocioXmedico;
    //list <Actividades*> actividadesSinRealizar;
    list <Historial*> *historialSocio;
public:
    Socio();
    /* Socio(Socio &socio, CategoriaUsuario &catUsr); */

    void setCantConsultas(int cantConsultas);
    void setActividadesSocioXmedico(map <string, list <Actividad*>> *actividadXmedico);
    //void setActividadesSinRealizar(list <Actividades*> sinRealizar);
    void setHistorialSocio(list <Historial*> *historialSocio);

    int getCantConsultas();
    map <string, list <Actividad*>> *getActividadesSocioXmedico();
    //list <Actividades*>* getActividadesSinRealizar();
    list <Historial*> *getHistorialSocio();

    void addActividad(Actividad actividad);
    string verNombre();
    string verCi();
    TipoUsuario obtenerTipo();
    Consulta *buscarConsulta(string idConsulta);
    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Actividad AltaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
    set <DTReserva> mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    /* set <DTHistorial> mostrarHistorialPorMedico(Usuario *usr); */




    ~Socio();
};
#endif