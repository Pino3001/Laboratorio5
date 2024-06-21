#include "CRegistroMedico.h"
#include "CUsuario.h"
#include "ProblemaDeSalud.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTConsulta.h"
#include "Actividad.h"
#include "Comun.h"
#include "Medico.h"
#include "Socio.h"
#include "Emergencia.h"
#include <list>
#include <set>
#include "definiciones.h"

CRegistroMedico *CRegistroMedico::instance = nullptr;

CRegistroMedico::CRegistroMedico() : memConsulta(nullptr), problemasDeSalud(new map<string, CategoriaProblemaSalud *>()), memActividades(new map<DTFecha, list<Actividad *>>()) {}

CRegistroMedico *CRegistroMedico::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CRegistroMedico();
    }
    return instance;
}

list<DTConsulta> CRegistroMedico::mostrarConsultas(const DTFecha fechaHoy)
{
    list<DTConsulta> listDTC;
    // Busco en el map si existe una lista de consultas para el dia pasado como parametro.
    auto itu = this->memActividades->find(fechaHoy);
    if (itu != memActividades->end())
    {
        // Si existe obtengo la lista de Actividades de ese dia.
        for (Actividad *a : itu->second)
        {
            // Recorro la lista buscando las consultas de tipo comun.
            if (Comun *comun = dynamic_cast<Comun *>(a))
            {
                if (comun->getEstadoConsulta() == EstadoConsulta::Asistio)
                {
                    DTConsulta dtcons = comun->getDatosConsulta();
                    listDTC.push_back(dtcons);
                }
            }
        }
    }
    return listDTC;
}

void CRegistroMedico::registroConsulta(string ci, string ciMedico, const DTFecha fechaHoy)
{
    // Busco en el map si existe una lista de consultas para el dia pasado como parametro.
    auto itu = this->memActividades->find(fechaHoy);
    if (itu != memActividades->end())
    {
        // Si existe obtengo la lista de Actividades de ese dia.
        for (Actividad *a : itu->second)
        {
            // Recorro la lista buscando las consultas de tipo comun.
            if (Comun *comun = dynamic_cast<Comun *>(a))
            {
                // De las consultas de tipo comun comparo los datos de estas, con los que estoy buscando y compruebo que sean consultas reservadas.
                if (comun->obtenerCiMedico() == ciMedico && comun->obtenerCiSocio() == ci && comun->getEstadoConsulta() == EstadoConsulta::Reservada)
                {
                    // Cambio el estado de la consulta para sacarla de la reserva.
                    comun->setEstadoConsulta(EstadoConsulta::Asistio);
                }
            }
        }
    }
    else
    {
    }
}

list<DTCategoriaRep> *CRegistroMedico::mostrarRepresentaciones()
{
    list<DTCategoriaRep> *ldt = new list<DTCategoriaRep>;
    for (auto &pair : *this->problemasDeSalud)
    {
        DTCategoriaRep dcr = DTCategoriaRep(pair.second->getIdCategoria(), pair.second->getDescripcion());
        ldt->push_back(dcr);
    }
    return ldt;
}

void CRegistroMedico::altaCategoriaRepresentacion(string id, string descripcion)
{
    CategoriaProblemaSalud *cat = new CategoriaProblemaSalud(id, descripcion);
    auto resultado = this->problemasDeSalud->insert(make_pair(id, cat));
    if (!resultado.second)
    {
        // La inserción no tuvo éxito porque el elemento ya existe
        delete cat; // Liberar la memoria si el elemento ya existe
    }
    else
    {
        // Categoría de problema de salud creada e insertada exitosamente.
    }
}

void CRegistroMedico::altaProblemaDeSalud(string id, string codigo, string etiqueta)
{
    auto it = this->problemasDeSalud->find(id);
    if (it != problemasDeSalud->end())
    {
        it->second->altaProblemas(codigo, etiqueta);
    }
    else
    {
        cout << "Problema de salud con ID '" << id << "' no encontrado.";
    }
}

list<DTProblemaDeSalud> CRegistroMedico::mostrarProblemaDeSalud() 
{

}

void CRegistroMedico::reservaNuevaConsulta(string ciMedico, string ciSocio, const DTFecha fechaConsulta, const DTFecha fecReserva, const DTHora horaCosn)
{
    Medico *m;
    Socio *s;
    bool esSocio = false, esMedico = false;
    Usuario *usrMed = CUsuario::getInstance()->darUsuario(ciMedico);
    if (usrMed != nullptr)
    {
        list<CategoriaUsuario *> *catUm = usrMed->getCatUsr();
        for (CategoriaUsuario *c : *catUm)
        {
            if (Medico *med = dynamic_cast<Medico *>(c))
            {
                m = med;
                esMedico = true;
            }
        }
    }
    else
    {
        // no existe usuario con esa cedula
    }
    Usuario *usrSocio = CUsuario::getInstance()->darUsuario(ciSocio);
    if (usrSocio != nullptr)
    {
        list<CategoriaUsuario *> *catUs = usrSocio->getCatUsr();
        for (CategoriaUsuario *c : *catUs)
        {
            if (Socio *soc = dynamic_cast<Socio *>(c))
            {
                s = soc;
                esSocio = true;
            }
        }
    }
    else
    {
        // no existe usuario con esa cedula
    }
    if (esMedico && esSocio)
    {
        Comun *cons = new Comun(fecReserva, EstadoConsulta::Reservada, fechaConsulta, horaCosn, s, m);
        s->addActividad(cons, m->verCi());
        m->addActividad(cons);
    }
    else if (!esMedico)
    {
        /* El usuario de la cedula no es medico */
    }else if (!esSocio)
    {
        /* El usuario de la cedula no es socio */
    }
    
    
}

ProblemaDeSalud *CRegistroMedico::seleccionarProblemaDeSalud(string codigo, string etiqueta) 
{
    
}




Consulta *CRegistroMedico::seleccionarConsulta(string idConsulta) {}
CategoriaProblemaSalud *CRegistroMedico::seleccionarCategoria(string nombreCat) {}

Diagnostico *CRegistroMedico::crearDiagnostico(ProblemaDeSalud pds, string descripcion) {}
void CRegistroMedico::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos) {}
void CRegistroMedico::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha) {}
void CRegistroMedico::agregarDiagnostico(Diagnostico diagnostico) {}
list<DTCategoriaRep> CRegistroMedico::listarRepresentaciones() {}

CRegistroMedico::~CRegistroMedico()
{
}