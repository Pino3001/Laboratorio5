#ifndef DTDATOSUSUARIO_H
#define DTDATOSUSUARIO_H

#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include <vector>
using namespace std;

class DTDatosUsuario
{
private:
    string ci;
    string nombre;
    string apellido;
    DTFecha fechaNacimiento;
    int cantidadInasistencias;
    vector<TipoUsuario> tipoUsuario;
    bool activo;

public:
    DTDatosUsuario();
    DTDatosUsuario(string ci, string nombre, string apellido, const DTFecha fechaNacimiento, int cantInasistencias, vector<TipoUsuario> tipoUsuario, bool activo);
    DTDatosUsuario(string ci, string nombre, string apellido);
    //DTDatosUsuario(const DTDatosUsuario &dtu);

    string getCi() const;
    string getNombre() const;
    string getApellido() const;
    DTFecha getFechaNacimiento() const;
    int getCantidadInasistencias() const;
    vector<TipoUsuario> getTipoUsuario() const;
    bool getActivo() const;

    void mostrarDatosUsuario() const;

    ~DTDatosUsuario();
};

#endif
