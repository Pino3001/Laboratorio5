#ifndef CATEGORIAUSUARIO_H
#define CATEGORIAUSUARIO_H

#include "Usuario.h"
#include "Actividad.h"
#include "Consulta.h"

#include <string>

using namespace std;

class CategoriaUsuario
{
protected:
    Usuario *usuarioVinculado;
public:
    CategoriaUsuario();
    CategoriaUsuario(CategoriaUsuario &catUsr);
    
    void setUsuarioVinculado(Usuario *usr);

    Usuario* getUsuarioVinculado();

    void addActividad(Actividad actividad);
    virtual string verNombre() = 0;
    string verCi();
    Consulta buscarConsulta(string idConsulta);

    ~CategoriaUsuario();
};
#endif