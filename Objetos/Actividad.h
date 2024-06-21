#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>
#include "DTFecha.h"
class Historial;
class Usuario;
class Medico;
class Socio;
using namespace std;

class Actividad
{
private:
    Socio *socioConsulta;
    Medico *medicoRealiza;
    Historial *historialAsoc;

public:
    // Actividad();
    Actividad(Socio *socio, Medico *medico);
    Actividad(Actividad &actividad);

    void setSocioConsulta(Socio *socio);
    void setMedicoRealiza(Medico *medico);
    void setHistorialAsoc(Historial *historial);

    Socio *getSocioConsulta();
    Medico *getMedicoRealiza();
    Historial *getHistorialAsoc();
    virtual DTFecha getFechaConsulta()const =0;

    void addHistorialAsoc(Historial *h);
    string cedulaSocio()const;
    string cedulaMedico()const;
    string nombreSocio();
    string nombreMedico();

    // Metodo para sobrecargar < y poder comparar en el <set>
    bool operator<(const Actividad &act) const;


    ~Actividad();
};
#endif
