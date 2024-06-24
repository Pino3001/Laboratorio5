#ifndef SOCIO_H
#define SOCIO_H
#include <list>
#include <set>
#include <map>
#include <string>
#include "DTHora.h"
#include "CategoriaUsuario.h"
#include "Actividad.h"
class Comun;
using namespace std;


class Socio : public CategoriaUsuario
{
private:
    int cantConsultas;
    set <Actividad*, ActividadPtrComparator> actividadesSocio;
public:
    Socio();

    void setCantConsultas(int cantConsultas);
    void setActividadesSocio(set <Actividad*, ActividadPtrComparator> actividadesSocio);

    int getCantConsultas();
    set <Actividad*, ActividadPtrComparator> getActividadesSocio();

    void addActividad(Actividad *cons);
    list <DTConsulta> mostrarHistorialPorMedico()const;

    list<DTConsulta> obtenerReservasActivas()const;

    ~Socio();
};
#endif
