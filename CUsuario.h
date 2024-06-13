#ifndef CUSUARIO_H
#define CUSUARIO_H

#include "IUsuario.h"
#include "Usuario.h"
#include <map>
#include <list>
#include <string>
using namespace std;

class CUsuario : public IUsuario {
private:
    Usuario *usrActivo;
    map <string, Usuario*> *memColUsuario;
    list <Usuario*> *memUsrSecion;

public:
    // ver si pasar como parametro al usuario administrativo por defecto
    CUsuario();
    // metodos controlador
    DTDatosUsuario buscarUser(string ci);
    bool verificarContraseña(string contraseña);
    bool primerContraseña(string contraseña);
    void cancelarIntento();
    void asignarSesion();
    void cerrarSesion();
    void existeUsuario(string ci );
    void altaUsuario(string nombre, string sexo, DTFecha nacimiento, TipoUsuario tipo[MAX_TIPO_USUARIO]);
    void cancelarIntento();
    DTDatosUsuario buscarUser();
    void activarUsr();
    set<DTReserva> mostrarReservasActivas();
    void camcelarReserva(string idConsulta);
    void registroConsulta(string ci, string idConsulta);
    void registroConsultaEmergencia(string ci, string ciMedico, DTFecha fecha, DTHora hora, string descrpcion);
    bool buscarSocio(string ci);
    DTDatosUsuario obtenerDatosSocio();
    set<DTHistorial>  mostrarHistorialPorMedico();
    ~CUsuario();

};

#endif 