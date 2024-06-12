#include "Usuario.h"

#include "CategoriaUsuario.h"
#include "Socio.h"
#include "Medico.h"
//#include "Administrativo.h"
#include "DTDatosUsuario.h"
#include <list>
#include <string>

// CONSTRUCTORES
Usuario ::Usuario()
{
    this->cedula = "0";
    this->nombre = "0";
    this->apellido = "0";
    this->contraseña = "0";
    this->primeraContraseña = true;
    this->sexo = "0";
    DTFecha fn();
    this->fechaNacimiento = fd;
    this->edad = 0;
    this->activo = false;
    TipoUsuario tu[2] = new TipoUsuario[2];
    this->tipoUsr * = tu;
    for (size i = 0; i < 2; i++)
    {
        tu[i] = none;
    }
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr * = actUsr;
    // array de CategoriaUsuario
}

Usuario ::Usuario(string ci, string nomb, string apell, string sex, DTFecha fechNac, TipoUsuario tUsr[2])
{
    this->cedula = ci;
    this->nombre = nomb;
    this->apellido = apell;
    this->contraseña = "0";
    this->primeraContraseña = true;
    this->sexo = sex;
    this->fechaNacimiento = fechNac;
    // this->edad = 0;
    this->activo = false;
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsr[i] = tUsr[i];
    }
    CategoriaUsuario *cu = new *CategoriaUsuario[2];
    this->catUsr * = *cu;
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (tipoUsr[i] == Socio)
        {
            Socio *s = new Socio(this);
            this->catUsr[i] = s;
        }
        else if (tipoUsr[i] == Medico)
        {
            Medico *m = new Medico(this);
            this->catUsr[i] = m;
        }
        else if (tipoUsr[i] == Administrativo)
        {
            Administrativo *a = new Administrativo(this);
            this->catUsr[i] = *a;
        }
    }
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr * = actUsr;
}

Usuario::Usuario(Usuario &usr)
{
    this->nombre = usr.getNombre();
    this->apellido = usr.getApellido();
    this->contraseña = usr.getContraseña();
    this->primeraContraseña = usr.getPrimeraContraseña();
    this->sexo = usr.getSexo();
    this->fechaNacimiento = usr.getFechaNacimiento();
    this->edad = usr.getEdad();
    this->activo = usr.getActivo();
    this->tipoUsr[0] = usr.getTipoUsr()[0];
    this->tipoUsr[1] = usr.getTipoUsr()[1];
    this->actividadesUsr = usr.getActividadesUsr();
    this->catUsr[0] = usr.getCatUsr()[0];
    this->catUsr[1] = usr.getCatUsr()[1];
}

// SETTERS
void Usuario::setNombre(string nombre) { this->nombre = nombre; }
void Usuario::setApellido(string apellido) { this->apellido = apellido; }
void Usuario::setContraseña(string contraseña) { this->contraseña = contraseña; }
void Usuario::setPrimeraContraseña(bool primeraContraseña) { this->primeraContraseña = primeraContraseña; }
void Usuario::setSexo(string sexo) { this->sexo = sexo; }
void Usuario::setFechaNacimiento(DTFecha fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }
void Usuario::setEdad(int edad) { this->edad = edad; }
void Usuario::setActivo(bool activo) { this->activo = activo; }
void Usuario::setTipoUsr(TipoUsuario *tipoUsr[2])
{
    this->tipoUsr[0] = tipoUsr[0];
    this->tipoUsr[1] = tipoUsr[1];
}
void Usuario::setActividadesUsr(list<Actividad *> *actividadesUsr) { this->actividadesUsr = actividadesUsr; }
void Usuario::setCatUsr(CategoriaUsuario *catUsr1, CategoriaUsuario *catUsr2)
{
    this->catUsr[0] = catUsr1;
    this->catUsr[1] = catUsr2;
}

// GETTERS
string Usuario::getNombre() { return this->nombre; }
string Usuario::getApellido() { return this->apellido; }
string Usuario::getContraseña() { return this->contraseña; }
bool Usuario::getPrimeraContraseña() { return this->primeraContraseña; }
string Usuario::getSexo() { return this->sexo; }
DTFecha Usuario::getFechaNacimiento() { return this->fechaNacimiento; }
int Usuario::getEdad() { return this->edad; }
bool Usuario::getActivo() { return this->activo; }
TipoUsuario[*] Usuario::getTipoUsr() { return this->tipoUsr; }
list<Actividad *> *Usuario::getActividadesUsr() { return this->actividadesUsr; }
CategoriaUsuario[*] Usuario::getCatUsr() { return this->catUsr; }

DTDatosUsuario Usuario:: getDatosUsuario()
{
    DTDatosUsuario dtu = DTDatosUsuario(this->getCedula(), this->getNombre(), this->getFechaNacimiento(), this->getTipoUsr, this->getActivo());
    return dtu;
}

// paraimplementar

/* bool contraValida(string contra);
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

~Usuario(){} */