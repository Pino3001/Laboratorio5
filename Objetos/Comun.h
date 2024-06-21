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
    Comun(const DTFecha fechaReserva, EstadoConsulta estConsulta, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico);

    // Setters
    void setFechaReserva(const DTFecha fechaReserva);
    void setEstadoConsulta(EstadoConsulta estadoConsulta);

    // Getters
    DTFecha getFechaReserva() const ;
    EstadoConsulta getEstadoConsulta();
    DTConsulta getDatosConsulta();
    
    Diagnostico crearDiagnostico(string descripcion, ProblemaDeSalud *pds);
    void agregarTratamientoFarmaco(Diagnostico *diagnostico, string descripcion, list<string> *listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico *diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnosticoAConsulta(Diagnostico *diagnostico);
    set<DTReserva> *getDatosReservas();
    string obtenerCiSocio();
    string obtenerCiMedico();
    Historial *getHistorialAsoc();

    ~Comun();
};
#endif
