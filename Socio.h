#ifndef SOCIO_H
#define SOCIO_H

#include "CategoriaUsuario.h"
#include "Actividad.h"
#include "Medico.h"
//#include "Historial.h"

#include <list>
#include <string>
using namespace std;


class Socio : public CategoriaUsuario
{
private:
    int cantConsultas;
    list <Actividad*> *actividadesSocio;
    list <Medico*> *medicosConsultados;
    list <Historial*> *historialSocio;
public:
    Socio(Usuario *usr);
    Socio(Socio &socio, CategoriaUsuario &catUsr);

    void setCantConsultas();
    void setActividadesSocio(list <Actividad*> *actividadesSocio);
    void setMedicosConsultados(list <Medico*> *medicosConsultados);
    void setHistorialSocio(list <Historial*> *historialSocio);

    int getCantConsultas();
    list <Actividad*> getActividadesSocio();
    list <Medico*> getMedicosConsultados();
    list <Historial*> getHistorialSocio();

    void addActividad(Actividad actividad);
    string verNombre();
    string verCi();
    TipoUsuario obtenerTipo();
    Consulta buscarConsulta(string idConsulta);
    void registrarAsistencia(EstadoConsulta estC);
    Actividad AltaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
    set(DTReserva) mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    set(DTHistorial) mostrarHistorialPorMedico(Usuario usr);




    ~Socio();
};
#endif