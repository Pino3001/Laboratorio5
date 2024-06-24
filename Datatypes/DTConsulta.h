#ifndef DTCONSULTA_H
#define DTCONSULTA_H
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "definiciones.h"
#include "DTDatosUsuario.h"
#include "DTDiagnostico.h"
#include <list>

using namespace std;

class DTConsulta
{
private:
    DTDatosUsuario socio;
    DTDatosUsuario medico;
    list<DTDiagnostico> diagnosticos;
    string motivo;
    DTFecha fechaConsulta;
    DTHora horaConsulta;
    DTFecha fechaReserva;
    TipoConsulta tipo;
public:
    DTConsulta();
    DTConsulta(DTDatosUsuario socio, DTDatosUsuario medico, list<DTDiagnostico> diagnosticos, string motivo, const DTFecha fechaConsul, const DTHora horaConsul, DTFecha fechaReserva, TipoConsulta tipo);

    DTDatosUsuario getSocio()const;
    DTDatosUsuario getMedico()const;
    list<DTDiagnostico> getDiagnosticos()const;
    string getMotivo()const;
    DTFecha getFechaConsulta() const;
    DTHora getHoraConsulta()const;
    DTFecha getFechaReserva()const;
    TipoConsulta getTipo()const;
    void mostrarDTConsulta()const;
    void mostrarReservas()const;
    void mostrarVersionHistorial()const;
};
#endif
