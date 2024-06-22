#include "CUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include "DTDatosUsuario.h"
#include "Medico.h"
#include "Socio.h"
#include "Administrativo.h"
#include "Actividad.h"
#include "Consulta.h"
#include "Comun.h"
#include "Emergencia.h"
#include <map>
#include <list>
#include <string>
using namespace std;

CUsuario *CUsuario::instance = nullptr;

CUsuario::CUsuario() : usrActivo(nullptr), memColUsuario(new map<string, Usuario *>()), memUsrSesion(new list<Usuario *>()) {}

CUsuario *CUsuario::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CUsuario();
    }
    return instance;
}

// metodos del controlador
void CUsuario::crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña)
{
    // Creo las categorias de usuario que tendra el Usuario.
    list<CategoriaUsuario *> *catUsr = new list<CategoriaUsuario *>;
    Administrativo *a = new Administrativo();
    catUsr->push_back(a);
    // Creo Usuario
    Usuario *newUsr = new Usuario(cedula, nombre, apellido, contraseña, catUsr);
    newUsr->addVisibilityCatUsr();
    // Inserto Usuario en la coleccion de usuarios en memoria
    auto incerto = this->memColUsuario->insert(make_pair(cedula, newUsr));
    if (incerto.second)
    {
        cout << "\n Se a creado el Usuario exitosamente!! ";
    }
    else
    {
        cout << "\n No se a podido crear el Administrativo por defecto. ";
    }
}

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

bool CUsuario::verificarContraseña(string ci, string contraseña)
{
    return this->usrActivo->contraValida(contraseña);
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

list<TipoUsuario> *CUsuario::tipoDeUsuario(string ci)
{
    list<TipoUsuario> *tUsr = new list<TipoUsuario>;
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        list<CategoriaUsuario *> *catU = usr->getCatUsr();
        for (CategoriaUsuario *c : *catU)
        {
            if (c != nullptr)
            {
                if (dynamic_cast<Administrativo *>(c))
                {
                    tUsr->push_back(TipoUsuario::Tipo_Administrativo);
                }
                if (dynamic_cast<Socio *>(c))
                {
                    tUsr->push_back(TipoUsuario::Tipo_Socio);
                }
                if (dynamic_cast<Medico *>(c))
                {
                    tUsr->push_back(TipoUsuario::Tipo_Medico);
                }
                else
                {
                    tUsr->push_back(TipoUsuario::UNKNOWN);
                }
            }
        }
        return tUsr;
    }
    return nullptr;
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
        DTDatosUsuario dtu;
        return dtu;
    }
}

bool CUsuario::primerContraseña()
{
    if (this->usrActivo->getPrimeraContraseña())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CUsuario::darPrimerContraseña(string contrasenia)
{
    this->usrActivo->setContraseña(contrasenia);
    this->usrActivo->setPrimeraContraseña(true);
}

void CUsuario::altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> *tUsr)
{

    // Creo las categorias de usuario que tendra el Usuario.
    list<CategoriaUsuario *> *catUsr = new list<CategoriaUsuario *>;
    for (TipoUsuario t : *tUsr)
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
            catUsr->push_back(new Medico());
        }
    }
    // Creo Usuario
    Usuario *newUsr = new Usuario(ci, nomb, apell, sexo, fechNac, catUsr);
    delete tUsr;
    newUsr->addVisibilityCatUsr();
    // Inserto Usuario en la coleccion de usuarios en memoria
    auto incerto = this->memColUsuario->insert(make_pair(ci, newUsr));
    if (incerto.second)
    {
        std::cout << "\n Se a creado el Usuario exitosamente!! ";
    }
    else
    {
        std::cout << "El Usuario con la cedula " << ci << " ya existe en el sistema!!";
        delete catUsr;
        delete newUsr;
    }
    // Corto iteracion por posible incercion repetida.
}

bool CUsuario::cerrarSesion()
{
    this->usrActivo = nullptr;
    return false;
    cout << "\n Sesion terminada!";
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
        list<CategoriaUsuario *> *catUm = usrMed->getCatUsr();
        for (CategoriaUsuario *c : *catUm)
        {
            if (Medico *med = dynamic_cast<Medico *>(c))
            {
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
        list<CategoriaUsuario *> *catUm = usrSocio->getCatUsr();
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



void CUsuario::cancelarIntento() {}
void CUsuario::activarUsr() {}
set<DTReserva> CUsuario::mostrarReservasActivas() {}
void CUsuario::camcelarReserva(string idConsulta) {}
// bool CUsuario::buscarSocio(string ci) {}

CUsuario::~CUsuario()
{
    // Destructor
}