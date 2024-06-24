#ifndef MEDICO_H
#define MEDICO_H
#include "CategoriaUsuario.h"
class Actividad;
#include <string>
#include <set>
#include <list>
#include "iostream"
using namespace std;


class Medico : public CategoriaUsuario
{
private:
    list <Actividad*> *actividadMedico;
public:
    Medico();

    void setActividadMedico(list <Actividad*> *actividadMedico);

    list <Actividad*> *getActividadMedico();

    void addActividad(Actividad *Cons);

    ~Medico();
};
#endif
