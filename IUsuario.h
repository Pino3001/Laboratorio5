#ifndef IUSUARIO_H
#define IUSUARIO_H
#include "Usuario.h"
#include <string>
#include "DTDatosUsuario.h"
#include "DTConsulta.h"
#include "definiciones.h"

class IUsuario
{
public:
    // Todos los metodos del controlador

    virtual bool existeUsuario(string ci) = 0;
    virtual bool esUsuario(string ci)=0;
    virtual bool verificarContrasenia(string contrasenia) = 0;
    virtual bool primerContrasenia() = 0;
    virtual void darPrimerContrasenia(string contrasenia)=0;
    virtual bool asignarSesion(string ci) = 0;
    virtual list<TipoUsuario> * tipoDeUsuario(string ci)=0;
    virtual void altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> tUsr) = 0;
    virtual bool cerrarSesion() = 0;
    virtual DTDatosUsuario obtenerDatosSocio(string ci) = 0;
    virtual list<DTDatosUsuario>  listarMedicos()=0;
    virtual list<DTConsulta> obtenerReservas(string ciSocio)=0;


    virtual ~IUsuario() = default;
};
#endif
