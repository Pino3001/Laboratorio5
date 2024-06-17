#include "Fabrica.h"
#include "IUsuario.h"
#include "IRegistroMedico.h"
#include "definiciones.h"
#include <string>
#include "iostream"
using namespace std;

int main()
{
    string nombre, cedula, apellido, contraseña;
    bool salir = false;

    Fabrica *f = Fabrica::getInstancia();
    IUsuario *usuarios = f->getIUsuario();
    IRegistroMedico *medicos = f->getIRegistroMedico();

    cout << "\t\t Iniciando el sistema...";
    cout << "\n\t Ingrese un administrativo por defecto para el sistema.";
    cout << "\n Nombre: ";
    cin >> nombre;
    cout << "\n Apellido: ";
    cin >> apellido;
    cout << "\n C.I: ";
    cin >> cedula;
    cout << "\n Contraseña: ";
    cin >> contraseña;

    usuarios->crearAdminDefecto(nombre, cedula, apellido, contraseña);

    do
    {
        int opt;

        cout << "\n\t\t Mutualista Grupo 5";
        cout << "\n\t [1] - Iniciar secion.";
        cout << "\n\t [2] - Salir.";
        cout << "\n opt >> ";
        cin >> opt;
        if (opt == 1)
        {
            string ci, contra;
            bool exist, valida, sesionActiva;
            cout << "\n\t\t -Iniciar sesion-";
            cout << "\n\t Para iniciar sesion ingrese su cedula y contraseña:";
            cout << "\n Cedula: ";
            cin >> ci;
            exist = usuarios->existeUsuario(ci);
            if (exist)
            {
                cout << "\n Contraseña: ";
                cin >> contra;
                valida = usuarios->verificarContraseña(ci, contra);
                if (valida)
                {
                    sesionActiva = usuarios->asignarSesion(ci);
                }
                else
                {
                    cout << "\n\t\t Contraseña no valida!";
                }
            }
            else
            {
                cout << "\n\t\t No existe el usuario en el sistema!";
            }
            bool socio = false, medico = false, administrativo = false;
            TipoUsuario *tu;
            tu = usuarios->tipoDeUsuario(ci);
            for (int i = 0; i < MAX_TIPO_USUARIO; i++)
            {
                if (tu[i] == Tipo_Administrativo)
                {
                    administrativo = true;
                }
                else if (tu[i] == Tipo_Socio)
                {
                    socio = true;
                }
                else if (tu[i] == Tipo_Medico)
                {
                    medico = true;
                }
            }
            while (sesionActiva)
            {
                if (administrativo && !socio && !medico)
                { // Solo Administrativo
                    /* code de administrativo*/
                }
                else if (administrativo && socio && !medico)
                { // Administrativo y socio
                    int optAux;
                    cout << "\n\t\t -Mustualista Grupo 5-";
                    cout << "\n\t Elija el con el tipo de usuario que desea ingresar:";
                    cout << "\n [1] - Administrativo.";
                    cout << "\n [2] - Socio.";
                    cout << "\n Opcion >> ";
                    cin >> optAux;
                    if (optAux == 1)
                    { // Entrar como administrativo
                        /* code administrativo*/
                    }
                    else if (optAux == 2)
                    { // Entrar como socio
                        /* code socio*/
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && !socio && medico)
                { // Solo medico
                    /* code medico*/
                }
                else if (!administrativo && socio && medico)
                { // Medico y socio
                    int optAux;
                    cout << "\n\t\t -Mustualista Grupo 5-";
                    cout << "\n\t Elija el con el tipo de usuario que desea ingresar:";
                    cout << "\n [1] - Medico.";
                    cout << "\n [2] - Socio.";
                    cout << "\n Opcion >> ";
                    cin >> optAux;
                    if (optAux == 1)
                    { // Entrar como medico
                        /* code medico*/
                    }
                    else if (optAux == 2)
                    { // Entrar como socio
                        /* code socio*/
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && socio && !medico)
                { // Solo socio
                    /* code socio */
                }
            }
        }
        else
        {
            cout << "\n\t Saliendo del sistema!";
            salir = true;
        }

    } while (!salir);
}