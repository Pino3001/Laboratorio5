#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "DTDatosUsuario.h"
#include <string>
#include "definiciones.h"

class IUsuario
{
public:
    // Todos los metodos del controlador

    virtual DTDatosUsuario buscarUser(string ci)= 0;
    virtual bool verificarContraseña(string contraseña)= 0;
    virtual bool primerContraseña(string contraseña)= 0;
    virtual void cancelarIntento()= 0;
    virtual void asignarSesion()= 0;
    virtual void cerrarSesion()= 0;
    void existeUsuario(string ci )= 0;
    virtual void altaUsuario(string nombre, string sexo, DTFecha nacimiento, TipoUsuario tipo[MAX_TIPO_USUARIO])= 0;
    virtual void cancelarIntento()= 0;
    virtual DTDatosUsuario buscarUser()= 0;
    virtual void activarUsr()= 0;
    virtual set<DTReserva> mostrarReservasActivas()= 0;
    virtual void camcelarReserva(string idConsulta)= 0;
    virtual void registroConsulta(string ci, string idConsulta)= 0;
    virtual void registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion)= 0;
    virtual bool buscarSocio(string ci)= 0;
    virtual DTDatosUsuario obtenerDatosSocio()= 0;
    virtual set<DTHistorial>  mostrarHistorialPorMedico()= 0;
    virtual ~IUsuario() = default;
};

#endif