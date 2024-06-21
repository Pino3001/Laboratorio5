#ifndef CREGISTROMEDICO_H
#define CREGISTROMEDICO_H
#include "IRegistroMedico.h"
#include "CategoriaProblemaSalud.h"
#include "CUsuario.h"
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
    ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo, string etiqueta);
    list<DTProblemaDeSalud> mostrarProblemaDeSalud();

    list<DTCategoriaRep> listarRepresentaciones();
    CategoriaProblemaSalud *seleccionarCategoria(string nombreCat);
    Consulta *seleccionarConsulta(string idConsulta);
    Diagnostico *crearDiagnostico(ProblemaDeSalud pds, string descripcion);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha);
    void agregarDiagnostico(Diagnostico diagnostico);

    ~CRegistroMedico();
};
#endif
