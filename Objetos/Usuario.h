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
class Comun;
class Emergencia;
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
    list<CategoriaUsuario*> *catUsr;

public:
    Usuario(string ci, string nomb, string apell, string sex, const DTFecha fechNac, list<CategoriaUsuario*> *catUsr);
    Usuario(string cedula, string nombre, string apellido, string contraseña, list<CategoriaUsuario*> *catUsr);
   
    void setCedula(string cedula);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setContraseña(string contraseña);
    void setPrimeraContraseña(bool primeraContraseña);
    void setSexo(string sexo);
    void setFechaNacimiento(const DTFecha fechaNacimiento);
    void setEdad(int edad);
    void setActivo(bool activo);
    void setActividadesUsr(list<Actividad *> *actividadesUsr);
    void setCatUsr(list<CategoriaUsuario*> *catUsr);

    string getCedula();
    string getNombre();
    string getApellido();
    string getContraseña();
    bool getPrimeraContraseña();
    string getSexo();
    DTFecha getFechaNacimiento()const;
    int getEdad();
    bool getActivo();
    list<Actividad *> *getActividadesUsr();
    list<CategoriaUsuario*> *getCatUsr();
    DTDatosUsuario getDatosUsuario()const; // lista
   
    void addVisibilityCatUsr();
    list<TipoUsuario> listarTipoDeUsuario()const;
    bool contraValida(string contra);
    void addCatUsuario(CategoriaUsuario *cat); // lista
   
    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Emergencia altaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion);
    void addActividad(Comun actividad);
    set<DTReserva> *mostrarReservasActivas();
    void cancelarReserva(string idConsulta);
    bool esSocio();
    set<DTHistorial> *mostrarHistorialPorMedico();
    set<DTConsulta> *mostrarDatosConsulta(const DTFecha fecha);
    void buscarConsulta(string idConsulta);

    ~Usuario();
};
#endif
