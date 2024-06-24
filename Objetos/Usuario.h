#ifndef USUARIO_H
#define USUARIO_H
#include "Administrativo.h"
#include "definiciones.h"
#include "DTDatosUsuario.h"
#include "DTConsulta.h"
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
    string contrasenia;
    bool primeraContrasenia;
    string sexo;
    DTFecha fechaNacimiento;
    int cantInasistencias;
    bool activo;
    list<Actividad *> *actividadesUsr;
    vector<CategoriaUsuario*> *catUsr;

public:
    Usuario(string ci, string nomb, string apell, string sex, const DTFecha fechNac, vector<CategoriaUsuario*> *catUsr);

    void setCedula(string cedula);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setContrasenia(string contrasenia);
    void setPrimeraContrasenia(bool primeraContrasenia);
    void setSexo(string sexo);
    void setFechaNacimiento(const DTFecha fechaNacimiento);
    void setCantInasistencias();
    void setActivo(bool activo);
    void setActividadesUsr(list<Actividad *> *actividadesUsr);
    void setCatUsr(vector<CategoriaUsuario*> *catUsr);

    string getCedula()const;
    string getNombre()const;
    string getApellido()const;
    string getContrasenia()const;
    bool getPrimeraContrasenia()const;
    string getSexo()const;
    DTFecha getFechaNacimiento()const;
    int getCantInasistencias();
    bool getActivo();
    list<Actividad *> *getActividadesUsr();
    vector<CategoriaUsuario*> *getCatUsr();
    DTDatosUsuario getDatosUsuario()const; // lista

    void addVisibilityCatUsr();
    vector<TipoUsuario> listarTipoDeUsuario()const;
    bool contraValida(string contra);
    void addCatUsuario(CategoriaUsuario *cat); // lista

    void registrarAsistencia(EstadoConsulta estC, string idConsulta);
    Emergencia altaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion);
    void addActividad(Comun actividad);
    void cancelarReserva(string idConsulta);
    bool esSocio();
    set<DTConsulta> *mostrarDatosConsulta(const DTFecha fecha);
    void buscarConsulta(string idConsulta);

    ~Usuario();
};
#endif
