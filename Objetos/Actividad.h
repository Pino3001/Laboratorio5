#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>
#include "DTFecha.h"
#include "DTConsulta.h"
class Usuario;
class Medico;
class Socio;
using namespace std;

class Actividad
{
private:
    Socio *socioConsulta;
    Medico *medicoRealiza;

public:
    // Actividad();
    Actividad(Socio *socio, Medico *medico);
    Actividad(const Actividad &actividad);

    void setSocioConsulta(Socio *socio);
    void setMedicoRealiza(Medico *medico);

    Socio *getSocioConsulta() const;
    Medico *getMedicoRealiza()const;

    string getNombreSocioActividad()const;
    string  getNombreMedicoActividad()const;

    virtual DTConsulta getDatosConsulta()const=0;
    virtual DTFecha getFechaConsulta()const =0;

    // Metodo para sobrecargar < y poder comparar en el <set>
    bool operator<(const Actividad &act) const;

    ~Actividad();
};
// Definir el comparador para punteros a Actividad
struct ActividadPtrComparator {
    bool operator()(const Actividad* ac1, const Actividad* ac2) const {
        if (!ac1 || !ac2) return ac1 < ac2; // Manejo de punteros nulos si es necesario
        return *ac1 < *ac2; // Usar el operador de comparación de Actividad
    }
};
#endif
