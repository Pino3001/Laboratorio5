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
Usuario ::Usuario(string ci, string nomb, string apell, string sexo, const DTFecha fechNac, vector<CategoriaUsuario *> *catUsr)
{
    this->cedula = ci;
    this->nombre = nomb;
    this->apellido = apell;
    this->contrasenia = "0";
    this->primeraContrasenia = true;
    this->sexo = sexo;
    this->fechaNacimiento = fechNac;
    this->cantInasistencias = 0;
    this->activo = true;
    // Crear las categorias de usuario a las que pertenece el Usuario
    this->catUsr = catUsr;
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
void Usuario::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}
void Usuario::setPrimeraContrasenia(bool primeraContrasenia)
{
    this->primeraContrasenia = primeraContrasenia;
}
void Usuario::setSexo(string sexo)
{
    this->sexo = sexo;
}
void Usuario::setFechaNacimiento(const DTFecha fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}
void Usuario::setCantInasistencias()
{
    this->cantInasistencias ++;
}
void Usuario::setActivo(bool activo)
{
    this->activo = activo;
}
void Usuario::setActividadesUsr(list<Actividad *> *actividadesUsr)
{
    this->actividadesUsr = actividadesUsr;
}
void Usuario::setCatUsr(vector<CategoriaUsuario *> *catUsr)
{
    this->catUsr = catUsr;
}

// GETTERS
string Usuario::getCedula() const
{
    return this->cedula;
}
string Usuario::getNombre() const
{
    return this->nombre;
}
string Usuario::getApellido() const
{
    return this->apellido;
}
string Usuario::getContrasenia() const
{
    return this->contrasenia;
}
bool Usuario::getPrimeraContrasenia() const
{
    return this->primeraContrasenia;
}
string Usuario::getSexo()const
{
    return this->sexo;
}
DTFecha Usuario::getFechaNacimiento() const
{
    return this->fechaNacimiento;
}
int Usuario::getCantInasistencias()
{
    return this->cantInasistencias;
}
bool Usuario::getActivo()
{
    return this->activo;
}
list<Actividad *> *Usuario::getActividadesUsr()
{
    return this->actividadesUsr;
}
vector<CategoriaUsuario *> *Usuario::getCatUsr()
{
    return this->catUsr;
}
DTDatosUsuario Usuario::getDatosUsuario() const // Da un datatype con los datos del Usuario.
{
    DTDatosUsuario dtu(this->cedula, this->nombre, this->apellido, this->fechaNacimiento, this->cantInasistencias, this->listarTipoDeUsuario(), this->activo);
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
vector<TipoUsuario> Usuario ::listarTipoDeUsuario() const
{
    vector<TipoUsuario> tipos;
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

    if (this->contrasenia == contra)
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
Usuario ::~Usuario() {}
