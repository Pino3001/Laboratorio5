#ifndef IUSUARIO_H
#define IUSUARIO_H
#include "Usuario.h"
#include <string>
#include "DTDatosUsuario.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include "definiciones.h"

class IUsuario
{
public:
    // Todos los metodos del controlador

    virtual void crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña) = 0;
    virtual bool existeUsuario(string ci) = 0;
    virtual bool verificarContraseña(string ci, string contraseña) = 0;
    virtual bool asignarSesion(string ci) = 0;
    virtual TipoUsuario* tipoDeUsuario(string ci)=0;
    virtual void altaUsuario(string ci, string nomb, string apell, string sexo, DTFecha fechNac, TipoUsuario tUsr[MAX_TIPO_USUARIO]) = 0;
    virtual void registroConsulta(string ci, string idConsulta) = 0;

    virtual DTDatosUsuario buscarUser(string ci) = 0;

    virtual bool primerContraseña(string contraseña) = 0;
    virtual void cancelarIntento() = 0;

    virtual void cerrarSesion() = 0;
    // virtual void cancelarIntento()= 0;
    virtual DTDatosUsuario buscarUser() = 0;
    virtual void activarUsr() = 0;
    virtual set<DTReserva> mostrarReservasActivas() = 0;
    virtual void camcelarReserva(string idConsulta) = 0;

    virtual void registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion) = 0;

    virtual DTDatosUsuario obtenerDatosSocio() = 0;
    virtual set<DTHistorial> mostrarHistorialPorMedico(string ci) = 0;
    virtual ~IUsuario() = default; 
};
#endif
/* #endif */