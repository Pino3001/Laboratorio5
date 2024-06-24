#ifndef CUSUARIO_H
#define CUSUARIO_H
#include "IUsuario.h"
#include "Usuario.h"
#include "Medico.h"
#include "DTFecha.h"
#include "DTHora.h"
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
    list<Medico*> *memMedicosSistema;

    CUsuario();

public:
    static CUsuario *getInstance();

    // metodos controlador
    bool existeUsuario(string ci);
    bool esUsuario(string ci);
    bool verificarContrasenia(string contrasenia);
    bool primerContrasenia();
    void darPrimerContrasenia(string contrasenia);
    bool asignarSesion(string ci);
    list<TipoUsuario> tipoDeUsuarioEnSesion(string ci);
    DTDatosUsuario buscarUser(string ci);
    void altaUsuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<TipoUsuario> tUsr);
    bool cerrarSesion();
    DTDatosUsuario obtenerDatosSocio(string ci);
    list<DTDatosUsuario>  listarMedicos();
    Usuario *darUsuario(string ci);
    Medico *darMedico(string ci);
    Socio *darSocio(string ci);
    list<DTConsulta> obtenerReservas(string ciSocio);

    ~CUsuario();
};

#endif
