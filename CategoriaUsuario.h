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
    CategoriaUsuario(Usuario *usr);
    CategoriaUsuario(CategoriaUsuario &catUsr);
    
    void setUsuarioVinculado(Usuario *usr);

    Usuario* getUsuarioVinculado();

    void addActividad(Actividad actividad);
    string verNombre();
    string verCi();
    virtual TipoUsuario obtenertipo()=0;
    Consulta buscarConsulta(string idConsulta);

    ~CategoriaUsuario();
};
#endif