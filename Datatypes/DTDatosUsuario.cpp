#include "DTDatosUsuario.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "iostream"
#include <iomanip> // Para std::setw y std::setfill
using namespace std;

DTDatosUsuario::DTDatosUsuario()
    : ci("0"), nombre("0"), apellido(""), fechaNacimiento(), cantidadInasistencias(0), tipoUsuario(), activo(true) {}

DTDatosUsuario::DTDatosUsuario(string ci, string nombre, string apellido, const DTFecha fechaNacimiento, int cantInasistencias, vector<TipoUsuario> tipoUsuario, bool activo)
    : ci(ci), nombre(nombre), apellido(apellido), fechaNacimiento(fechaNacimiento), cantidadInasistencias(cantInasistencias), tipoUsuario(tipoUsuario), activo(activo) {}

DTDatosUsuario::DTDatosUsuario(string ci, string nombre, string apellido) : ci(ci), nombre(nombre), apellido(apellido)
{
    DTFecha f;
    this->fechaNacimiento = f;
    this->cantidadInasistencias = 0;
    this->activo = true;
}

/* DTDatosUsuario::DTDatosUsuario(const DTDatosUsuario &dtu)
    : ci(dtu.ci), nombre(dtu.nombre), apellido(dtu.apellido), fechaNacimiento(dtu.fechaNacimiento), cantidadInasistencias(dtu.getCantidadInasistencias()), tipoUsuario(dtu.tipoUsuario), activo(dtu.activo) {}
 */
string DTDatosUsuario::getCi() const
{
    return this->ci;
}

string DTDatosUsuario::getNombre() const
{
    return this->nombre;
}

string DTDatosUsuario::getApellido() const
{
    return this->apellido;
}

DTFecha DTDatosUsuario::getFechaNacimiento() const
{
    return this->fechaNacimiento;
}

int DTDatosUsuario::getCantidadInasistencias()const
{
        return this->cantidadInasistencias;
}

vector<TipoUsuario> DTDatosUsuario::getTipoUsuario() const
{
    return this->tipoUsuario;
}

bool DTDatosUsuario::getActivo() const
{
    return this->activo;
}

void DTDatosUsuario::mostrarDatosUsuario() const
{
    cout << "\n";
    cout << setw(40) << setfill('_') << "\n\n";
    cout << "  C.I: " << this->ci << "\n";
    cout << "  Nombre : " << this->nombre << "\n";
    cout << "  Apellido : " << this->apellido << "\n";
    cout << "  Fecha de Nacimiento: ";
    this->fechaNacimiento.imprimirDTFecha();
    cout << "\n";
    cout << "  Tipo de Usuario : ";
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
    cout << "\t  Cantidad de inasistencias a Consultas: " << this->cantidadInasistencias << "\n";
    cout << "\t  Activo: " << (this->activo ? "SI" : "NO") << "\n";
    cout << setw(40) << setfill('_') << "\n";
}

DTDatosUsuario::~DTDatosUsuario() {}
