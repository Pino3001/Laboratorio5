#ifndef DTDATOSUSUARIO_H
#define DTDATOSUSUARIO_H
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include <list>
using namespace std;

class DTDatosUsuario
{
private:
    string ci;
    string nombre;
    DTFecha fechaNacimiento;
    list<TipoUsuario> tipoUsuario;
    bool activo;

public:
    DTDatosUsuario();
    DTDatosUsuario(string ci, string nombre, const DTFecha fechaNacimiento, list<TipoUsuario> tipoUsuario, bool activo);
    DTDatosUsuario(const DTDatosUsuario &dtu);

    string getCi()const;
    string getNombre()const;
    DTFecha getFechaNacimiento()const;
    list<TipoUsuario> getTipoUsuario()const;
    bool getActivo()const;

    void mostrarDatosUsuario();

    ~DTDatosUsuario();
};
#endif