#include "CUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include "Medico.h"
#include "Socio.h"
#include "Administrativo.h"
#include <map>
#include <list>
#include <string>
using namespace std;

CUsuario::CUsuario()
{
    this->usrActivo = usrActivo;
    map<string, Usuario *> *ColUsuario = new map<string, Usuario *>;
    this->memColUsuario = ColUsuario;
    list<Usuario *> *UsrSecion = new list<Usuario *>;
    this->memUsrSecion = UsrSecion;
}

// metodos del controlador
void CUsuario::crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña)
{
    // Creo las categorias de usuario que tendra el Usuario.
    CategoriaUsuario *catUsr[MAX_TIPO_USUARIO];
    catUsr[0] = new Administrativo();
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
        return true;
    }
    else
    {
        return false;
    }
}

bool CUsuario::verificarContraseña(string ci, string contraseña)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        return this->usrActivo->contraValida(contraseña);
    }
    else
    {
        return false;
    }
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

TipoUsuario *CUsuario::tipoDeUsuario(string ci)
{
    TipoUsuario *tUsr = new TipoUsuario[MAX_TIPO_USUARIO];
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        CategoriaUsuario **catU = usr->getCatUsr();
        for (int i = 0; i < MAX_TIPO_USUARIO; ++i)
        {
            if (catU[i] != nullptr)
            {
                if (dynamic_cast<Administrativo *>(catU[i]))
                {
                    tUsr[i] = TipoUsuario::Tipo_Administrativo;
                }
                if (dynamic_cast<Socio *>(catU[i]))
                {
                    tUsr[i] = TipoUsuario::Tipo_Socio;
                }
                if (dynamic_cast<Medico *>(catU[i]))
                {
                    tUsr[i] = TipoUsuario::Tipo_Medico;
                }
                else
                {
                    tUsr[i] = TipoUsuario::UNKNOWN;
                }
            }
        }
        return tUsr;
    }
    else
    {
        for (int i = 0; i < MAX_TIPO_USUARIO; ++i)
        {
            tUsr[i] = TipoUsuario::ERROR;
        }
        return tUsr;
    }
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

bool CUsuario::primerContraseña(string contraseña)
{
    if (this->usrActivo->getPrimeraContraseña())
    {
        this->usrActivo->setContraseña(contraseña);
    }
    else
    {
        return false;
    }
}

void CUsuario::altaUsuario(string ci, string nomb, string apell, string sexo, DTFecha fechNac, TipoUsuario tUsr[MAX_TIPO_USUARIO])
{
    Usuario *usr = this->usrActivo;
    CategoriaUsuario **catU = usr->getCatUsr();

    for (int i = 0; i < MAX_TIPO_USUARIO; ++i)
    {
        if (catU[i] != nullptr)
        {
            // Casteo para ver que tipo de socio esta intentando hacer un ingreso.
            if (dynamic_cast<Administrativo *>(catU[i]))
            {
                // Creo las categorias de usuario que tendra el Usuario.
                CategoriaUsuario *catUsr[MAX_TIPO_USUARIO];
                for (int i = 0; i < MAX_TIPO_USUARIO; i++)
                {
                    if (tUsr[i] == Tipo_Socio)
                    {
                        catUsr[i] = new Socio();
                    }
                    else if (tUsr[i] == Tipo_Administrativo || tUsr[i] == Administrativo_defecto)
                    {
                        catUsr[i] = new Administrativo();
                    }
                    else if (tUsr[i] == Tipo_Medico)
                    {
                        catUsr[i] = new Medico();
                    }
                    else
                    {
                        catUsr[i] = nullptr;
                    }
                }
                // Creo Usuario
                Usuario *newUsr = new Usuario(ci, nomb, apell, sexo, fechNac, catUsr);
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

void CUsuario::cerrarSesion()
{
    this->usrActivo = nullptr;
    cout << "\n Sesion terminada!";
}

void CUsuario::registroConsulta(string ci, string idConsulta)
{
    // Ver de comprobar antes si el usuario es un socio
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        CategoriaUsuario **catU = usr->getCatUsr();
        for (int i = 0; i < MAX_TIPO_USUARIO; ++i)
        {
            if (catU[i] != nullptr)
            {
                if (Socio *paciente = dynamic_cast<Socio *>(catU[i]))
                {
                    EstadoConsulta asistio = EstadoConsulta::Asistio;
                    // usr->registrarAsistencia(asistio, idConsulta);
                    paciente->registrarAsistencia(asistio, idConsulta);
                }
            }
        }
    }
    else
    {
        cout << "\n No se encontro el usuario en el sistema.";
    }
}

set<DTHistorial> CUsuario::mostrarHistorialPorMedico(string ci)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
        Usuario *usr = itu->second;
        CategoriaUsuario **catU = usr->getCatUsr();
        for (int i = 0; i < MAX_TIPO_USUARIO; ++i)
        {
            if (catU[i] != nullptr)
            {
                if (Socio *paciente = dynamic_cast<Socio *>(catU[i]))
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
void CUsuario::registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion) {}
// bool CUsuario::buscarSocio(string ci) {}
DTDatosUsuario CUsuario::obtenerDatosSocio() {}

CUsuario::~CUsuario()
{
    // Destructor
}