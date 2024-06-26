#include "CategoriaUsuario.h"
#include "Usuario.h"
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
CategoriaUsuario::~CategoriaUsuario() {}
