#include "Fabrica.h"
#include "IUsuario.h"
#include "IRegistroMedico.h"
#include "DTFecha.h"
#include "DTCategoriaRep.h"
#include "definiciones.h"
#include <list>
#include <map>
#include <string>
#include "iostream"
using namespace std;

int main()
{
    string nombre, cedula, apellido, contraseña;
    bool salir = false;

    Fabrica *f = Fabrica::getInstancia();
    IUsuario *usuarios = f->getIUsuario();
    IRegistroMedico *registros = f->getIRegistroMedico();
    //static_cast<CRegistroMedico*>(registros)->setControladorUsuario(static_cast<CUsuario*>(usuarios));

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
            bool exist, valida = false, sesionActiva = false, primerIngr = false, socio = false, medico = false, administrativo = false;

            cout << "\n\t\t -Iniciar sesion-";
            cout << "\n\t Para iniciar sesion ingrese su cedula y contraseña:";
            cout << "\n Cedula: ";
            cin >> ci;
            exist = usuarios->existeUsuario(ci);
            // primer contraseña
            if (exist)
            {
                cout << "\n Contraseña: ";
                cin >> contra;
                primerIngr = usuarios->primerContraseña();
                if (primerIngr)
                {
                    usuarios->darPrimerContraseña(contra);
                }
                else
                {
                    valida = usuarios->verificarContraseña(ci, contra);
                    if (!valida)
                    {
                        cout << "\n\t\t Contraseña no valida!\n";
                    }
                }
                if (valida || primerIngr)
                {
                    sesionActiva = usuarios->asignarSesion(ci);
                    list<TipoUsuario> *tu = usuarios->tipoDeUsuario(ci);
                    for (TipoUsuario t : *tu)
                    {
                        if (t == Tipo_Administrativo)
                        {
                            administrativo = true;
                        }
                        else if (t == Tipo_Socio)
                        {
                            socio = true;
                        }
                        else if (t == Tipo_Medico)
                        {
                            medico = true;
                        }
                    }
                }
            }
            else
            {
                cout << "\n\t\t No existe el usuario en el sistema!";
            }
            cout << "\n estoy aca y voy bien!!";

            while (sesionActiva)
            { // Inicio de sesion segun categoria
                int ingresaComo;
                if (administrativo && !socio && !medico)
                { // Solo Administrativo
                    ingresaComo = 1;
                }
                else if (administrativo && socio && !medico)
                { // Administrativo y socio
                    int optAux;
                    cout << "\n\t\t -Mustualista Grupo 5-";
                    cout << "\n\t Elija con el tipo de usuario que desea ingresar:";
                    cout << "\n\n [1] - Administrativo.";
                    cout << "\n [2] - Socio.";
                    cout << "\n\n Opcion >> ";
                    cin >> optAux;
                    if (optAux == 1)
                    { // Entrar como administrativo
                        ingresaComo = 1;
                    }
                    else if (optAux == 2)
                    { // Entrar como socio
                        ingresaComo = 3;
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && !socio && medico)
                { // Solo medico
                    ingresaComo = 2;
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
                        ingresaComo = 2;
                    }
                    else if (optAux == 2)
                    { // Entrar como socio
                        ingresaComo = 3;
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && socio && !medico)
                { // Solo socio
                    ingresaComo = 3;
                }
                if (ingresaComo == 1)
                { // Administrativo
                    int opt;
                    cout << "\n\t\t --Administrativo--";
                    cout << "\n\t Opciones del menu Administrativo.";
                    cout << "\n\n [1] - Alta Usuario.";
                    cout << "\n [2] - Alta Representacion Estandarizada de Problemas de Salud";
                    cout << "\n [3] - Registro de Consulta";
                    cout << "\n [4] - Cerrar Sesion";
                    cout << "\n\n Opcion >> ";
                    cin >> opt;
                    if (opt == 1) // Alta Usuario
                    {
                        string ci, nomb, apell, sexo;
                        int dia, año, mes, i = 0;
                        bool s = true, med = false, admin = false, existe;
                        list<TipoUsuario> *tUsr = new list<TipoUsuario>;
                        cout << "\n\t Ingrese los datos del nuevo Usuario.";
                        cout << "\n C.I: ";
                        cin >> ci;
                        existe = usuarios->esUsuario(ci);
                        if (!existe)
                        {
                            cout << "\n Nombre: ";
                            cin >> nomb;
                            cout << "\n Apellido: ";
                            cin >> apell;
                            cout << "\n Sexo: ";
                            cin >> sexo;
                            cout << "\n Fecha de Nacimiento: ";
                            cout << "\n Dia: ";
                            cin >> dia;
                            cout << "\n Mes: ";
                            cin >> mes;
                            cout << "\n Año: ";
                            cin >> año;
                            DTFecha fn(dia, mes, año);
                            cout << "\n Ingrese el tipo de usuario";
                            while (s && i < MAX_TIPO_USUARIO)
                            {
                                int op;
                                char otra;
                                cout << "\n\t Elija uno de los siguientes tipos: ";
                                cout << "\n [1] - Administrativo";
                                cout << "\n [2] - Medico";
                                cout << "\n [3] - Socio";
                                cout << "\n Opcion >> ";
                                cin >> op;
                                if (op == 1)
                                {
                                    if (!med)
                                    {
                                        tUsr->push_back(TipoUsuario::Tipo_Administrativo);
                                        i++;
                                    }
                                    else
                                    {
                                        cout << "\n\t El Usuario es un Usuario Medico!!!";
                                    }
                                }
                                else if (op == 2)
                                {
                                    if (!admin)
                                    {
                                        tUsr->push_back(TipoUsuario::Tipo_Medico);
                                        i++;
                                    }
                                    else
                                    {
                                        cout << "\n\t El Usuario es un Usuario Administrativo!!!";
                                    }
                                }
                                else if (op == 3)
                                {
                                    tUsr->push_back(TipoUsuario::Tipo_Socio);
                                    i++;
                                }
                                cout << "\n\n\t Desea ingresar otra categoria al Usuario? [S/N]: ";
                                cin >> otra;
                                if (otra == 'n' || otra == 'N')
                                {
                                    s = false;
                                }
                            }
                            usuarios->altaUsuario(ci, nomb, apell, sexo, fn, tUsr);
                        }
                        else
                        {
                            cout << "\n\t Ya existe un Usuario con la cedula " << ci << ".";
                        }
                    }
                    else if (opt == 2) // Alta Representacion estandarizada de un problema de salud
                    {
                        int opcProblema;
                        cout << "\n\t -Problemas de Salud Registrados-";
                        cout << "\n [1] - Listar Categorias de Problemas de Salud";
                        cout << "\n [2] - Ingresar Nueva Categoria";
                        cout << "\n [3] - Alta Problema de Salud";
                        cout << "\n [4] - Salir";
                        cout << "\n Opcion >> ";
                        cin >> opcProblema;
                        if (opcProblema == 1)
                        {
                            /* set<DTCategoriaRep> *setCatP = new set<DTCategoriaRep>;
                            setCatP = registros->mostrarRepresentaciones();
                            for (DTCategoriaRep dt : *setCatP)
                            {
                                dt.mostrarCategoria();
                            }
                            delete setCatP; */
                        }
                        else if (opcProblema == 2)
                        {
                            string id, descrip, codigo, etiqueta;
                            char ingresar;
                            cout << "\n\t -Alta Categoria de Problema de Salud-";
                            cout << "\n Ingrese los datos de la nueva Categoria.";
                            cout << "\n Id Categoria: ";
                            cin >> id;
                            cout << "\n Descripcion: ";
                            cin >> descrip;
                            registros->altaCategoriaRepresentacion(id, descrip);
                            cout << "\n\t Desea ingresar un problema de salud a la categoria? [S/N]: ";
                            cin >> ingresar;
                            while (ingresar == 's' || ingresar == 'S')
                            {
                                cout << "\n Ingrese un nuevo Problema de Salud a la Categoria " << id << ".";
                                cout << "\n Codigo: ";
                                cin >> codigo;
                                cout << "\n Etiqueta: ";
                                cin >> etiqueta;
                                registros->altaProblemaDeSalud(id, codigo, etiqueta);
                                cout << "\n\t Desea ingresar un problema de salud a la categoria? [S/N]: ";
                                cin >> ingresar;
                            }
                        }
                        else if (opcProblema == 3)
                        {
                            cout << "\n\t Ingresar Nuevo Problema de salud al Sistema.";
                            char ingresar;
                            do
                            {
                                string idC, codigo, etiqueta;
                                cout << "\n Ingrese la categoria del problema a ingresar.";
                                cout << "\n Id Categoria: ";
                                cin >> idC;
                                cout << "\n\t Ingrese los datos del Problema De Salud a ingresar";
                                cout << "\n Codigo: ";
                                cin >> codigo;
                                cout << "\n Etiqueta: ";
                                cin >> etiqueta;
                                registros->altaProblemaDeSalud(idC, codigo, etiqueta);
                                cout << "\n\t Desea ingresar un problema de salud? [S/N]: ";
                                cin >> ingresar;
                            } while (ingresar == 's' || ingresar == 'S');
                        }
                    }
                    else if (opt == 3) // Registro Consulta
                    {
                        string ci;
                        cout << "\n\t\t -Registro de Consultas-";
                        cout << "\n\t A continuacion ingrese los datos del Socio a Registrar.";
                        cout << "\n Cedula: ";
                        cin >> ci;
                    }
                    else if (opt == 4) // Cerrar sesion
                    {
                        sesionActiva = usuarios->cerrarSesion();
                    }
                }
                else if (ingresaComo == 2)
                { // Ingresa como medico
                    /* code */
                }
                else if (ingresaComo == 3)
                { // Ingresa como Socio
                    /* code */
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