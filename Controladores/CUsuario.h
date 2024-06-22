#ifndef CUSUARIO_H
#define CUSUARIO_H
#include "IUsuario.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include "DTDatosUsuario.h"
#include <map>
#include <list>
#include <string>
class Actividad;
using namespace std;

class CUsuario : public IUsuario
{
private:
    static CUsuario *instance;
    Usuario *usrActivo;
    map<string, Usuario *> *memColUsuario;
    list<Usuario *> *memUsrSesion;

    CUsuario();

public:
    static CUsuario *getInstance();

    // metodos controlador
    void crearAdminDefecto(string nombre, string cedula, string apellido, string contraseña);
    bool existeUsuario(string ci);
    bool esUsuario(string ci);
    bool verificarContraseña(string ci, string contraseña);
    bool primerContraseña();
    void darPrimerContraseña(string contrasenia);
    bool asignarSesion(string ci);
    list<TipoUsuario> *tipoDeUsuario(string ci);
    DTDatosUsuario buscarUser(string ci);
    void altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> *tUsr);
    bool cerrarSesion();
    DTDatosUsuario obtenerDatosSocio(string ci);

    Usuario *darUsuario(string ci);
    Medico *darMedico(string ci);
    Socio *darSocio(string ci);

    void cancelarIntento();
    void activarUsr();
    set<DTReserva> mostrarReservasActivas();
    void camcelarReserva(string idConsulta);

    ~CUsuario();
};

#endif