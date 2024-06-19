#include "Usuario.h"
#include "definiciones.h"
#include "Socio.h"
#include "Medico.h"
#include "DTFecha.h"

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
Usuario ::Usuario(string cedula, string nombre, string apellido, string contraseña, CategoriaUsuario *catUsr[MAX_TIPO_USUARIO])
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
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = catUsr[i];
    }
    this->actividadesUsr = new list<Actividad *>;
}

Usuario ::Usuario(string ci, string nomb, string apell, string sexo, DTFecha fechNac, CategoriaUsuario *catU[MAX_TIPO_USUARIO])
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
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = catU[i];
    }
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr = actUsr;
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
void Usuario::setActividadesUsr(list<Actividad *> *actividadesUsr) { this->actividadesUsr = actividadesUsr; }
void Usuario::setCatUsr(CategoriaUsuario *catUsr[MAX_TIPO_USUARIO])
{
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = catUsr[i];
    }
}

// GETTERS
string Usuario::getNombre() { return this->nombre; }
string Usuario::getApellido() { return this->apellido; }
string Usuario::getContraseña() { return this->contraseña; }
bool Usuario::getPrimeraContraseña() { return this->primeraContraseña; }
string Usuario::getSexo() { return this->sexo; }
DTFecha& Usuario::getFechaNacimiento()
{
    return this->fechaNacimiento;
}
int Usuario::getEdad()
{
    return this->edad;
}
bool Usuario::getActivo() { return this->activo; }

list<Actividad *> *Usuario::getActividadesUsr() { return this->actividadesUsr; }
CategoriaUsuario **Usuario::getCatUsr() { return this->catUsr; }

// Setea el usuario a CategoriaUsuario para que exista la doble navegabilidad
void Usuario ::addVisibilityCatUsr()
{
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (this->catUsr[i] != nullptr)
        {
            this->catUsr[i]->setUsuarioVinculado(this);
        }
    }
}
// Devielve un array con las categorias de usuario a las que pertenece el Usuario
TipoUsuario *Usuario ::listarTipoDeUsuario()
{
    TipoUsuario arrayTipo[MAX_TIPO_USUARIO];
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (this->catUsr[i] != nullptr)
        {
            // Casteo para ver que tipo de socio esta intentando hacer un ingreso.
            if (dynamic_cast<Administrativo *>(catUsr[i]))
            {
                arrayTipo[i] = TipoUsuario::Tipo_Administrativo;
            }
            else if (dynamic_cast<Socio *>(catUsr[i]))
            {
                arrayTipo[i] = TipoUsuario::Tipo_Socio;
            }
            else if (dynamic_cast<Medico *>(catUsr[i]))
            {
                arrayTipo[i] = TipoUsuario::Tipo_Medico;
            }
            else
            {
                arrayTipo[i] = TipoUsuario::UNKNOWN;
            }
        }
        else
        {
            arrayTipo[i] = TipoUsuario::UNKNOWN;
        }
    }
    return arrayTipo;
}
// Dat un datatype con los datos del Usuario.
DTDatosUsuario Usuario::getDatosUsuario()
{
    DTFecha& fechaNacimiento = this->getFechaNacimiento();
    DTDatosUsuario dtu(this->getCedula(), this->getNombre(), this->getFechaNacimiento(), this->listarTipoDeUsuario(), this->getActivo());
    return dtu;
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
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (this->getCatUsr()[i] == NULL)
        {
            this->getCatUsr()[i] = cat;
            break;
        }
    }
}

void registrarAsistencia(EstadoConsulta estC, string idConsulta) {}
// paraimplementar

/*

Actividad altaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
void addActividad(Actividad actividad);
set(DTReserva) mostrarReservasActivas();
void cancelarReserva(string idConsulta);
bool esSocio();
set(DTHistorial) mostrarHistorialPorMedico();
set(DTConsulta) mostrarDatosConsulta(DTFecha fecha);
void buscarConsulta(string idConsulta);

~Usuario(){} */