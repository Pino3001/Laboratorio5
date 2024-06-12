#include "DTDatosUsuario.h"

#include <string>
using namespace std;

DTDatosUsuario ::DTDatosUsuario()
{
    this->ci = "0";
    this->nombre = "0";
    DTFecha fecha = DTFecha();
    this->fechaNacimiento = fecha;
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsuario[i] = none;
    }
    this->activo = true;
}

DTDatosUsuario ::DTDatosUsuario(string ci, string nombre, DTFecha fechaNacimiento, TipoUsuario tipo_Usuario[2], bool activo)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsuario[i] = tipo_Usuario[i];
    }
    this->activo = activo;
}
DTDatosUsuario ::DTDatosUsuario(DTDatosUsuario &dtu)
{
    this->ci = dtu.getCi();
    this->nombre = dtu.getNombre();
    this->fechaNacimiento = dtu.getFechaNacimiento();
    for (int i = 0; i < MAX_TIPO_USUARIO; i++)
    {
        this->tipoUsuario[i] = dtu.getTipoUsuario()[i];
    }
    this->activo = dtu.getActivo();
}

string DTDatosUsuario ::getCi() { return this->ci; }
string DTDatosUsuario ::getNombre() { return this->nombre; }
DTFecha DTDatosUsuario ::getFechaNacimiento() { return this->fechaNacimiento; }
TipoUsuario **DTDatosUsuario ::getTipoUsuario() { return this->tipoUsuario; }
bool DTDatosUsuario ::getActivo() { return this->activo; }

void DTDatosUsuario ::mostrarDatosUsuario()
{
}
DTDatosUsuario ::~DTDatosUsuario() {}