#include "DTDatosUsuario.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "iostream"
#include <iomanip> // Para std::setw y std::setfill
using namespace std;

DTDatosUsuario ::DTDatosUsuario()
{
    this->ci = "0";
    this->nombre = "0";
    DTFecha fecha;
    this->fechaNacimiento = fecha;
    this->tipoUsuario;
    this->activo = true;
}
DTDatosUsuario ::DTDatosUsuario(string ci, string nombre, const DTFecha fechaNacimiento, list<TipoUsuario> tipo_Usuario, bool activo)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    this->tipoUsuario = tipo_Usuario;
    this->activo = activo;
}
 DTDatosUsuario ::DTDatosUsuario(const DTDatosUsuario &dtu)
        : ci(dtu.ci), nombre(dtu.nombre), fechaNacimiento(dtu.fechaNacimiento), tipoUsuario(dtu.tipoUsuario) {}

string DTDatosUsuario ::getCi()const
{
    return this->ci;
}
string DTDatosUsuario ::getNombre()const
{
    return this->nombre;
}
DTFecha DTDatosUsuario ::getFechaNacimiento() const
{
    return this->fechaNacimiento;
}
list<TipoUsuario> DTDatosUsuario ::getTipoUsuario()const
{
    return this->tipoUsuario;
}
bool DTDatosUsuario ::getActivo()const
{
    return this->activo;
}

void DTDatosUsuario ::mostrarDatosUsuario()
{
    cout << "\n";
    cout << setw(40) << setfill('_') << "\n";
    cout << "\t  C.I: " << this->ci << "\n";
    cout << "\t  Nombre Usuario: " << this->nombre << "\n";
    cout << "\t  Fecha de Nacimiento: " << this->fechaNacimiento.getAnio() << ":" << this->fechaNacimiento.getMes() << ":" << this->fechaNacimiento.getDia() << "\n";
    cout << "\t  Tipo de Usuario : ";
    for (TipoUsuario t : this->tipoUsuario)
    {
        if (t == TipoUsuario::Tipo_Socio)
        {
            cout << "-Socio- ";
        }
        else if (t == TipoUsuario::Tipo_Medico)
        {
            cout << "-Medico- ";
        }
        else if (t == TipoUsuario::Tipo_Administrativo)
        {
            cout << "-Administrativo- ";
        }
        else if (t == TipoUsuario::Administrativo_defecto)
        {
            cout << "-Administrativo por defecto- ";
        }
    }
    cout << "\n";
    cout << "\t  Activo: ";
    if (this->activo)
    {
        cout << "SI" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
    cout << setw(40) << setfill('_') << "\n";
}
DTDatosUsuario ::~DTDatosUsuario() {}