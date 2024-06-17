#ifndef CREGISTROMEDICO_H
#define CREGISTROMEDICO_H
#include "IRegistroMedico.h"
#include "CUsuario.h"
#include "Consulta.h"
#include "ProblemaDeSalud.h"
#include "definiciones.h"
#include <set>

class CRegistroMedico : public IRegistroMedico
{
private:
    CUsuario *controladorUsuario;
    Consulta *memConsulta;
    set<ProblemaDeSalud *> *problemasDeSalud;

public:
    CRegistroMedico();

    set<DTConsulta> mostrarConsultas();
    Consulta *seleccionarConsulta(string idConsulta);
    set<DTCategoriaRep> mostrarRepresentaciones();
    CategoriaRepresentacion *seleccionarCategoria(string nombreCat);
    set<DTProblemaDeSalud> mostrarProblemaDeSalud();
    ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo, string etiqueta);
    Diagnostico *crearDiagnostico(ProblemaDeSalud pds, string descripcion);
    void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<Medicamentos> listMedicamentos);
    void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha);
    void agregarDiagnostico(Diagnostico diagnostico);
    set<DTCategoriaRep> listarRepresentaciones();

    ~CRegistroMedico();
};


