#ifndef CATEGORIAUSUARIO_H
#define CATEGORIAUSUARIO_H
#include <string>
class Actividad;
class Consulta;
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

    void addActividad(Actividad actividad);
    virtual string verNombre() = 0;
    virtual string verCi()=0;
    virtual Actividad *buscarConsulta(string idConsulta)=0;

    ~CategoriaUsuario();
};
#endif