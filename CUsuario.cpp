#include "CUsuario.h"
#include "CategoriaUsuario.h"
#include "Socio.h"
#include "Administrativo.h"
#include "Medico.h"
#include "definiciones.h"
#include <iostream>
#include <string>
#include "iostream"

CUsuario::CUsuario()
{
    this->usrActivo = usrActivo;
    map<string, Usuario *> *ColUsuario = new map<string, Usuario *>;
    this->memColUsuario = ColUsuario;
    list<Usuario *> *UsrSecion = new list<Usuario *>;
    this->memUsrSecion = UsrSecion;
}

// metodos del controlador
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
        DTDatosUsuario dtu = DTDatosUsuario();
        return dtu;
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

bool CUsuario::primerContraseña(string contraseña)
{
    this->usrActivo->setContraseña(contraseña);
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
            if (Administrativo *admin = dynamic_cast<Administrativo *>(catU[i]))
            {
                // Creo las categorias de usuario que tendra el Usuario.
                CategoriaUsuario *catUsr[MAX_TIPO_USUARIO];
                for (int i = 0; i < MAX_TIPO_USUARIO; i++)
                {
                    if (tUsr[i] == Tipo_Socio)
                    {
                        catUsr[i] = new Socio();
                    }
                    else if (tUsr[i] == Tipo_Administrativo)
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
                Usuario *newUsr = new Usuario(ci, nomb, apell, sexo, fechNac, tUsr[MAX_TIPO_USUARIO], catUsr);
                // Inserto Usuario en la coleccion de usuarios en memoria
                auto incerto = this->memColUsuario.insert(std::make_pair(ci, *newUsr));
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

void CUsuario::asignarSesion(string ci)
{
    auto itu = this->memColUsuario->find(ci);
    if (itu != memColUsuario->end())
    {
       this->usrActivo = itu->second;
    }
    else
    {
        cout << "\n No se ha podido iniciar secion correctamente!!";
    }
}

void CUsuario::cerrarSesion() 
{
    this->usrActivo = nullptr;
    cout << "\n Secion terminada!"
}


void CUsuario::cancelarIntento() {}
void CUsuario::cancelarIntento() {}
DTDatosUsuario CUsuario::buscarUser() {}
void CUsuario::activarUsr() {}
set<DTReserva> CUsuario::mostrarReservasActivas() {}
void CUsuario::camcelarReserva(string idConsulta) {}
void CUsuario::registroConsulta(string ci, string idConsulta) {}
void CUsuario::registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion) {}
bool CUsuario::buscarSocio(string ci) {}
DTDatosUsuario CUsuario::obtenerDatosSocio() {}
set<DTHistorial> CUsuario::mostrarHistorialPorMedico() {}

CUsuario::~CUsuario()
{
    // Destructor
}