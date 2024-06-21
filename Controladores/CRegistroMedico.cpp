#include "CRegistroMedico.h"
#include "CUsuario.h"
#include "ProblemaDeSalud.h"
#include "CategoriaProblemaSalud.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTConsulta.h"
#include "Actividad.h"
#include "Consulta.h"
#include "Comun.h"
#include "Emergencia.h"
#include "Medico.h"
#include "Socio.h"
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
            if (Emergencia *emer = dynamic_cast<Emergencia *>(a))
            {

                DTConsulta dtcons = emer->getDatosConsulta();
                listDTC.push_back(dtcons);
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
    for (auto &parVal : *this->problemasDeSalud)
    {
        DTCategoriaRep dcr = DTCategoriaRep(parVal.second->getIdCategoria(), parVal.second->getDescripcion());
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

    Medico *m = CUsuario::getInstance()->darMedico(ciMedico);
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);
    Usuario *usrSocio = CUsuario::getInstance()->darUsuario(ciSocio);
    if (m != nullptr && s != nullptr)
    {
        Comun *cons = new Comun(fecReserva, EstadoConsulta::Reservada, fechaConsulta, horaCosn, s, m);
        s->addActividad(cons, m->verCi());
        m->addActividad(cons);
        cout << "\n\n Se creo la consulta, o eso parece";
    }
    else if (m == nullptr)
    {
        /* El usuario de la cedula no es medico */
    }
    else if (s == nullptr)
    {
        /* El usuario de la cedula no es socio */
    }
}

void CRegistroMedico::altaDiagnosticoConsulta(map<string, map<string, string>> *problAsoc, string descripDiagnostico, bool esQuirurgico, bool esFarmaco, list<string> *medicamentos, string descripFarmaco, const DTFecha fechaCirujia, string ciMedicoCirujano, string descripcionQuirurji)
{
    Consulta *cons = this->memConsulta;
    list<ProblemaDeSalud *> *listProb = new list<ProblemaDeSalud *>;

    for (auto &[idCat, problemas] : *problAsoc)
    {
        auto itCat = this->problemasDeSalud->find(idCat);
        if (itCat != problemasDeSalud->end())
        {
            for (auto &[codigo, etiqueta] : problemas)
            {
                ProblemaDeSalud *p = itCat->second->seleccionarProblemaDeSalud(codigo, etiqueta);
                if (p != nullptr)
                {
                    listProb->push_back(p);
                }
            }
        }
    }
    if (esQuirurgico)
    {
        bool creado = false;
        Medico *m = CUsuario::getInstance()->darMedico(ciMedicoCirujano);
        if (m != nullptr)
        {
            this->memConsulta->crearDiagnosticoTratQuirurjico(descripDiagnostico, listProb, m, descripcionQuirurji, fechaCirujia);
            creado = true;
        }
        else if (m == nullptr || creado == false)
        {
            cout << "\n\n\t No se creo la consulta!";
        }
    }
    else if (esFarmaco)
    {
        this->memConsulta->crearDiagnosticoTratFarmaco(descripFarmaco, listProb, medicamentos, descripFarmaco);
    }
    else
    {
        this->memConsulta->crearDiagnostico(descripDiagnostico, listProb);
    }
    // Leberar memoria de los map creados en el main
    delete problAsoc;
}

void CRegistroMedico::seleccionarConsulta(string ciSocio, string ciMedico, const DTFecha fechaCons)
{
    Medico *usrMedico = CUsuario::getInstance()->darMedico(ciMedico);
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);

    auto itCons = this->memActividades->find(fechaCons);
    if (itCons != memActividades->end())
    {
        for (Actividad *a : itCons->second)
        {
            if (Comun *comun = dynamic_cast<Comun *>(a))
            {
                // De las consultas de tipo comun comparo los datos de estas, con los que estoy buscando y compruebo que sean consultas Activas.
                if (comun->obtenerCiMedico() == ciMedico && comun->obtenerCiSocio() == ciSocio && comun->getEstadoConsulta() == EstadoConsulta::Asistio)
                {
                    this->memConsulta = comun;
                    break;
                }
            }
            else if (Emergencia *emer = dynamic_cast<Emergencia *>(a))
            {
                if (emer->obtenerCiMedico() == ciMedico && emer->obtenerCiSocio() == ciSocio)
                {
                    this->memConsulta = emer;
                    break;
                }
            }
        }
        if (this->memConsulta == nullptr)
        {
            // No se encontro actividad para el socio y medico
        }
    }
    else
    {
        // No existen actividades en la fecha
    }
}

void CRegistroMedico::crearHistorialPaciente(){
    this->memConsulta->crearHistorial();
}

list<DTHistorial> CRegistroMedico::obtenerHistorialPaciente(string ciSocio){
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);
    return s->mostrarHistorialPorMedico();
}

void CRegistroMedico::registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion) {}

void CRegistroMedico::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos) {}
void CRegistroMedico::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha) {}
void CRegistroMedico::agregarDiagnostico(Diagnostico diagnostico) {}
list<DTCategoriaRep> CRegistroMedico::listarRepresentaciones() {}

CRegistroMedico::~CRegistroMedico()
{
}