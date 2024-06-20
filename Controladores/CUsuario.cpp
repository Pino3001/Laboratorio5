#include "CUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include "DTHistorial.h"
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

CUsuario* CUsuario::instance = nullptr;

CUsuario::CUsuario() : usrActivo(nullptr), memColUsuario(new map<string, Usuario*>()), memUsrSesion(new list<Usuario*>()) {}

CUsuario* CUsuario::getInstance() {
    if (instance == nullptr) {
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

DTDatosUsuario CUsuario::buscarUser(string ci)
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

void CUsuario::darPrimerContraseña(string contraseña)
{
    this->usrActivo->setContraseña(contraseña);
    this->usrActivo->setPrimeraContraseña(true);
}

void CUsuario::altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> *tUsr)
{
    Usuario *usr = this->usrActivo;
    list<CategoriaUsuario *> *catU = usr->getCatUsr();

    for (CategoriaUsuario *c : *catU)
    {
        if (c != nullptr)
        {
            // Casteo para ver que tipo de socio esta intentando hacer un ingreso.
            if (dynamic_cast<Administrativo *>(c))
            {
                // Creo las categorias de usuario que tendra el Usuario.
                list<CategoriaUsuario *> *catUsr = new list<CategoriaUsuario *>;
                for (TipoUsuario t : *tUsr)
                {
                    if (t == TipoUsuario::Tipo_Socio)
                    {
                        catUsr->push_back(new Socio());
                    }
                    else if (t == TipoUsuario::Tipo_Administrativo || t == TipoUsuario::Administrativo_defecto)
                    {
                        catUsr->push_back(new Administrativo());
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
                    delete newUsr;
                }
                // Corto iteracion por posible incercion repetida.
                break;
            }
            else
            {
                cout << ANSI_COLOR_RED << "\n \t No eres un Usuario habilitado para crear nuevos Usuarios!!!" << ANSI_COLOR_RESET;
            }
        }
    }
}

bool CUsuario::cerrarSesion()
{
    this->usrActivo = nullptr;
    return false;
    cout << "\n Sesion terminada!";
}

set<DTHistorial> CUsuario::mostrarHistorialPorMedico(string ci)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        list<CategoriaUsuario *> *catU = usr->getCatUsr();
        for (CategoriaUsuario *c : *catU)
        {
            if (c != nullptr)
            {
                if (Socio *paciente = dynamic_cast<Socio *>(c))
                {
                    set<DTHistorial> serDth = paciente->mostrarHistorialPorMedico(usr);
                }
            }
        }
    }
    else
    {
        cout << "\n No se encontro el usuario en el sistema.";
    }
}

void CUsuario::cancelarIntento() {}
DTDatosUsuario CUsuario::buscarUser() {}
void CUsuario::activarUsr() {}
set<DTReserva> CUsuario::mostrarReservasActivas() {}
void CUsuario::camcelarReserva(string idConsulta) {}
void CUsuario::registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion) {}
// bool CUsuario::buscarSocio(string ci) {}
DTDatosUsuario CUsuario::obtenerDatosSocio() {}

CUsuario::~CUsuario()
{
    // Destructor
}