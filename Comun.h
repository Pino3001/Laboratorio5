#ifndef COMUN_H
#define COMUN_H

#include "Consulta.h"

#include "DTFecha.h"
#include "DTConsulta.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
#include "DTReserva.h"
#include "definiciones.h"
#include <list>
#include <string>

using namespace std;

class Comun : public Consulta
{
private:
    DTFecha fechaReserva;
    EstadoConsulta estadoConsulta;

public:
    Comun();
    Comun(DTFecha fecha, EstadoConsulta estConsulta, string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico);

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
    set<DTReserva> getDatosReservas();

    ~Comun();
};
#endif
