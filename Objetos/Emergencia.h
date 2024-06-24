#ifndef EMERGENCIA_H
#define EMERGENCIA_H
#include "Consulta.h"
#include "DTFecha.h"
#include "DTConsulta.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
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
    string getMotivoConsulta()const;
    DTConsulta getDatosConsulta()const;
    TipoConsulta obtenerTipoConsulta()const;

    ~Emergencia();
};

#endif
