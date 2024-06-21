#ifndef CUSUARIO_H
#define CUSUARIO_H
#include "IUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include <map>
#include <list>
#include <string>
class Actividad;
using namespace std;

class CUsuario : public IUsuario
{
private:
    static CUsuario* instance;
    Usuario *usrActivo;
    map<string, Usuario *> *memColUsuario;
    list<Usuario *> *memUsrSesion;

    CUsuario();

public:
    static CUsuario* getInstance();
    // ver si pasar como parametro al usuario administrativo por defecto
    
    // metodos controlador
    void crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña);
    bool existeUsuario(string ci);
    bool esUsuario(string ci);
    bool verificarContraseña(string ci, string contraseña);
    bool asignarSesion(string ci);
    list<TipoUsuario> *tipoDeUsuario(string ci);
    DTDatosUsuario buscarUser(string ci);
    bool primerContraseña();
    void darPrimerContraseña(string contrasenia);
    bool cerrarSesion();
    void altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> *tUsr);
    set<DTHistorial> mostrarHistorialPorMedico(string ci);

    Usuario *darUsuario(string ci);

    void cancelarIntento();
    DTDatosUsuario buscarUser();
    void activarUsr();
    set<DTReserva> mostrarReservasActivas();
    void camcelarReserva(string idConsulta);
    void registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion);

    DTDatosUsuario obtenerDatosSocio();
    ~CUsuario();
};

#endif