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
    list<TipoUsuario> *tipoUsuario;
    bool activo;

public:
    DTDatosUsuario();
    DTDatosUsuario(string ci, string nombre, DTFecha fechaNacimiento, list<TipoUsuario> *tipoUsuario, bool activo);
    DTDatosUsuario(DTDatosUsuario &dtu);

    string getCi();
    string getNombre();
    DTFecha getFechaNacimiento();
    list<TipoUsuario> *getTipoUsuario();
    bool getActivo();

    void mostrarDatosUsuario();

    ~DTDatosUsuario();
};
#endif