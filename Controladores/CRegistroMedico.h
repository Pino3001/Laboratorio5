#ifndef CREGISTROMEDICO_H
#define CREGISTROMEDICO_H
#include "IRegistroMedico.h"
#include "CategoriaProblemaSalud.h"
#include "DTProblemaDeSalud.h"
#include "DTCategoriaRep.h"
#include "CUsuario.h"
class Diagnostico;
#include <list>
#include <set>
#include <map>
#include <string>

class CRegistroMedico : public IRegistroMedico
{
private:
    static CRegistroMedico *instance;
    Consulta *memConsulta;
    map<string, CategoriaProblemaSalud *> *problemasDeSalud;
    map<DTFecha, list<Actividad *>> *memActividades;

    CRegistroMedico();

public:
    static CRegistroMedico *getInstance();

    list<DTConsulta> mostrarConsultas(const DTFecha fechaHoy);
    void registroConsulta(string ci, string ciMedico, const DTFecha fechaHoy);
    list<DTCategoriaRep> *mostrarRepresentaciones();
    void altaCategoriaRepresentacion(string id, string descripcion); 
    void altaProblemaDeSalud(string id, string codigo, string etiqueta);
    void reservaNuevaConsulta(string ciMedico, string ciSocio, const DTFecha fechaConsulta, const DTFecha fecReserva,const DTHora horaCosn);
    list<DTProblemaDeSalud> mostrarProblemaDeSalud();
    void altaDiagnosticoConsulta(map<string,map<string,string>> *problAsoc, string descripDiagnostico, bool esQuirurgico, bool esFarmaco, list<string> *medeicamentos, string descripFarmaco, const DTFecha fechaCirujia, string ciMedicoCirujano, string descripcionQuirurji);
    void seleccionarConsulta(string ciSocio, string ciMedico, const DTFecha fechaCons);
    void crearHistorialPaciente();
    list<DTHistorial> obtenerHistorialPaciente(string ciSocio);
    void registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion);

    list<DTCategoriaRep> listarRepresentaciones();
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnostico(Diagnostico diagnostico);

    ~CRegistroMedico();
};
#endif
