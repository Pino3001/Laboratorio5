#ifndef CONSULTA_H
#define CONSULTA_H
#include "Actividad.h"
#include "Diagnostico.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTConsulta.h"
#include <list>
#include <string>
class Socio;
class Medico;
using namespace std;


class Consulta : public Actividad
{
private:
    string idConsulta;
    DTFecha fechaConsulta;
    DTHora horaConsulta;
public:
    /* Consulta(); */
    /* Consulta(string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico); */
    Consulta(string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio);
    Consulta(Consulta &consulta, Actividad &actividad);

    void setFechaConsulta(DTFecha fecha);
    void setHoraConsulta(DTHora hora);

    string getIdConsulta();
    DTFecha getFechaConsulta();
    DTHora getHoraConsulta();

    DTConsulta getDatosConsulta();
    Diagnostico* crearDiagnostico(string descripcion, ProblemaDeSalud pds);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, list<string> listaMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha);
    void agregarDiagnosticoConsulta(Diagnostico diagnostico);

    ~Consulta();
};
#endif