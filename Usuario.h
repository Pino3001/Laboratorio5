#ifndef USUARIO_H
#define USUARIO_H

#include "CategoriaUsuario.h"
#include "Socio.h"
#include "Medico.h"
//#include "Administrativo.h"
#include "definiciones.h"
#include <list>
#include <string>

using namespace std;

class Usuario
{
private:
    string cedula;
    string nombre;
    string apellido;
    string contraseña;
    bool primeraContraseña;
    string sexo;
    DTFecha fechaNacimiento;
    int edad;
    bool activo;
    TipoUsuario tipoUsr[2];
    list<Actividad *> *actividadesUsr;
    CategoriaUsuario *catUsr[2];

public:
    Usuario();
    Usuario(string ci, string nomb, string apell, string sex, DTFecha fechNac, TipoUsuario tUsr[2]);
    Usuario(Usuario &usr);

    void setCedula(string cedula);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setContraseña(string contraseña);
    void setPrimeraContraseña(bool primeraContraseña);
    void setSexo(string sexo);
    void setFechaNacimiento(DTFecha fechaNacimiento);
    void setEdad(int edad);
    void setActivo(bool activo);
    void setTipoUsr(TipoUsuario *tipoUsr[2]);
    void setActividadesUsr(list<Actividad *> *actividadesUsr);
    void setCatUsr(CategoriaUsuario *catUsr[2]);

    string getCedula();
    string getNombre();
    string getApellido();
    string getContraseña();
    bool getPrimeraContraseña();
    string getSexo();
    DTFecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    TipoUsuario* getTipoUsr();
    list<Actividad *> *getActividadesUsr();
    CategoriaUsuario[*] getCatUsr();

    DTDatosUsuario getDatosUsuario();
    bool contraValida(string contra);
    void registrarAsistencia(EstadoConsulta estC);
    Actividad altaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
    void addActividad(Actividad actividad);
    set(DTReserva) mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    bool esSocio();
    set(DTHistorial) mostrarHistorialPorMedico();
    set(DTConsulta) mostrarDatosConsulta(DTFecha fecha);
    void buscarConsulta(string idConsulta);
    void addCatUsuario(CategoriaUsuario cat);

    ~Usuario();
};
#endif
