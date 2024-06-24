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

    list<Diagnostico *> *getDiagnosticoConsulta()const;
    DTFecha getFechaConsulta() const;
    DTHora getHoraConsulta() const;
    list<DTDiagnostico> getDatosDiagnosticoConsulta()const;

    Diagnostico* crearDiagnostico(string descripcion, list<ProblemaDeSalud *> *lPds);
    
    virtual TipoConsulta obtenerTipoConsulta()const=0;
    virtual DTConsulta getDatosConsulta()const=0;



    virtual ~Consulta()=0;
};
#endif
