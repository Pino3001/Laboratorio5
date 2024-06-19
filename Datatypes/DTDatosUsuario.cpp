#include "DTDatosUsuario.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "iostream"
using namespace std;

DTDatosUsuario ::DTDatosUsuario()
{
    this->ci = "0";
    this->nombre = "0";
    DTFecha fecha;
    this->fechaNacimiento = fecha;
    this->tipoUsuario = new list<TipoUsuario>;
    this->activo = true;
}

DTDatosUsuario ::DTDatosUsuario(string ci, string nombre, DTFecha fechaNacimiento, list<TipoUsuario> *tipo_Usuario, bool activo)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    this->tipoUsuario = tipo_Usuario;
    this->activo = activo;
}
DTDatosUsuario ::DTDatosUsuario(DTDatosUsuario &dtu)
{
    this->ci = dtu.getCi();
    this->nombre = dtu.getNombre();
    this->fechaNacimiento = dtu.getFechaNacimiento();
    for (TipoUsuario d : *dtu.getTipoUsuario())
    {
        this->tipoUsuario->push_back(d);
    }
    
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsuario[i] = dtu.getTipoUsuario()[i];
    }
    this->activo = dtu.getActivo();
}

string DTDatosUsuario ::getCi() { return this->ci; }
string DTDatosUsuario ::getNombre() { return this->nombre; }
DTFecha DTDatosUsuario ::getFechaNacimiento() { return this->fechaNacimiento; }
list<TipoUsuario> *DTDatosUsuario ::getTipoUsuario() { return this->tipoUsuario; }
bool DTDatosUsuario ::getActivo() { return this->activo; }

void DTDatosUsuario ::mostrarDatosUsuario()
{
    cout << "\n";
    cout << "\t ______________________________________\n";
    cout << "\t  C.I: " << this->ci << "\n";
    cout << "\t  Nombre Usuario: " << this->nombre << "\n";
    cout << "\t  Fecha de Nacimiento: " << this->fechaNacimiento.getAnio() << ":" << this->fechaNacimiento.getMes() << ":" << this->fechaNacimiento.getDia() << "\n";
    cout << "\t  Tipo de Usuario : " << "\n";
/*     for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        if (this->tipoUsuario[i] == Tipo_Socio)
        {
            cout << "-Socio- ";
        }
        else if (this->tipoUsuario[i] == Tipo_Medico)
        {
            cout << "-Medico- ";
        }
        else if (this->tipoUsuario[i] == Tipo_Administrativo)
        {
            cout << "-Administrativo- ";
        }
        else if (this->tipoUsuario[i] == Administrativo_defecto)
        {
            cout << "-Administrativo por defecto- ";
        }
    } */
    cout << "\n";
    cout << "\t  Activo: ";
    if (this->activo)
    {
        cout << "SI" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    cout << "\t ______________________________________\n";
}
DTDatosUsuario ::~DTDatosUsuario() {}