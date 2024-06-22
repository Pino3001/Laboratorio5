#include "Usuario.h"
#include "definiciones.h"
#include "Emergencia.h"
#include "Comun.h"
#include "Socio.h"
#include "Medico.h"
#include "DTFecha.h"
#include <set>
#include <list>

// CONSTRUCTORES
/* Usuario ::Usuario()
{
     this->cedula = "0";
    this->nombre = "0";
    this->apellido = "0";
    this->contraseña = "0";
    this->primeraContraseña = true;
    this->sexo = "0";
    DTFecha fn = DTFecha();
    this->fechaNacimiento = fn;
    this->edad = 0;
    this->activo = false;
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr = actUsr;
    // Inicializa el array de CategoriaUsuario con NULL.
    CategoriaUsuario cat[MAX_TIPO_USUARIO] = new CategoriaUsuario[MAX_TIPO_USUARIO];

    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = NULL;
    }
} */
// Constructor de administrativo por defecto
Usuario ::Usuario(string cedula, string nombre, string apellido, string contraseña, list<CategoriaUsuario *> *catUsr)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contraseña = contraseña;
    this->primeraContraseña = false;
    this->sexo = "---";
    DTFecha fn;
    this->fechaNacimiento = fn;
    // this->edad = 0;
    this->activo = true;
    // Crear las categorias de usuario a las que pertenece el Usuario
    this->catUsr = catUsr;
    this->actividadesUsr = new list<Actividad *>;
}
Usuario ::Usuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, list<CategoriaUsuario *> *catUsr)
{
    this->cedula = ci;
    this->nombre = nomb;
    this->apellido = apell;
    this->contraseña = "0";
    this->primeraContraseña = true;
    this->sexo = sexo;
    this->fechaNacimiento = fechNac;
    // this->edad = 0;
    this->activo = true;
    // Crear las categorias de usuario a las que pertenece el Usuario
    this->catUsr = catUsr;
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr = actUsr;
}

// SETTERS
void Usuario::setCedula(string cedula)
{
    this->cedula = cedula;
}
void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Usuario::setApellido(string apellido)
{
    this->apellido = apellido;
}
void Usuario::setContraseña(string contraseña)
{
    this->contraseña = contraseña;
}
void Usuario::setPrimeraContraseña(bool primeraContraseña)
{
    this->primeraContraseña = primeraContraseña;
}
void Usuario::setSexo(string sexo)
{
    this->sexo = sexo;
}
void Usuario::setFechaNacimiento(const DTFecha fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}
void Usuario::setEdad(int edad)
{
    this->edad = edad;
}
void Usuario::setActivo(bool activo)
{
    this->activo = activo;
}
void Usuario::setActividadesUsr(list<Actividad *> *actividadesUsr)
{
    this->actividadesUsr = actividadesUsr;
}
void Usuario::setCatUsr(list<CategoriaUsuario *> *catUsr)
{
    this->catUsr = catUsr;
}

// GETTERS
string Usuario::getCedula()
{
    return this->cedula;
}
string Usuario::getNombre()
{
    return this->nombre;
}
string Usuario::getApellido()
{
    return this->apellido;
}
string Usuario::getContraseña()
{
    return this->contraseña;
}
bool Usuario::getPrimeraContraseña()
{
    return this->primeraContraseña;
}
string Usuario::getSexo()
{
    return this->sexo;
}
DTFecha Usuario::getFechaNacimiento()const
{
    return this->fechaNacimiento;
}
int Usuario::getEdad()
{
    return this->edad;
}
bool Usuario::getActivo()
{
    return this->activo;
}
list<Actividad *> *Usuario::getActividadesUsr()
{
    return this->actividadesUsr;
}
list<CategoriaUsuario *> *Usuario::getCatUsr()
{
    return this->catUsr;
}
DTDatosUsuario Usuario::getDatosUsuario() const// Da un datatype con los datos del Usuario.
{
    DTFecha fechaNacimiento = this->getFechaNacimiento();
    list<TipoUsuario> pa;
    DTDatosUsuario dtu(this->cedula, this->nombre, fechaNacimiento,pa, this->activo);
    return dtu;
}

// Setea el usuario a CategoriaUsuario para que exista la doble navegabilidad
void Usuario ::addVisibilityCatUsr()
{
    for (CategoriaUsuario *c : *this->catUsr)
    {
        c->setUsuarioVinculado(this);
    }
}
// Devielve un array con las categorias de usuario a las que pertenece el Usuario
list<TipoUsuario> Usuario ::listarTipoDeUsuario() const
{
    list<TipoUsuario> tipos;
    for (CategoriaUsuario *c : *this->catUsr)
    {
        if (c != nullptr)
        {
            // Casteo para ver que tipo de socio esta intentando hacer un ingreso.
            if (dynamic_cast<Administrativo *>(c))
            {
                tipos.push_back(TipoUsuario::Tipo_Administrativo);
            }
            else if (dynamic_cast<Socio *>(c))
            {
                tipos.push_back(TipoUsuario::Tipo_Socio);
            }
            else if (dynamic_cast<Medico *>(c))
            {
                tipos.push_back(TipoUsuario::Tipo_Medico);
            }
            else
            {
                tipos.push_back(TipoUsuario::UNKNOWN);
            }
        }
        else
        {
            tipos.push_back(TipoUsuario::UNKNOWN);
        }
    }
    return tipos;
}
// Verificar la contraseña.
bool Usuario ::contraValida(string contra)
{

    if (this->contraseña == contra)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Agregar una categoria mas al usuario, agrega categorias repetidas
void Usuario ::addCatUsuario(CategoriaUsuario *cat)
{
    this->catUsr->push_back(cat);
}

// paraimplementar

void Usuario ::registrarAsistencia(EstadoConsulta estC, string idConsulta) {}
Emergencia Usuario ::altaConsultaEmergencia(const DTFecha fecha, const DTHora hora, string descripcion) {}
void Usuario ::addActividad(Comun actividad) {}
set<DTReserva> *Usuario ::mostrarReservasActivas() {}
void Usuario ::cancelarReserva(string idConsulta) {}
bool Usuario ::esSocio() {}
set<DTHistorial> *Usuario ::mostrarHistorialPorMedico() {}
set<DTConsulta> *Usuario ::mostrarDatosConsulta(const DTFecha fecha) {}
void Usuario ::buscarConsulta(string idConsulta) {}

Usuario ::~Usuario() {}