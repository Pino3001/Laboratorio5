#ifndef CUSUARIO_H
#define CUSUARIO_H
#include "IUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include <map>
#include <list>
#include <string>
using namespace std;

class CUsuario : public IUsuario
{
private:
    Usuario *usrActivo;
    map<string, Usuario *> *memColUsuario;
    list<Usuario *> *memUsrSecion;

public:
    // ver si pasar como parametro al usuario administrativo por defecto
    CUsuario();
    // metodos controlador
    void crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña);
    bool existeUsuario(string ci);
    bool verificarContraseña(string ci, string contraseña);
    bool asignarSesion(string ci);
    TipoUsuario* tipoDeUsuario(string ci);

    DTDatosUsuario buscarUser(string ci);
    bool primerContraseña(string contraseña);
    void altaUsuario();
    void cerrarSesion();
    void altaUsuario(string ci, string nomb, string apell, string sexo, DTFecha fechNac, TipoUsuario tUsr[2]);
    set<DTHistorial> mostrarHistorialPorMedico(string ci);

    void cancelarIntento();
    //bool existeUsuario(string ci);
    void cancelarIntento();
    DTDatosUsuario buscarUser();
    void activarUsr();
    set<DTReserva> mostrarReservasActivas();
    void camcelarReserva(string idConsulta);
    void registroConsulta(string ci, string idConsulta);
    void registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion);

    DTDatosUsuario obtenerDatosSocio();
    ~CUsuario();
};

#endif