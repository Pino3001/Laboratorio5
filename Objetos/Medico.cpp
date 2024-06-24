#include "Medico.h"
#include "Socio.h"
#include "CategoriaUsuario.h"
#include "Usuario.h"
#include "Consulta.h"
#include "Actividad.h"
#include "Comun.h"
#include <map>
#include <list>
#include <string>

Medico ::Medico() : CategoriaUsuario()
{
    list<Actividad *> *actMedico = new list<Actividad *>;
    this->actividadMedico = actMedico;
}

// Setters
void Medico ::setActividadMedico(list<Actividad *> *actividadMedico)
{
    this->actividadMedico = actividadMedico;
}

// Getters
list<Actividad *> *Medico ::getActividadMedico()
{
    return this->actividadMedico;
}

void Medico::addActividad(Actividad *Cons)
{
    this->actividadMedico->push_back(Cons);
}

Medico ::~Medico() {}
