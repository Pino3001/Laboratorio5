#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include "Consulta.h"
#include "DTFecha.h"
#include "DTConsulta.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
#include "Datatypes/DTReserva.h"
#include "definiciones.h"
#include <list>
#include <string>

using namespace std;

class Emergencia : public Consulta
{
private:
    string motivoConsulta;

public:
    Emergencia(string motivo, const DTFecha fecha, DTHora const hora, Socio *socio, Medico *medico);
    Emergencia(Emergencia &emergencia, Consulta &consulta, Actividad &actividad);

    // Setters
    void setMotivoConsulta(string motivo);
    // Getters
    string getMotivoConsulta();
    DTConsulta getDatosConsulta();
    // Métodos adicionales
    string obtenerCiSocio();
    string obtenerCiMedico();
    TipoConsulta obtenerTipoConsulta();

    Diagnostico crearDiagnostico(string descripcion, ProblemaDeSalud pds);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<std::string> *listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnosticoAConsulta(Diagnostico diagnostico);

    Historial *getHistorialAsoc();

    ~Emergencia();
};

#endif