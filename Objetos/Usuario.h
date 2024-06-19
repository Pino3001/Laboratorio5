#ifndef USUARIO_H
#define USUARIO_H
#include "Administrativo.h"
#include "definiciones.h"
#include "DTDatosUsuario.h"
#include "DTReserva.h"
#include "DTHistorial.h"
#include <list>
#include <set>
#include <string>
class CategoriaUsuario;
class Medico;
class Socio;

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
    list<Actividad *> *actividadesUsr;
    CategoriaUsuario *catUsr[MAX_TIPO_USUARIO];

public:
    Usuario(string ci, string nomb, string apell, string sex, DTFecha fechNac, CategoriaUsuario *catUsr[MAX_TIPO_USUARIO]);
    Usuario(string cedula, string nombre, string apellido, string contraseña, CategoriaUsuario *catUsr[MAX_TIPO_USUARIO]);
   
    void setCedula(string cedula);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setContraseña(string contraseña);
    void setPrimeraContraseña(bool primeraContraseña);
    void setSexo(string sexo);
    void setFechaNacimiento(DTFecha fechaNacimiento);
    void setEdad(int edad);
    void setActivo(bool activo);
    void setActividadesUsr(list<Actividad *> *actividadesUsr);
    void setCatUsr(CategoriaUsuario *catUsr[2]);

    string getCedula();
    string getNombre();
    string getApellido();
    string getContraseña();
    bool getPrimeraContraseña();
    string getSexo();
    DTFecha& getFechaNacimiento();
    int getEdad();
    bool getActivo();
    list<Actividad *> *getActividadesUsr();
    CategoriaUsuario **getCatUsr();
    DTDatosUsuario& getDatosUsuario(); // lista
   
    void addVisibilityCatUsr();
    list<TipoUsuario> *listarTipoDeUsuario();
    bool contraValida(string contra);
    void addCatUsuario(CategoriaUsuario *cat); // lista
   
    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Actividad altaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
    void addActividad(Actividad actividad);
    set<DTReserva> *mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    bool esSocio();
    set<DTHistorial> *mostrarHistorialPorMedico();
    set<DTConsulta> *mostrarDatosConsulta(DTFecha fecha);
    void buscarConsulta(string idConsulta);

    ~Usuario();
};
#endif
