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
#include <stdexcept>
#include <iostream>
#include "definiciones.h"

CRegistroMedico *CRegistroMedico::instance = nullptr;

CRegistroMedico::CRegistroMedico() : memConsulta(nullptr), categoriasProblemas(new map<string, CategoriaProblemaSalud *>()), memActividades(new map<DTFecha, list<Actividad *>>()) {}

CRegistroMedico *CRegistroMedico::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CRegistroMedico();
    }
    return instance;
}

void CRegistroMedico::addMemActividad(Actividad *act, DTFecha fecha)
{
    auto itAct = this->memActividades->find(fecha);
    if (itAct != this->memActividades->end())
    {
        itAct->second.push_back(act);
    }
    else
    {
        list<Actividad *> a;
        a.push_back(act);
        this->memActividades->insert(make_pair(fecha, a));
    }
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
    bool registrada = false;
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
                if (comun->getMedicoRealiza()->getUsuarioVinculado()->getCedula() == ciMedico && comun->getSocioConsulta()->getUsuarioVinculado()->getCedula() == ci && comun->getEstadoConsulta() == EstadoConsulta::Reservada)
                {
                    // Cambio el estado de la consulta para sacarla de la reserva.
                    comun->setEstadoConsulta(EstadoConsulta::Asistio);
                    registrada = true;
                }
            }
        }
    }
    else
    {
        throw runtime_error("No existen consultas para la fecha dada!.");
    }
    if (!registrada)
    {
        throw runtime_error("La consulta no ha sido registrada!.");
    }
}

void CRegistroMedico::cancelarReservaConsuta(string ci, string ciMedico, const DTFecha fechaConsulta)
{
    bool cancelada = false;
    // Busco en el map si existe una lista de consultas para el dia pasado como parametro.
    auto itu = this->memActividades->find(fechaConsulta);
    if (itu != memActividades->end())
    {
        // Si existe obtengo la lista de Actividades de ese dia.
        for (Actividad *a : itu->second)
        {
            // Recorro la lista buscando las consultas de tipo comun.
            if (Comun *comun = dynamic_cast<Comun *>(a))
            {
                // De las consultas de tipo comun comparo los datos de estas, con los que estoy buscando y compruebo que sean consultas reservadas.
                if (comun->getMedicoRealiza()->getUsuarioVinculado()->getCedula() == ciMedico && comun->getSocioConsulta()->getUsuarioVinculado()->getCedula() == ci && comun->getEstadoConsulta() == EstadoConsulta::Reservada)
                {
                    // Cambio el estado de la consulta para sacarla de la reserva.
                    comun->setEstadoConsulta(EstadoConsulta::Cancelada);
                    cancelada = true;
                }
            }
        }
    }
    else
    {
        throw runtime_error("No existen consultas para la fecha dada!.");
    }
    if (!cancelada)
    {
        throw runtime_error("La consulta no ha sido cancelada!.");
    }
}

list<DTCategoriaRep> CRegistroMedico::mostrarDatosCategorias()
{
    list<DTCategoriaRep> ldt;
    for (auto parVal : *this->categoriasProblemas)
    {
        DTCategoriaRep dcr = DTCategoriaRep(parVal.second->getIdCategoria(), parVal.second->getDescripcion());
        ldt.push_back(dcr);
    }
    return ldt;
}

void CRegistroMedico::altaCategoriaRepresentacion(string id, string descripcion)
{
    CategoriaProblemaSalud *cat = new CategoriaProblemaSalud(id, descripcion);
    auto resultado = this->categoriasProblemas->insert(make_pair(id, cat));
    if (!resultado.second)
    {
        delete cat;
        throw runtime_error("Categoria con ID " + id + " Ya existe..");
    }
}

void CRegistroMedico::altaProblemaDeSalud(string id, string codigo, string etiqueta)
{
    auto it = this->categoriasProblemas->find(id);
    if (it != categoriasProblemas->end())
    {
        it->second->altaProblemas(codigo, etiqueta);
    }
    else
    {
        throw runtime_error("Categoria de problema con ID " + id + " no encontrada..");
    }
}

void CRegistroMedico::reservaNuevaConsulta(string ciMedico, string ciSocio, const DTFecha fechaConsulta, const DTFecha fecReserva, const DTHora horaCosn)
{
    Medico *m = CUsuario::getInstance()->darMedico(ciMedico);
    if (m == nullptr)
    {
        throw runtime_error("El usuario de la cedula " + ciMedico + " no es socio!.");
    }
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);
    if (s == nullptr)
    {
        throw runtime_error("El usuario de la cedula " + ciSocio + " no es socio!.");
    }
    if (m != nullptr && s != nullptr)
    {
        Comun *cons = new Comun(fecReserva, EstadoConsulta::Reservada, fechaConsulta, horaCosn, s, m);
        m->addActividad(cons);
        s->addActividad(cons);
        auto itAct = this->memActividades->find(fechaConsulta);
        if (itAct != this->memActividades->end())
        {
            itAct->second.push_back(cons);
        }
        else if (itAct == this->memActividades->end())
        {
            list<Actividad *> a;
            a.push_back(cons);
            this->memActividades->insert(make_pair(fechaConsulta, a));
        }
        else
        {
            throw runtime_error("La consulta no ha sido creada!");
        }
    }
}

