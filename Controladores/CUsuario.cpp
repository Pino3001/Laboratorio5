#include "CUsuario.h"
#include "Usuario.h"
#include "CategoriaUsuario.h"
#include "Medico.h"
#include "Socio.h"
#include "Administrativo.h"
#include "Actividad.h"
#include "Consulta.h"
#include "Comun.h"
#include "Emergencia.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTDatosUsuario.h"
#include <map>
#include <list>
#include <string>
using namespace std;

CUsuario *CUsuario::instance = nullptr;

CUsuario::CUsuario() : usrActivo(nullptr), memColUsuario(new map<string, Usuario *>()), memUsrSesion(new list<Usuario *>()), memMedicosSistema(new list<Medico *>) {}

CUsuario *CUsuario::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CUsuario();
    }
    return instance;
}

// metodos del controlador

bool CUsuario::existeUsuario(string ci)
{
    // Auto para no colocar map<string, Usuario*>::iterator
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        this->usrActivo = itu->second;
        return true;
    }
    else
    {
        return false;
    }
}

bool CUsuario::esUsuario(string ci)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CUsuario::verificarContrasenia(string contrasenia)
{
    return this->usrActivo->contraValida(contrasenia);
}

bool CUsuario::asignarSesion(string ci)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        this->usrActivo = itu->second;
        return true;
    }
    else
    {
        cout << "\n No se ha podido iniciar secion correctamente!!";
        return false;
    }
}

list<TipoUsuario> CUsuario::tipoDeUsuarioEnSesion(string ci)
{
    list<TipoUsuario> tUsr;
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        vector<CategoriaUsuario *> *catU = usr->getCatUsr();
        for (CategoriaUsuario *c : *catU)
        {
            if (c != nullptr)
            {
                if (dynamic_cast<Administrativo *>(c))
                {
                    tUsr.push_back(TipoUsuario::Tipo_Administrativo);
                }
                if (dynamic_cast<Socio *>(c))
                {
                    tUsr.push_back(TipoUsuario::Tipo_Socio);
                }
                if (dynamic_cast<Medico *>(c))
                {
                    tUsr.push_back(TipoUsuario::Tipo_Medico);
                }
                else
                {
                    tUsr.push_back(TipoUsuario::UNKNOWN);
                }
            }
        }
        return tUsr;
    }
    throw runtime_error("El Usuario con la cedula " + ci + " no existe en el sistema!.");
}

DTDatosUsuario CUsuario::obtenerDatosSocio(string ci)
{
    // Auto para no colocar map<string, Usuario*>::iterator
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {

        DTDatosUsuario dtu = itu->second->getDatosUsuario();
        return dtu;
    }
    else
    {
        throw runtime_error("El Usuario con la cedula " + ci + " no existe en el sistema!.");
    }
}

bool CUsuario::primerContrasenia()
{
    if (this->usrActivo->getPrimeraContrasenia())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CUsuario::darPrimerContrasenia(string contrasenia)
{
    this->usrActivo->setContrasenia(contrasenia);
    this->usrActivo->setPrimeraContrasenia(false);
}

void CUsuario::altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> tUsr)
{

    // Creo las categorias de usuario que tendra el Usuario.
    vector<CategoriaUsuario *> *catUsr = new vector<CategoriaUsuario *>;
    for (TipoUsuario t : tUsr)
    {
        if (t == TipoUsuario::Tipo_Socio)
        {
            Socio *s = new Socio();
            catUsr->push_back(s);
        }
        else if (t == TipoUsuario::Tipo_Administrativo)
        {
            Administrativo *a = new Administrativo();

            catUsr->push_back(a);
        }
        else if (t == TipoUsuario::Tipo_Medico)
        {
            Medico *m = new Medico();
            catUsr->push_back(m);
            this->memMedicosSistema->push_back(m);
        }
    }
    // Creo Usuario
    Usuario *newUsr = new Usuario(ci, nomb, apell, sexo, fechNac, catUsr);
    for (CategoriaUsuario *c : *catUsr)
    {
        c->setUsuarioVinculado(newUsr);
    }
    // Inserto Usuario en la coleccion de usuarios en memoria
    auto incerto = this->memColUsuario->insert(make_pair(ci, newUsr));
    if (!incerto.second)
    {
        delete catUsr;
        delete newUsr;
        throw runtime_error("El Usuario con la cedula " + ci + " ya existe en el sistema!.");
    }
}

bool CUsuario::cerrarSesion()
{
    this->usrActivo = nullptr;
    return false;
}

Usuario *CUsuario::darUsuario(string ci)
{
    auto itUsr = this->memColUsuario->find(ci);
    if (itUsr != memColUsuario->end())
    {
        return itUsr->second;
    }
    return nullptr;
}

Medico *CUsuario::darMedico(string ci)
{
    Usuario *usrMed = darUsuario(ci);
    if (usrMed != nullptr)
    {
        vector<CategoriaUsuario *> *catUm = usrMed->getCatUsr();
        for (CategoriaUsuario *c : *catUm)
        {
            if (Medico *med = dynamic_cast<Medico *>(c))
            {
                med->setUsuarioVinculado(usrMed);
                return med;
            }
        }
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}

Socio *CUsuario::darSocio(string ci)
{
    Usuario *usrSocio = darUsuario(ci);
    if (usrSocio != nullptr)
    {
        vector<CategoriaUsuario *> *catUm = usrSocio->getCatUsr();
        for (CategoriaUsuario *c : *catUm)
        {
            if (Socio *soc = dynamic_cast<Socio *>(c))
            {
                return soc;
            }
        }
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}

list<DTDatosUsuario> CUsuario::listarMedicos()
{
    list<DTDatosUsuario> lisDTD;
    for (Medico *med : *this->memMedicosSistema)
    {
        DTDatosUsuario dc = med->getUsuarioVinculado()->getDatosUsuario();
        lisDTD.push_back(dc);
    }
    return lisDTD;
}

list<DTConsulta> CUsuario::obtenerReservas(string ciSocio)
{
    list<DTConsulta> liDTC;
    auto itu = this->memColUsuario->find(ciSocio);
    if (itu != memColUsuario->end())
    {
        vector<CategoriaUsuario *> *lCU = itu->second->getCatUsr();
        for (CategoriaUsuario *c : *lCU)
        {
            if (Socio *socio = dynamic_cast<Socio *>(c))
            {
                liDTC = socio->obtenerReservasActivas();
            }
        }
    }
    return liDTC;
}

CUsuario::~CUsuario() {}
