#include "CategoriaUsuario.h"
#include "Usuario.h"
#include "Actividad.h"
#include "Consulta.h"
#include <string>

using namespace std;

//Constructores
CategoriaUsuario ::CategoriaUsuario()
{
    this->usuarioVinculado = nullptr;
}
CategoriaUsuario ::CategoriaUsuario(CategoriaUsuario &catUsr)
{
    this->usuarioVinculado = catUsr.getUsuarioVinculado();
}

//Setters
void CategoriaUsuario ::setUsuarioVinculado(Usuario *usr)
{
    this->usuarioVinculado = usr;
}

//Getters
Usuario *CategoriaUsuario ::getUsuarioVinculado()
{
    return this->usuarioVinculado;
}

 //Para implementar
/* void CategoriaUsuario ::addActividad(Actividad actividad){} */

CategoriaUsuario ::~CategoriaUsuario(){}

