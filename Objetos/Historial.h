#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "Usuario.h"
#include "DTDiagnostico.h"
#include "DTConsulta.h"
#include "DTHistorial.h"
#include "string.h"
using namespace std;
class Socio;
class Medico;
class Consulta;
class Diagnostico;
class Historial
{
private:
    Socio *historialSocio;
    Medico *medicoRealiza;
    Consulta *consulta;
    list <Diagnostico*> *listaDiagnosticos;

public:
    /* Historial(); */
    Historial(Socio *socio, Medico *medico, Consulta *consulta, list <Diagnostico*> *diagnosticos);
    Historial(Historial &historial); 

    void setHistorialSocio(Socio *socio);
    void setMedicoRealiza(Medico *medico);
    void setConsulta(Consulta *consulta);
    void setDiagnostico(list <Diagnostico*> *diagnosticos);

    Socio *getHistorialSocio();
    Medico *getMedicoRealiza();
    Consulta *getConsulta();
    list<Diagnostico*> *getDiagnostico();

    bool operator<(const Historial &hist) const;
    DTHistorial getDatosHistorial();

    ~Historial();
};

#endif