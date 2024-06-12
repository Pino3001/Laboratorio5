#include "CategoriaUsuario.h"
#include "Usuario.h"
#include "Actividad.h"

#include <string>

using namespace std;

//Constructores
CategoriaUsuario ::CategoriaUsuario(Usuario *usr)
{
    this->usuarioVinculado = usr;
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
void addActividad(Actividad actividad);
string verNombre();
string verCi();
Consulta buscarConsulta(string idConsulta);

~CategoriaUsuario(); 