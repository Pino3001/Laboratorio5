#include "Usuario.h"

#include "CategoriaUsuario.h"
#include "Socio.h"
#include "Medico.h"
// #include "Administrativo.h"
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
    this->fechaNacimiento = fn;
    this->edad = 0;
    this->activo = false;
    //Inicializa los tipos de usuario en none
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsr[i] = none;
    }
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr = actUsr;
    //Inicializa el array de CategoriaUsuario con NULL.
        for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = NULL;
    }
}

Usuario ::Usuario(string ci, string nomb, string apell, string sexo, DTFecha fechNac, TipoUsuario tUsr[2], CategoriaUsuario *catUsr[MAX_TIPO_USUARIO])
{
    this->cedula = ci;
    this->nombre = nomb;
    this->apellido = apell;
    this->contraseña = "0";
    this->primeraContraseña = true;
    this->sexo = sexo;
    this->fechaNacimiento = fechNac;
    // this->edad = 0;
    this->activo = false;
    // Setear el arreglo de tipo de usuarios
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsr[i] = tUsr[i];
    }
    // Crear las categorias de usuario a las que pertenece el Usuario
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] = catUsr[i];
    }
    list<Actividad *> *actUsr = new list<Actividad *>;
    this->actividadesUsr = actUsr;
}

Usuario::Usuario(Usuario &usr)
{
    this->cedula = usr.getCedula();
    this->nombre = usr.getNombre();
    this->apellido = usr.getApellido();
    this->contraseña = usr.getContraseña();
    this->primeraContraseña = usr.getPrimeraContraseña();
    this->sexo = usr.getSexo();
    this->fechaNacimiento = usr.getFechaNacimiento();
    this->edad = usr.getEdad();
    this->activo = usr.getActivo();
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsr[i] = usr.getTipoUsr()[i];
    }
    CategoriaUsuario ** cu =  usr.getCatUsr();
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->catUsr[i] =cu[i];
    }
    this->actividadesUsr = usr.getActividadesUsr();
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
CategoriaUsuario** Usuario::getCatUsr() { return this->catUsr; }

//Dat un datatype con los datos del Usuario.
DTDatosUsuario Usuario::getDatosUsuario()
{
    DTDatosUsuario dtu = DTDatosUsuario(this->getCedula(), this->getNombre(), this->getFechaNacimiento(), this->getTipoUsr, this->getActivo());
    return dtu;
}
//Verificar la contraseña.
bool Usuario ::contraValida(string contra){
    
    if (this->contraseña == contra)
    {
        return true;
    }else{
        return false;
    }
    
}

//Agregar una categoria mas al usuario, agrega categorias repetidas
void Usuario ::addCatUsuario(CategoriaUsuario *cat){
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (this->getCatUsr()[i] == NULL)
        {
            this->getCatUsr()[i] = cat;
            break;
        }
        
    }
    
}
// paraimplementar

/* 
void registrarAsistencia(EstadoConsulta estC);
Actividad altaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
void addActividad(Actividad actividad);
set(DTReserva) mostrarReservasActivas();
void cancelarReserva(string idConsulta);
bool esSocio();
set(DTHistorial) mostrarHistorialPorMedico();
set(DTConsulta) mostrarDatosConsulta(DTFecha fecha);
void buscarConsulta(string idConsulta);

~Usuario(){} */