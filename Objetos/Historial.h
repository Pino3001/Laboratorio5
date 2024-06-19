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

class Historial
{
private:
    Socio *historialSocio;
    Medico *medicoRealiza;
    DTConsulta consulta;
    list <DTDiagnostico> listaDiagnosticos;

public:
    Historial();
    Historial(Socio *socio, Medico *medico, DTConsulta consulta, list <DTDiagnostico> diagnosticos);
    Historial(Historial &historial);

    void setHistorialSocio(Socio *socio);
    void setMedicoRealiza(Medico *medico);
    void setConsulta(DTConsulta consulta);
    void setDiagnostico(list <DTDiagnostico> diagnosticos);

    Socio *getHistorialSocio();
    Medico *getMedicoRealiza();
    DTConsulta getConsulta();
    list <DTDiagnostico> getDiagnostico();

    DTHistorial getDatosHistorial();

    ~Historial();
};

#endif