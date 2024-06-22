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
    set <Historial*> *historialSocio;
public:
    Socio();

    void setCantConsultas(int cantConsultas);
    void setActividadesSocio(map <string, list <Actividad*>> *actividadesSocio);
    void setHistorialSocio(set <Historial*> *historialSocio);

    int getCantConsultas();
    map <string, list <Actividad*>> *getActividadesSocio();
    set <Historial*> *getHistorialSocio();

    void addActividad(Consulta *cons);
    void addHistorialSocio(Historial *h);
    string verNombre();
    string verCi();
    list <DTHistorial> mostrarHistorialPorMedico();


    TipoUsuario obtenerTipo();
    Actividad *buscarConsulta(string idConsulta);
    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Emergencia *AltaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion);
    set <DTReserva> mostrarReservasActivas();
    void cancelarReserva(string idConsulta);




    ~Socio();
};
#endif