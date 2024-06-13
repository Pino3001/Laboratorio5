#include "CUsuario.h"
#include <iostream>
#include <string>

CUsuario::CUsuario()
{
    this->usrActivo = usrActivo;
    map <string, Usuario*> *ColUsuario = new map <string, Usuario*>;
    this->memColUsuario = ColUsuario;
    list <Usuario*> *UsrSecion = new list <Usuario*>;
    this->memUsrSecion = UsrSecion;
}


// metodos del controlador

DTDatosUsuario CUsuario::buscarUser(string ci){}
bool CUsuario::verificarContraseña(string contraseña){

}
bool CUsuario::primerContraseña(string contraseña){}
void CUsuario::cancelarIntento(){}
void CUsuario::asignarSesion(){}
void CUsuario::cerrarSesion(){}
void CUsuario::existeUsuario(string ci){}
void CUsuario::altaUsuario(string nombre, string sexo, DTFecha nacimiento, TipoUsuario tipo[MAX_TIPO_USUARIO]){}
void CUsuario::cancelarIntento(){}
DTDatosUsuario CUsuario::buscarUser(){}
void CUsuario::activarUsr(){}
set<DTReserva> CUsuario::mostrarReservasActivas(){}
void CUsuario::camcelarReserva(string idConsulta){}
void CUsuario::registroConsulta(string ci, string idConsulta){}
void CUsuario::registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion){}
bool CUsuario::buscarSocio(string ci){}
DTDatosUsuario CUsuario::obtenerDatosSocio(){}
set<DTHistorial> CUsuario::mostrarHistorialPorMedico(){}

CUsuario::~CUsuario()
{
    // Destructor
}