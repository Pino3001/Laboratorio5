#ifndef SOCIO_H
#define SOCIO_H
#include <list>
#include <set>
#include <map>
#include <string>
#include "DTHora.h"
#include "CategoriaUsuario.h"
#include "Historial.h"
#include "DTReserva.h"
class Actividad;
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

  /*   void addActividad(Consulta actividad); */
    string verNombre();
    string verCi();
    TipoUsuario obtenerTipo();
    Actividad *buscarConsulta(string idConsulta);
    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Emergencia *AltaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion);
    set <DTReserva> mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    set <DTHistorial> mostrarHistorialPorMedico(Usuario *usr);




    ~Socio();
};
#endif