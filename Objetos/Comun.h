#ifndef COMUN_H
#define COMUN_H
#include <list>
#include <set>
#include <string>
#include "definiciones.h"
#include "Consulta.h"
class DTConsulta;
class DTReserva;
class DTFecha;
class DTHora;
class ProblemaDeSalud;
class Diagnostico;
class Socio;
class Medico;
using namespace std;

class Comun : public Consulta
{
private:
    DTFecha fechaReserva;
    EstadoConsulta estadoConsulta;

public:
    /* Comun(); */
    Comun(DTFecha fechaReserva, EstadoConsulta estConsulta, string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio);

    // Setters
    void setFechaReserva(DTFecha fechaReserva);
    void setEstadoConsulta(EstadoConsulta estadoConsulta);

    // Getters
    DTFecha getFechaReserva();
    EstadoConsulta getEstadoConsulta();

    DTConsulta getDatosConsulta();
    Diagnostico crearDiagnostico(string descripcion, ProblemaDeSalud *pds);
    void agregarTratamientoFarmaco(Diagnostico *diagnostico, string descripcion, list<string> *listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico *diagnostico, string descripcion, DTFecha fecha);
    void agregarDiagnosticoAConsulta(Diagnostico *diagnostico);
    set<DTReserva> *getDatosReservas();

    ~Comun();
};
#endif
