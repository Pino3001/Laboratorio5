#ifndef CREGISTROMEDICO_H
#define CREGISTROMEDICO_H
#include "IRegistroMedico.h"
#include "CategoriaProblemaSalud.h"
#include "CUsuario.h"
#include <list>
#include <set>
#include <string>

class CRegistroMedico : public IRegistroMedico
{
private:
    CUsuario *controladorUsuario;
    Consulta *memConsulta;
    list<CategoriaProblemaSalud *> *problemasDeSalud;

public:
    CRegistroMedico();

    list<DTCategoriaRep> *mostrarRepresentaciones();
    void altaCategoriaRepresentacion(string id, string descripcion);
    void altaProblemaDeSalud(string id, string codigo, string etiqueta);


    set<DTConsulta> mostrarConsultas();
    Consulta *seleccionarConsulta(string idConsulta);
    CategoriaProblemaSalud *seleccionarCategoria(string nombreCat);
    set<DTProblemaDeSalud> mostrarProblemaDeSalud();
    ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo, string etiqueta);
    Diagnostico *crearDiagnostico(ProblemaDeSalud pds, string descripcion);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha);
    void agregarDiagnostico(Diagnostico diagnostico);
    set<DTCategoriaRep> listarRepresentaciones();

    ~CRegistroMedico();
};
#endif
