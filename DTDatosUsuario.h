#ifndef DTDATOSUSUARIO_H
#define DTDATOSUSUARIO_H

#include <string>
using namespace std;

class DTDatosUsuario
{
private:
    string ci;
    string nombre;
    DTFecha fechaNacimiento;
    TipoUsuario tipoUsuario[2];
    bool activo;

public:
    DTDatosUsuario();
    DTDatosUsuario(string ci, string nombre, DTFecha fechaNacimiento, TipoUsuario tipoUsuario[2], bool activo);
    DTDatosUsuario(DTDatosUsuario &dtu);

    string getCi();
    string getNombre();
    DTFecha getFechaNacimiento();
    TipoUsuario *getTipoUsuario();
    bool getActivo();

    void mostrarDatosUsuario();

    ~DTDatosUsuario();
};
#endif