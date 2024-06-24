#include "Socio.h"
#include "definiciones.h"
#include "CategoriaUsuario.h"
#include "Consulta.h"
#include "Comun.h"
#include "Emergencia.h"
#include "Actividad.h"
#include <list>
#include <string>
#include "Medico.h"

// Constructores
Socio ::Socio() : CategoriaUsuario()
{
    this->cantConsultas = 0;
}

// Setters
void Socio ::setCantConsultas(int cantConsultas)
{
    this->cantConsultas = cantConsultas;
}
void Socio ::setActividadesSocio(set <Actividad*, ActividadPtrComparator> actividadesSocio)
{
    this->actividadesSocio = actividadesSocio;
}

// Getters
int Socio ::getCantConsultas()
{
    return this->cantConsultas;
}
set <Actividad*, ActividadPtrComparator>  Socio::getActividadesSocio()
{
    return this->actividadesSocio;
}

// Metodos Socio

void Socio ::addActividad(Actividad* cons)
{
    
    this->actividadesSocio.insert(cons);
}

list<DTConsulta> Socio ::mostrarHistorialPorMedico() const
{
    list<DTConsulta> listDth;
    for(Actividad *ac : this->actividadesSocio)
    {
        if(Comun *cons = dynamic_cast<Comun*>(ac))
        {
            if(cons->getEstadoConsulta() == EstadoConsulta::Asistio)
            {
                DTConsulta dth = ac->getDatosConsulta();
                listDth.push_back(dth);
            }
        }
        else
        {
            DTConsulta dth = ac->getDatosConsulta();
            listDth.push_back(dth);
        }

    }
    return listDth;
}

list<DTConsulta> Socio::obtenerReservasActivas()const
{
    list<DTConsulta> liDTC;
    for(Actividad *ac : this->actividadesSocio){
        if(Comun *cons = dynamic_cast<Comun*>(ac)){
            if(cons->getEstadoConsulta() == EstadoConsulta::Reservada){
                DTConsulta dc = cons->getDatosConsulta();
                liDTC.push_back(dc);
            }
        }
    }
    return liDTC;
}

Socio ::~Socio() {}
