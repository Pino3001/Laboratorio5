#ifndef IREGISTROMEDICO_H
#define IREGISTROMEDICO_H

#include "Usuario.h"
#include "Consulta.h"
#include "Diagnostico.h"
#include "DTDatosUsuario.h"
#include <set>
#include <string>
#include "definiciones.h"

class IRegistroMedico
{
public:
    // Todos los metodos del controlador

virtual set <DTConsulta>  mostrarConsultas()=0;
virtual Consulta* seleccionarConsulta(string idConsulta)=0;
virtual set <DTCategoriaRep> mostrarRepresentaciones()=0;
virtual CategoriaRepresentacion *seleccionarCategoria(string nombreCat)=0;
virtual set <DTProblemaDeSalud> mostrarProblemaDeSalud()=0;
virtual ProblemaDeSalud *seleccionarProblemaDeSalud(string codigo, string etiqueta)=0;
virtual Diagnostico *crearDiagnostico(ProblemaDeSalud pds, string descripcion)=0;
virtual void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<Medicamentos> listMedicamentos)=0;
virtual void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha)=0;
virtual void agregarDiagnostico(Diagnostico diagnostico)=0;
virtual set <DTCategoriaRep> listarRepresentaciones()=0;
virtual ~IRegistroMEdico() = default;
};
#endif