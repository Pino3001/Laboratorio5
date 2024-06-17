#include "CRegistroMedico.h"

CRegistroMedico::CRegistroMedico()
{
    this->controladorUsuario = nullptr;
    this->memConsulta = nullptr;
    this->problemasDeSalud = new set<ProblemaDeSalud *>;
}

set<DTConsulta> CRegistroMedico::mostrarConsultas(){}
Consulta *CRegistroMedico::seleccionarConsulta(string idConsulta){}
set<DTCategoriaRep> CRegistroMedico::mostrarRepresentaciones(){}
CategoriaRepresentacion *CRegistroMedico::seleccionarCategoria(string nombreCat){}
set<DTProblemaDeSalud> CRegistroMedico::mostrarProblemaDeSalud(){}
ProblemaDeSalud *CRegistroMedico::seleccionarProblemaDeSalud(string codigo, string etiqueta){}
Diagnostico *CRegistroMedico::crearDiagnostico(ProblemaDeSalud pds, string descripcion){}
void CRegistroMedico::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<Medicamentos> listMedicamentos){}
void CRegistroMedico::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha){}
void CRegistroMedico::agregarDiagnostico(Diagnostico diagnostico){}
set<DTCategoriaRep> CRegistroMedico::listarRepresentaciones(){}

CRegistroMedico::~CRegistroMedico()
{
}