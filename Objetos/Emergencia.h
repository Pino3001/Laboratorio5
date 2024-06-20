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

class Emergencia : public Consulta{
private:
    string motivoConsulta;

public:
    Emergencia(string motivo, string idConsulta, const DTFecha fecha, DTHora const hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio);
    /* Emergencia(); */

    // Getters
    string getMotivoConsulta();

    // Setters
    void setMotivoConsulta(string motivo);

    // Métodos adicionales
    DTConsulta getDatosConsulta();
    Diagnostico crearDiagnostico(string descripcion, ProblemaDeSalud pds);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<std::string> *listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnosticoAConsulta(Diagnostico diagnostico);

     string getNombreSocio();
     string getCiSocio();
     string getNombreMedico();
     string CiMedico();


    ~Emergencia();
};

#endif 