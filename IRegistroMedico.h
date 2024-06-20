#ifndef IREGISTROMEDICO_H
#define IREGISTROMEDICO_H
#include "Usuario.h"
#include "Consulta.h"
#include "CategoriaProblemaSalud.h"
#include "Diagnostico.h"
#include "DTDatosUsuario.h"
#include "DTConsulta.h"
#include <set>
#include <string>
#include "definiciones.h"
#include "DTCategoriaRep.h"

class IRegistroMedico
{
public:
    // Todos los metodos del controlador
    virtual list<DTConsulta> mostrarConsultas(const DTFecha fechaHoy) = 0;
    virtual void registroConsulta(string ci, string ciMedico, const DTFecha fechaHoy) = 0;
    virtual list<DTCategoriaRep> *mostrarRepresentaciones() = 0;
    virtual void altaCategoriaRepresentacion(string id, string descripcion) = 0;
    virtual void altaProblemaDeSalud(string id, string codigo, string etiqueta) = 0;
    virtual void reservaConsulta(string ciMedico, const DTFecha fechaCons, const DTHora horaCosn)=0;

    virtual Consulta *seleccionarConsulta(string idConsulta) = 0;
    virtual CategoriaProblemaSalud *seleccionarCategoria(string nombreCat) = 0;
    virtual list<DTProblemaDeSalud> mostrarProblemaDeSalud() = 0;
    virtual ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo, string etiqueta) = 0;
    virtual Diagnostico *crearDiagnostico(ProblemaDeSalud pds, string descripcion) = 0;
    virtual void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos) = 0;
    virtual void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha) = 0;
    virtual void agregarDiagnostico(Diagnostico diagnostico) = 0;
    virtual list<DTCategoriaRep> listarRepresentaciones() = 0;

    virtual ~IRegistroMedico() = default;
};
#endif