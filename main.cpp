#include "Fabrica.h"
#include "IUsuario.h"
#include "IRegistroMedico.h"
#include "DTFecha.h"
#include "DTCategoriaRep.h"
#include "DTDatosUsuario.h"
#include "DTConsulta.h"
#include "definiciones.h"
#include <list>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include "iostream"
#include <stdexcept>
#include <cctype>
using namespace std;

bool contraseniaValida(string str)
{
    // Verificar si la longitud está entre 6 y 9
    if (str.length() < 6 || str.length() > 9)
    {
        return false;
    }
    // Verificar si todos los caracteres son alfanuméricos
    for (char c : str)
    {
        if (!isalnum(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }
    return true;
}

DTFecha splitFecha(string str)
{
    istringstream ss(str);
    string token;
    int i = 1;
    int dia = -1;
    int mes = -1;
    int anio = -1;
    while (getline(ss, token, '/'))
    {
        if (i == 1)
        {
            if (token.length() > 2 || token.length() == 0)
                throw runtime_error("Formato de fecha invalido");
            dia = stoi(token);
        }
        else if (i == 2)
        {
            if (token.length() > 2 || token.length() == 0)
                throw runtime_error("Formato de fecha invalido");
            mes = stoi(token);
        }
        else if (i == 3)
        {
            if (token.length() != 4)
                throw runtime_error("Formato de fecha invalido");
            anio = stoi(token);
        }
        i++;
    }
    if (i > 4)
        throw runtime_error("Formato de hora invalido");
    if (dia > 31 || dia < 1)
        throw runtime_error("Formato de fecha invalido");
    if (mes > 12 || mes < 1)
        throw runtime_error("Formato de fecha invalido");
    DTFecha fecha(dia, mes, anio);
    return fecha;
}

DTHora splitHora(string str)
{
    istringstream stri(str);
    string token;
    int i = 1;
    int ss = -1;
    int mm = -1;
    int hh = -1;
    while (getline(stri, token, ':'))
    {
        if (i == 1)
        {
            if (token.length() > 2 || token.length() == 0)
                throw runtime_error("Formato de hora invalido");
            hh = stoi(token);
        }
        else if (i == 2)
        {
            if (token.length() > 2 || token.length() == 0)
                throw runtime_error("Formato de hora invalido");
            mm = stoi(token);
        }
        else if (i == 3)
        {
            if (token.length() > 2 || token.length() == 0)
                throw runtime_error("Formato de hora invalido");
            ss = stoi(token);
        }
        i++;
    }
    if (i > 4)
        throw runtime_error("Formato de hora invalido");
    if (hh > 23 || hh < 0)
        throw runtime_error("Formato de hora invalido");
    if (mm > 59 || mm < 1)
        throw runtime_error("Formato de hora invalido");
    if (ss > 59 || ss < 1)
        throw runtime_error("Formato de hora invalido");
    DTHora hora(hh, mm, ss);
    return hora;
}

void CargarDatosDefecto(IUsuario *usuarios, IRegistroMedico *registros)
{
    // Representación Estandarizada
    // X1
    registros->altaCategoriaRepresentacion("A", "Afecciones Pulmonares");
    // X2
    registros->altaCategoriaRepresentacion("B", "Aparato Digestivo");

    // R1
    registros->altaProblemaDeSalud("A", "01", "Asma");
    // R2
    registros->altaProblemaDeSalud("A", "02", "Congestión");
    // R3
    registros->altaProblemaDeSalud("B", "01", "Nauseas");

    // Usuarios
    //  TM
    list<TipoUsuario> tUsr;
    tUsr.push_back(TipoUsuario::Tipo_Socio);
    usuarios->altaUsuario("34562345", "Tifany", "McKensey", "Femenino", DTFecha(1, 1, 1990), tUsr);
    // DP
    list<TipoUsuario> tUsr1;
    tUsr1.push_back(TipoUsuario::Tipo_Socio);
    usuarios->altaUsuario("12345435", "Diego", "Perez", "Masculino", DTFecha(3, 3, 1980), tUsr1);
    // JM
    list<TipoUsuario> tUsr2;
    tUsr2.push_back(TipoUsuario::Tipo_Socio);
    tUsr2.push_back(TipoUsuario::Tipo_Medico);
    usuarios->altaUsuario("65436667", "Juan", "Montoya", "Masculino", DTFecha(7, 4, 1970), tUsr2);
    // DC
    list<TipoUsuario> tUsr3;
    tUsr3.push_back(TipoUsuario::Tipo_Medico);
    usuarios->altaUsuario("43521343", "Debora", "Corral", "Femenino", DTFecha(13, 7, 1993), tUsr3);
    // AL
    list<TipoUsuario> tUsr4;
    tUsr4.push_back(TipoUsuario::Tipo_Medico);
    usuarios->altaUsuario("98056743", "Ana", "Lopez", "Femenino", DTFecha(24, 9, 1981), tUsr4);

    // Consultas Comunes
    //  C1 21/06/2014 23/06/2014 JM TM
    registros->reservaNuevaConsulta("65436667", "34562345", DTFecha(23, 6, 2014), DTFecha(21, 6, 2014), DTHora(17, 00, 00));
    registros->registroConsulta("34562345", "65436667", DTFecha(23, 6, 2014));

    // C2 22/05/2014 22/06/2014 DC TM
    registros->reservaNuevaConsulta("43521343", "34562345", DTFecha(22, 6, 2014), DTFecha(22, 5, 2014), DTHora(17, 00, 00));
    // registros->registroConsulta("34562345", "43521343", DTFecha(22, 6, 2014));

    // C3 15/03/2014 16/03/2014 DC JM
    registros->reservaNuevaConsulta("43521343", "65436667", DTFecha(16, 3, 2014), DTFecha(15, 3, 2014), DTHora(17, 00, 00));
    registros->registroConsulta("65436667", "43521343", DTFecha(16, 3, 2014));

    // C4 28/02/2014 1/03/2014 AL DP
    registros->reservaNuevaConsulta("98056743", "12345435", DTFecha(1, 3, 2014), DTFecha(28, 2, 2014), DTHora(17, 00, 00));
    registros->registroConsulta("12345435", "98056743", DTFecha(1, 3, 2014));

    // Consultas Emergencia
    //  U1
    registros->registroConsultaEmergencia("34562345", "65436667", DTFecha(23, 5, 2014), DTHora(17, 00, 00), "Fiebre alta");
    // U2
    registros->registroConsultaEmergencia("65436667", "43521343", DTFecha(24, 5, 2014), DTHora(17, 00, 00), "Asma");
    // U3
    registros->registroConsultaEmergencia("65436667", "98056743", DTFecha(3, 3, 2014), DTHora(17, 00, 00), "Mareos");

    // Selecciono C1
    registros->seleccionarConsulta("34562345", "65436667", DTFecha(23, 6, 2014));

    map<string, list<string>> *probYCat = new map<string, list<string>>();
    list<string> *problemas = new list<string>();
    problemas->push_back("A02");
    probYCat->insert(make_pair("A", *problemas));
    // D1
    registros->agregarDiagnostico(*probYCat, "Desc 1");
    delete probYCat;
    delete problemas;

    list<string> *medicamentos = new list<string>();
    medicamentos->push_back("M1");
    // F1
    registros->agregarTratamientoFarmaco("Desc 1", medicamentos);

    medicamentos = new list<string>();
    medicamentos->push_back("M2");
    // F2
    registros->agregarTratamientoFarmaco("Desc 2", medicamentos);

    medicamentos = new list<string>();
    medicamentos->push_back("M3");
    // F3
    registros->agregarTratamientoFarmaco("Desc 3", medicamentos);

    // C1 esta seleccionada
    probYCat = new map<string, list<string>>();
    problemas = new list<string>();
    problemas->push_back("B01");
    probYCat->insert(make_pair("B", *problemas));
    // D2
    registros->agregarDiagnostico(*probYCat, "Desc 2");
    delete probYCat;
    delete problemas;

    // Q1
    registros->agregarTratamientoQuirurgico("65436667", "Desc 11", DTFecha(25, 7, 2014));

    // Selecciono C3
    registros->seleccionarConsulta("65436667", "43521343", DTFecha(16, 3, 2014));

    probYCat = new map<string, list<string>>();
    problemas = new list<string>();
    problemas->push_back("A02");
    probYCat->insert(make_pair("A", *problemas));
    // D3
    registros->agregarDiagnostico(*probYCat, "Desc 3");
    delete probYCat;
    delete problemas;

    // Q2
    registros->agregarTratamientoQuirurgico("43521343", "Desc 22", DTFecha(1, 2, 2015));

    // Selecciono U1
    registros->seleccionarConsulta("34562345", "65436667", DTFecha(23, 5, 2014));

    probYCat = new map<string, list<string>>();
    problemas = new list<string>();
    problemas->push_back("B01");
    probYCat->insert(make_pair("B", *problemas));
    // D4
    registros->agregarDiagnostico(*probYCat, "Desc 4");
    delete probYCat;
    delete problemas;

    medicamentos = new list<string>();
    medicamentos->push_back("M1");
    // F4
    registros->agregarTratamientoFarmaco("Desc 4", medicamentos);

    // Selecciono U2
    registros->seleccionarConsulta("65436667", "43521343", DTFecha(24, 5, 2014));

    probYCat = new map<string, list<string>>();
    problemas = new list<string>();
    problemas->push_back("A01");
    probYCat->insert(make_pair("A", *problemas));
    // D5
    registros->agregarDiagnostico(*probYCat, "Desc 5");
    delete probYCat;
    delete problemas;

    medicamentos = new list<string>();
    medicamentos->push_back("M2");
    // F5
    registros->agregarTratamientoFarmaco("Desc 5", medicamentos);

    // U2 esta seleccionada
    probYCat = new map<string, list<string>>();
    problemas = new list<string>();
    problemas->push_back("A02");
    probYCat->insert(make_pair("A", *problemas));
    // D6
    registros->agregarDiagnostico(*probYCat, "Desc 6");
    delete probYCat;
    delete problemas;

    // F6
    medicamentos = new list<string>();
    medicamentos->push_back("M3");
    registros->agregarTratamientoFarmaco("Desc 6", medicamentos);
}

int main()
{
    bool salir = false;

    Fabrica *f = Fabrica::getInstancia();
    IUsuario *usuarios = f->getIUsuario();
    IRegistroMedico *registros = f->getIRegistroMedico();

    DTFecha fch(28, 12, 1988);
    list<TipoUsuario> tUsr;
    tUsr.push_back(TipoUsuario::Tipo_Administrativo);
    usuarios->altaUsuario("1", "James", "Peer", "Masculino", fch, tUsr);
    cout << "\n\n\t\t Usuario por defecto creado!";
    do
    {
        int opt;

        cout << "\n\t\t Mutualista Grupo 5";
        cout << "\n\t [1] - Iniciar sesion.";
        cout << "\n\t [2] - Cargar datos de prueba.";
        cout << "\n\t [3] - Salir.";
        cout << "\n opt >> ";
        cin >> opt;
        if (opt == 1)
        {
            string ci, contra;
            bool exist, valida = false, sesionActiva = false, primerIngr = false, socio = false, medico = false, administrativo = false;

            cout << "\n\t\t -Iniciar sesion-";
            cout << "\n\t Para iniciar sesion ingrese su cedula y contrasenia:";
            cout << "\n Cedula: ";
            cin >> ci;
            exist = usuarios->existeUsuario(ci);
            if (exist)
            {
                cout << "\n Contrasenia: ";
                cin >> contra;
                if (contraseniaValida(contra))
                {
                    // Si es primer ingreso setea la contraseña al usuario.
                    primerIngr = usuarios->primerContrasenia();
                    if (primerIngr)
                    {
                        usuarios->darPrimerContrasenia(contra);
                    }
                    else // No es el primer ingreso, entonces compruebo que la contraseña sea correcta.
                    {
                        valida = usuarios->verificarContrasenia(contra);
                        if (!valida)
                        {
                            cout << "\n\t\t Contraseña no valida!\n";
                        }
                    }
                    if (valida || primerIngr) // Se cumplen las condiciones para iniciar sesion.
                    {
                        sesionActiva = usuarios->asignarSesion(ci);          // Dar la sesion al usuario.
                        list<TipoUsuario> *tu = usuarios->tipoDeUsuario(ci); // Obtengo los tipos de usuarios
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
                    cout << "\n\t\t La contraseña no tiene un formato valido.";
                }
            }
            else
            {
                cout << "\n\t\t No existe el usuario en el sistema!";
            }
            while (sesionActiva)
            {
                int ingresaComo;
                // Inicio de sesion segun categoria
                if (administrativo && !socio && !medico)
                {
                    // Solo Administrativo
                    ingresaComo = 1;
                }
                else if (administrativo && socio && !medico)
                {
                    // Administrativo y socio, usr elije como ingresar.
                    int optAux;
                    cout << "\n\t\t -Mustualista Grupo 5-";
                    cout << "\n\t Elija con el tipo de usuario que desea ingresar:";
                    cout << "\n\n [1] - Administrativo.";
                    cout << "\n [2] - Socio.";
                    cout << "\n\n Opcion >> ";
                    cin >> optAux;
                    if (optAux == 1)
                    {
                        // Entrar como administrativo
                        ingresaComo = 1;
                    }
                    else if (optAux == 2)
                    {
                        // Entrar como socio
                        ingresaComo = 3;
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && !socio && medico)
                {
                    // Solo medico
                    ingresaComo = 2;
                }
                else if (!administrativo && socio && medico)
                {
                    // Medico y socio
                    int optAux;
                    cout << "\n\t\t -Mustualista Grupo 5-";
                    cout << "\n\t Elija el con el tipo de usuario que desea ingresar:";
                    cout << "\n [1] - Medico.";
                    cout << "\n [2] - Socio.";
                    cout << "\n Opcion >> ";
                    cin >> optAux;
                    if (optAux == 1)
                    {
                        // Entrar como medico
                        ingresaComo = 2;
                    }
                    else if (optAux == 2)
                    {
                        // Entrar como socio
                        ingresaComo = 3;
                    }
                    else
                    {
                        cout << "\n Ingrese una opcion correcta!!";
                    }
                }
                else if (!administrativo && socio && !medico)
                {
                    // Solo socio
                    ingresaComo = 3;
                }
                if (ingresaComo == 1)
                {
                    // Administrativo
                    int opt;
                    cout << "\n\t\t --Administrativo--";
                    cout << "\n\t Opciones del menu Administrativo.\n";
                    cout << "\n [1] - Alta Usuario.";
                    cout << "\n [2] - Alta Representacion Estandarizada de Problemas de Salud";
                    cout << "\n [3] - Registro de Consulta";
                    cout << "\n [4] - Cerrar Sesion";
                    cout << "\n\n Opcion >> ";
                    cin >> opt;
                    if (opt == 1) // Alta Usuario
                    {
                        bool ingOtro;
                        do
                        {
                            string ci, nomb, apell, sexo;
                            char otro;
                            int dia, anio, mes, i = 0;
                            bool seguir = true, tSoci = true, tMed = false, tAdmin = false, existe;
                            list<TipoUsuario> tUsr;
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
                                cout << "\n\t Dia: ";
                                cin >> dia;
                                cout << "\n\t Mes: ";
                                cin >> mes;
                                cout << "\n\t Año: ";
                                cin >> anio;
                                DTFecha fn(dia, mes, anio);
                                cout << "\n Ingrese el tipo de usuario";
                                while (seguir && i < MAX_TIPO_USUARIO)
                                {
                                    int op;
                                    char otraC;
                                    cout << "\n\t Elija uno de los siguientes tipos: ";
                                    cout << "\n [1] - Administrativo";
                                    cout << "\n [2] - Medico";
                                    cout << "\n [3] - Socio";
                                    cout << "\n Opcion >> ";
                                    cin >> op;
                                    if (op == 1)
                                    {
                                        if (!tMed)
                                        {
                                            tUsr.push_back(TipoUsuario::Tipo_Administrativo);
                                            tMed = true;
                                            i++;
                                        }
                                        else
                                        {
                                            cout << "\n\t La categoria Medico ya ha sido ingresada!!!";
                                        }
                                    }
                                    else if (op == 2)
                                    {
                                        if (!tAdmin)
                                        {
                                            tUsr.push_back(TipoUsuario::Tipo_Medico);
                                            tAdmin = true;
                                            i++;
                                        }
                                        else
                                        {
                                            cout << "\n\t La categoria Administrativo ya ha sido ingresada!!!";
                                        }
                                    }
                                    else if (op == 3)
                                    {
                                        if (!tSoci)
                                        {
                                            tUsr.push_back(TipoUsuario::Tipo_Socio);
                                            tSoci = true;
                                            i++;
                                        }
                                        else
                                        {
                                            cout << "\n\t La categoria Socio ya ha sido ingresada!!!";
                                        }
                                    }
                                    else
                                    {
                                        cout << "\n Ingrese una opcion correcta!!";
                                    }
                                    cout << "\n\n\t Desea ingresar otra categoria para el Usuario? [S/N]: ";
                                    cin >> otraC;
                                    if (otraC == 'n' || otraC == 'N')
                                    {
                                        seguir = false;
                                    }
                                    else
                                    {
                                        seguir = true;
                                    }
                                }
                                usuarios->altaUsuario(ci, nomb, apell, sexo, fn, tUsr);
                                cout << "\n\tDesea ingresar Un usuario mas? [S / N]";
                                cin >> otro;
                                if (otro == 's' || otro == 'S')
                                {
                                    ingOtro = true;
                                }
                                else
                                {
                                    ingOtro = false;
                                }
                            }
                            else
                            {
                                char cancel;
                                cout << "\n\t Ya existe un Usuario con la cedula " << ci << ".";
                                cout << "\n\t\t Desea cancelar el intento? [S / N]: ";
                                cin >> cancel;
                                if (cancel == 's' || cancel == 'S')
                                {
                                    ingOtro = false;
                                }
                                else
                                {
                                    ingOtro = true;
                                }
                            }
                        } while (ingOtro);
                    }
                    else if (opt == 2) // Alta Representacion estandarizada de un problema de salud
                    {
                        bool salProblemas = false;
                        do
                        {
                            /* code */

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
                                list<DTCategoriaRep> listCatRe;
                                listCatRe = registros->listarRepresentacionesEstandarizadas();
                                cout << "\n\t Categorias de problemas de salud:";
                                for (DTCategoriaRep dt : listCatRe)
                                {
                                    cout << "\n\t\t" << dt.getIdCategoria() << " - " << dt.getDescripcion();
                                }
                                cout << "\n";
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
                            else if (opcProblema == 4)
                            {
                                salProblemas = true;
                            }
                            else
                            {
                                cout << "\n Ingrese una opcion correcta!!";
                            }
                        } while (salProblemas);
                    }
                    else if (opt == 3) // Registro Consulta
                    {
                        bool ingCons;
                        string str;
                        cout << "\n\t\t -Registro de Consultas-";
                        cout << "\n\t Ingrese la fecha de hoy.";
                        cout << "Fecha: ";
                        cin >> str;
                        DTFecha fecha = splitFecha(str);
                        cout << "\n\t Registrar Consultas.";
                        do
                        {
                            string ciSocio, ciMedico;
                            char otraCons;
                            cout << "\n\t A continuacion ingrese los datos del Socio a Registrar.";
                            cout << "\n Cedula Socio: ";
                            cin >> ciSocio;
                            cout << "\n Cedula Medico: ";
                            cin >> ciMedico;
                            registros->registroConsulta(ciSocio, ciMedico, fecha);
                            cout << "\n\t Desea registrar otra consulta? [S / N]: ";
                            cin >> otraCons;
                            if (otraCons == 's' || otraCons == 'S')
                            {
                                ingCons = true;
                            }
                            else
                            {
                                ingCons = false;
                            }
                        } while (ingCons);
                    }
                    else if (opt == 4) // Cerrar sesion
                    {
                        sesionActiva = usuarios->cerrarSesion();
                        cout << "\n\t Sesion Terminada!!!";
                    }
                }
                else if (ingresaComo == 2) // Ingresa como medico
                {
                    bool salMedico;
                    do
                    {
                        int optMedico;
                        cout << "\n\t\t --Medico--";
                        cout << "\n\t Opciones del menu Medico.\n";
                        cout << "\n [1] - Alta diagnostico Consulta.";
                        cout << "\n [2] - Listar Representaciones Estandarizadas.";
                        cout << "\n [3] - Obtener Historial Paciente.";
                        cout << "\n [4] - Cerrar Sesion";
                        cout << "\n\n Opcion >> ";
                        cin >> optMedico;
                        if (optMedico == 1)
                        {
                            bool salAltDiag;
                            do
                            {
                                int opcDiagn;
                                DTFecha fecha;
                                cout << "\n\t\t Altas Diagnosticos.";
                                cout << "\n\t[1] - Listar Consultas por fecha.";
                                cout << "\n\t[2] - Dar de alta Diagnostico.";
                                cout << "\n\t[3] - Salir.";
                                cout << "\n\t Opcion >> ";
                                cin >> opcDiagn;
                                if (opcDiagn == 1)
                                {
                                    string str;
                                    cout << "\n\t Ingrese la fecha de las consultas a mostrar.";
                                    cout << "Fecha: ";
                                    cin >> str;
                                    DTFecha fecha = splitFecha(str);
                                    list<DTConsulta> lDTC;
                                    lDTC = registros->mostrarConsultas(fecha);
                                    for (DTConsulta dc : lDTC)
                                    {
                                        dc.mostrarDTConsulta();
                                    }
                                }
                                else if (opcDiagn == 2)
                                {
                                    string ciSocio, descrip;
                                    bool otroProb;
                                    char listar, aT;
                                    string id, codigo;
                                    map<string, list<string>> mapProb;
                                    cout << "\n\t\t Alta Diagnostico.";
                                    cout << "\n\t A continuacion ingrese los datos de la Consulta.";
                                    cout << "\n\n\t Cedula Socio: ";
                                    cin >> ciSocio;
                                    registros->seleccionarConsulta(ciSocio, ci, fecha);
                                    cout << "\n\t Ingresar Diagnostico:";
                                    cout << "\n\t Descripcion del Diagnostico: ";
                                    cin >> descrip;
                                    do
                                    {
                                        char oP;
                                        cout << "\n\t Listar problemas de salud? [S / N]:";
                                        cin >> listar;
                                        if (listar == 's' || listar == 'S')
                                        {
                                            list<DTCategoriaRep> lDTcr;
                                            lDTcr = registros->listarRepresentacionesEstandarizadas();
                                            for (DTCategoriaRep dc : lDTcr)
                                            {
                                                dc.mostrarCategoria();
                                            }
                                            cout << "\n\t Ingrese el ID de la categoria: ";
                                            cin >> id;
                                            cout << "\n\t Ingrese el codigo del problema de salud: ";
                                            cin >> codigo;
                                            auto it = mapProb.find(id);
                                            if (it != mapProb.end())
                                            {
                                                list<string> liP;
                                                liP.push_back(codigo);
                                                mapProb.insert(make_pair(id, liP));
                                            }
                                        }
                                        else
                                        {
                                            cout << "\n\t Ingrese el ID de la categoria: ";
                                            cin >> id;
                                            cout << "\n\t Ingrese el codigo del problema de salud: ";
                                            cin >> codigo;
                                            auto it = mapProb.find(id);
                                            if (it != mapProb.end())
                                            {
                                                list<string> liP;
                                                liP.push_back(codigo);
                                                mapProb.insert(make_pair(id, liP));
                                            }
                                        }
                                        cout << "\n\t Ingresar otro problema de salud? [S / N]; ";
                                        cin >> oP;
                                        if (oP == 's' || oP == 'S')
                                        {
                                            otroProb = true;
                                        }
                                        else
                                        {
                                            otroProb = false;
                                        }

                                    } while (otroProb);
                                    registros->agregarDiagnostico(mapProb, descrip);
                                    cout << "\n\n\t Agregar Tratamiento al Diagnostico? [S / N]: ";
                                    cin >> aT;
                                    if (aT == 's' || aT == 'S')
                                    {
                                        int salTrat;
                                        char oTra = true;
                                        do
                                        {
                                            int opTrat;
                                            cout << "\n\t\t Que tipo de tratamiento desea ingresar?";
                                            cout << "\n\t[2] - Quirurjico.";
                                            cout << "\n\t[1] - Farmaco.";
                                            cout << "\n\t Opcion >> ";
                                            cin >> opTrat;
                                            if (opTrat == 1)
                                            {
                                                string ciMedico, descripTrata, str;
                                                cout << "\n\t Descripcion del tratamiento: ";
                                                cin >> descripTrata;
                                                cout << "\n\t Cedula del cirujano: ";
                                                cin >> ciMedico;
                                                cout << "\n\t Ingrese la fecha en que se iba a realizar la Consulta: dd/mm/aa";
                                                cout << "Fecha: ";
                                                cin >> str;
                                                DTFecha fechaCir = splitFecha(str);
                                                registros->agregarTratamientoQuirurgico(ciMedico, descripTrata, fechaCir);
                                            }
                                            else if (opTrat == 2)
                                            {
                                                string descripFarmaco;
                                                bool salMed;
                                                list<string> *listMed = new list<string>;
                                                cout << "\n\t Descripcion del tratamiento: ";
                                                cin >> descripFarmaco;
                                                do
                                                {
                                                    string medicamento;
                                                    char otroMedi;
                                                    cout << "\n\t Ingrese los medicamentos del Tratamiento.";
                                                    cout << "\n\t Medicamento: ";
                                                    cin >> medicamento;
                                                    listMed->push_back(medicamento);
                                                    cout << "\n\t Ingresar otro Medicamneto? [S / N]; ";
                                                    cin >> otroMedi;
                                                    if (otroMedi == 's' || otroMedi == 'S')
                                                    {
                                                        salMed = true;
                                                    }
                                                    else
                                                    {
                                                        salMed = false;
                                                    }

                                                } while (salMed);
                                                registros->agregarTratamientoFarmaco(descripFarmaco, listMed);
                                            }
                                            else
                                            {
                                                cout << "\n\t Ingrese una opcion correcta!!!";
                                            }
                                            cout << "\n\t\t Desea ingresar otro Tratamiento: [S / N]:";
                                            cin >> oTra;
                                            if(oTra == 's' || oTra == 'S') 
                                            {
                                                salTrat = false;
                                            }
                                            else{
                                                salTrat = true;
                                            }

                                        } while (salTrat);
                                    }
                                }
                                else if (opcDiagn == 3)
                                {
                                    salAltDiag = false;
                                }
                                else
                                {
                                    cout << "\n Ingrese una opcion correcta!!";
                                }

                            } while (salAltDiag);
                        }
                        else if (optMedico == 2)
                        {
                            string ciSocio;
                            cout << "\n\t\t -Obtener historial de un Socio-";
                            cout << "\n\t Ingrese la cedula del Socio.";
                            cout << "\n\tCedula: ";
                            cin >> ciSocio;
                            list<DTConsulta> lisHis;
                            lisHis = registros->obtenerHistorialPaciente(ciSocio);
                            for (DTConsulta dc : lisHis)
                            {
                                dc.mostrarVersionHistorial();
                            }
                        }
                        else if (optMedico == 3)
                        {
                            sesionActiva = usuarios->cerrarSesion();
                            salMedico = false;
                            cout << "\n\t Sesion Terminada!!!";
                        }
                        else
                        {
                            cout << "\n Ingrese una opcion correcta!!";
                        }

                    } while (salMedico);
                }
                else if (ingresaComo == 3)
                {
                    // Ingresa como Socio
                    int optSocio;
                    bool salSocio;
                    do
                    {
                        cout << "\n\t\t\t --Socio--";
                        cout << "\n\t\t Opciones del menu Socio.\n";
                        cout << "\n\t[1] - Reserva Consulta.";
                        cout << "\n\t[2] - Devolucion de Reserva.";
                        cout << "\n\t[3] - Cerrar Sesion";
                        cout << "\n\n Opcion >> ";
                        cin >> optSocio;
                        if (optSocio == 1)
                        {
                            bool salReserva = true;
                            do
                            {
                                int optReserva;
                                cout << "\n\t\t -Reserva de Consulta-";
                                cout << "\n\t[1] - Listar Medicos Disponibles.";
                                cout << "\n\t[2] - Reservar Consulta.";
                                cout << "\n\t[3] - Salir.";
                                cout << "\n\n Opcion >> ";
                                cin >> optReserva;
                                if (optReserva == 1)
                                {
                                    list<DTDatosUsuario> dt = usuarios->listarMedicos();
                                    for (DTDatosUsuario du : dt)
                                    {

                                        cout << "\n\tNombre: " << du.getNombre() << " " << du.getApellido();
                                        cout << "\n\tCedula: " << du.getCi() << "\n";
                                        cout << "------------------------------";
                                    }
                                }
                                else if (optReserva == 2)
                                {
                                    string ciMedico, str;
                                    cout << "\n\t Ingrese la fecha del dia de hoy: dd/mm/aa";
                                    cout << "\n\t Fecha: ";
                                    cin >> str;
                                    DTFecha fechaReserva = splitFecha(str);
                                    cout << "\n\t Ingrese la cedula del Medico a consultar: ";
                                    cin >> ciMedico;
                                    cout << "\n\t Elija una Fecha para la Consulta: dd/mm/aa ";
                                    cout << "\n\t Fecha: ";
                                    cin >> str;
                                    DTFecha fechaConsulta = splitFecha(str);
                                    cout << "\n\t Ingrese la Hora de la consulta: hh:ss:mm";
                                    cout << "\n\t Hora: ";
                                    cin >> str;
                                    DTHora horaCosn = splitHora(str);
                                    registros->reservaNuevaConsulta(ciMedico, ci, fechaConsulta, fechaReserva, horaCosn);
                                }
                                else if (optReserva == 3)
                                {
                                    salReserva = false;
                                }
                                else
                                {
                                    cout << "\n Ingrese una opcion correcta!!";
                                }

                            } while (salReserva);
                        }
                        else if (optSocio == 2)
                        {
                            bool salDevReserva = true;
                            do
                            {
                                int opDevRes;
                                cout << "\n\t\t -Devolucion de reserva-";
                                cout << "\n\t [1] - Listar Reservas.";
                                cout << "\n\t [2] - Devolver Reserva.";
                                cout << "\n\t [3] - Salir;";
                                cout << "\n\n Opcion >> ";
                                cin >> opDevRes;
                                if (opDevRes == 1)
                                {
                                    list<DTConsulta> liDC = usuarios->obtenerReservas(ci);
                                    for (DTConsulta dc : liDC)
                                    {
                                        dc.mostrarDTConsulta();
                                    }
                                }
                                else if (opDevRes == 2)
                                {
                                    string ciMedico, str;
                                    cout << "\n\t Ingrese la Cedula del medico que realizaria la Consulta: ";
                                    cin >> ciMedico;
                                    cout << "\n\t Ingrese la fecha en que se iba a realizar la Consulta: dd/mm/aa";
                                    cin >> str;
                                    DTFecha fecha = splitFecha(str);
                                    registros->cancelarReservaConsuta(ci, ciMedico, fecha);
                                }
                                else if (opDevRes == 3)
                                {
                                    salDevReserva = false;
                                }
                                else
                                {
                                    cout << "\n Ingrese una opcion correcta!!";
                                }
                            } while (salDevReserva);
                        }
                        else if (optSocio == 3)
                        {
                            sesionActiva = usuarios->cerrarSesion();
                            salSocio = false;
                            cout << "\n\t Sesion Terminada!!!";
                        }
                        else
                        {
                            cout << "\n Ingrese una opcion correcta!!";
                        }

                    } while (salSocio);
                }
            }
        }
        else if (opt == 2)
        {
            CargarDatosDefecto(usuarios, registros);
            cout << "\n\t\t Datos por defecto cargados.";
        }
        else if (opt == 3)
        {
            cout << "\n\t Saliendo del sistema!";
            salir = true;
        }
        else
        {
            cout << "\n\t Ingrese una opcion correcta!";
        }

    } while (!salir);
}
