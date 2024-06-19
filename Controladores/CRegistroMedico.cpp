#include "CRegistroMedico.h"
#include <list>

CRegistroMedico::CRegistroMedico()
{
    this->controladorUsuario = nullptr;
    this->memConsulta = nullptr;
    this->problemasDeSalud = new list<CategoriaProblemaSalud *>;
}

list<DTCategoriaRep> *CRegistroMedico::mostrarRepresentaciones()
{
    list<DTCategoriaRep> *ldt = new list<DTCategoriaRep>;
    for (CategoriaProblemaSalud *problema : *this->problemasDeSalud)
    {
        DTCategoriaRep dcr = DTCategoriaRep(problema->getIdCategoria(), problema->getDescripcion());
        ldt->push_back(dcr);
    }
    return ldt;
}

void CRegistroMedico::altaCategoriaRepresentacion(string id, string descripcion)
{
    CategoriaProblemaSalud *cat = new CategoriaProblemaSalud(id, descripcion);
    this->problemasDeSalud->push_back(cat);
}

void CRegistroMedico::altaProblemaDeSalud(string id, string codigo, string etiqueta){

}

set<DTConsulta> CRegistroMedico::mostrarConsultas() {}
Consulta *CRegistroMedico::seleccionarConsulta(string idConsulta) {}

CategoriaProblemaSalud *CRegistroMedico::seleccionarCategoria(string nombreCat) {}
set<DTProblemaDeSalud> CRegistroMedico::mostrarProblemaDeSalud() {}
ProblemaDeSalud *CRegistroMedico::seleccionarProblemaDeSalud(string codigo, string etiqueta) {}
Diagnostico *CRegistroMedico::crearDiagnostico(ProblemaDeSalud pds, string descripcion) {}
void CRegistroMedico::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos) {}
void CRegistroMedico::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha) {}
void CRegistroMedico::agregarDiagnostico(Diagnostico diagnostico) {}
set<DTCategoriaRep> CRegistroMedico::listarRepresentaciones() {}

CRegistroMedico::~CRegistroMedico()
{
}