void CRegistroMedico::seleccionarConsulta(string ciSocio, string ciMedico, const DTFecha fechaCons)
{
    Medico *usrMedico = CUsuario::getInstance()->darMedico(ciMedico);
    if (usrMedico == nullptr)
    {
        throw runtime_error("La cedula ingresada no pertenece a un Medico!.");
    }
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);
    if (s == nullptr)
    {
        throw runtime_error("La cedula ingresada no pertenece a un Socio!.");
    }
    auto itCons = this->memActividades->find(fechaCons);
    if (itCons != memActividades->end())
    {
        for (Actividad *a : itCons->second)
        {
            if (a->getMedicoRealiza()->getUsuarioVinculado()->getCedula() == ciMedico && a->getSocioConsulta()->getUsuarioVinculado()->getCedula() == ciSocio)
            {
                if (Comun *comun = dynamic_cast<Comun *>(a))
                {
                    // De las consultas de tipo comun comparo los datos de estas, con los que estoy buscando y compruebo que sean consultas Activas.
                    if (comun->getEstadoConsulta() == EstadoConsulta::Asistio)
                    {
                        this->memConsulta = comun;
                        break;
                    }
                }
                else if (Emergencia *emer = dynamic_cast<Emergencia *>(a))
                {
                    this->memConsulta = emer;
                    break;
                }
            }
        }
        if (this->memConsulta == nullptr)
        {
            throw runtime_error("No se encontro una Actividad!.");
        }
    }
    else
    {
        throw runtime_error("No se encontro una Actividad para la fecha dada!.");
    }
}

list<DTConsulta> CRegistroMedico::obtenerHistorialPaciente(string ciSocio)
{
    Socio *s = CUsuario::getInstance()->darSocio(ciSocio);
    if (s == nullptr)
    {
        throw runtime_error("El Usuario con cedula " + ciSocio + " no es un socio.");
    }
    return s->mostrarHistorialPorMedico();
}

void CRegistroMedico::registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion)
{
    Medico *m = CUsuario::getInstance()->darMedico(ciMedico);
    Socio *s = CUsuario::getInstance()->darSocio(ci);
    if (m != nullptr && s != nullptr)
    {
        Emergencia *eme = new Emergencia(descrpcion, fecha, hora, s, m);
        s->addActividad(eme);
        m->addActividad(eme);
        addMemActividad(eme, fecha);
    }
    else if (m == nullptr)
    {
        throw runtime_error("La cedula ingresada no pertenece a un Usuario Medico!!");
    }
    else if (s == nullptr)
    {
        throw runtime_error("La cedula ingresada no pertenece a un Socio!!");
    }
}

list<DTCategoriaRep> CRegistroMedico::listarRepresentacionesEstandarizadas()
{
    list<DTCategoriaRep> ldt;
    for (auto &catProb : *this->categoriasProblemas)
    {
        DTCategoriaRep dcr = DTCategoriaRep(catProb.second->getIdCategoria(), catProb.second->getDescripcion(), catProb.second->getDTProblemasAsoc());
        ldt.push_back(dcr);
    }
    return ldt;
}

void CRegistroMedico::agregarTratamientoFarmaco(string descripcion, list<string> *listMedicamentos)
{
    if (this->diagnosticoMem == nullptr)
    {
        throw runtime_error("No se encontro un diagnostico!");
    }
    this->diagnosticoMem->agregarTratamientoFarmaco(listMedicamentos, descripcion);
}

void CRegistroMedico::agregarTratamientoQuirurgico(string ciMedicoCirujano, string descripcion, DTFecha fecha)
{
    Medico *m = CUsuario::getInstance()->darMedico(ciMedicoCirujano);
    if (m == nullptr)
    {
        throw runtime_error("La cedula ingresada no pertenece a un Usuario Medico!!");
    }
    if (m != nullptr)
    {
        this->diagnosticoMem->agregarTratamientoQuirurgico(descripcion, fecha, m);
    }
}
void CRegistroMedico::agregarDiagnostico(map<string, list<string>> problAsoc, string descripcion)
{
    if (this->categoriasProblemas->empty())
    {
        throw runtime_error("No existen Problemas de salud en el sistema!.");
    }

    if (this->memConsulta == nullptr)
    {
        throw runtime_error("No se encontro la consulta!");
    }
    list<ProblemaDeSalud *> *listProb = new list<ProblemaDeSalud *>;
    for (auto pair : problAsoc)
    {
        auto itCat = this->categoriasProblemas->find(pair.first);
        if (itCat != this->categoriasProblemas->end())
        {
            for (auto problema : pair.second)
            {
                ProblemaDeSalud *p = itCat->second->seleccionarProblemaDeSalud(problema);
                if (p != nullptr)
                {
                    listProb->push_back(p);
                }
                else
                {
                    throw runtime_error("No se encontro el Problema de Salud con Codigo " + problema + "!");
                }
            }
        }
        else
        {
            throw runtime_error("No se encontro la Categoria de Problema de Salud de salud con ID " + pair.first + "!");
        }
    }
    this->diagnosticoMem = this->memConsulta->crearDiagnostico(descripcion, listProb);
}

void CRegistroMedico::eliminarUnDiagnostico()
{
    if (memConsulta != nullptr && diagnosticoMem != nullptr)
    {
        this->memConsulta->eliminarDiagnostico(this->diagnosticoMem);
        this->diagnosticoMem = nullptr;
    }
    else
    {
        throw runtime_error("No se encontro diagnostico o consulta para eliminar");
    }
}

CRegistroMedico::~CRegistroMedico()
{
}
