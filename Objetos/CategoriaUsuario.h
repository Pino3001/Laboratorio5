#ifndef CATEGORIAUSUARIO_H
#define CATEGORIAUSUARIO_H
#include <string>
class Usuario;

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

    virtual ~CategoriaUsuario()=0;
};
#endif
