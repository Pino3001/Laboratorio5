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
    list<Diagnostico *> *diagnosticosConsulta;

public:
    /* Consulta(); */
    /* Consulta(string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico); */
    Consulta(const DTFecha fechaConsulta, const DTHora horaConsulta, Socio *socio, Medico *medico);
    Consulta(Consulta &consulta, Actividad &actividad);

    void setFechaConsulta(const DTFecha fecha);
    void setHoraConsulta(const DTHora hora);
    void setDiagnosticosConsulta(list<Diagnostico *> *diagnosticosConsulta);

    list<Diagnostico *> *getDiagnosticoConsulta();
    DTFecha getFechaConsulta() const;
    DTHora getHoraConsulta() const;
    DTConsulta getDatosConsulta();
    list<DTDiagnostico> getDatosDiagnosticoConsulta();

    void crearDiagnostico(string descripcion, list<ProblemaDeSalud *> *lPds);
    void crearDiagnosticoTratFarmaco(string descripcion, list<ProblemaDeSalud *> *lPds, list<string> *medicamentos, string descrTrat);
    void crearDiagnosticoTratQuirurjico(string descripcion, list<ProblemaDeSalud *> *lPds, Medico *med, string descrTrat, const DTFecha fechaCiruj);
    void crearHistorial();
   
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, list<string> listaMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnosticoConsulta(Diagnostico diagnostico);
    virtual Historial *getHistorialAsoc() = 0;
    virtual TipoConsulta obtenerTipoConsulta()=0;


    ~Consulta();
};
#endif