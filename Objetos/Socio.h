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
class Comun;
using namespace std;


class Socio : public CategoriaUsuario
{
private:
    int cantConsultas;
    map <string, list <Actividad*>> *actividadesSocio;
    list <Historial*> *historialSocio;
public:
    Socio();

    void setCantConsultas(int cantConsultas);
    void setActividadesSocio(map <string, list <Actividad*>> *actividadesSocio);
    void setHistorialSocio(list <Historial*> *historialSocio);

    int getCantConsultas();
    map <string, list <Actividad*>> *getActividadesSocio();
    list <Historial*> *getHistorialSocio();

    void addActividad(Comun *ConsComun, string ciMedico);
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