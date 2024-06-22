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
#include <map>
#include "definiciones.h"
#include "DTCategoriaRep.h"

class IRegistroMedico
{
public:
    // Todos los metodos del controlador
    virtual list<DTConsulta> mostrarConsultas(const DTFecha fechaHoy) = 0;
    virtual void registroConsulta(string ci, string ciMedico, const DTFecha fechaHoy) = 0;
    virtual list<DTCategoriaRep> mostrarDatosCategorias() = 0;
    virtual void altaCategoriaRepresentacion(string id, string descripcion) = 0;
    virtual void altaProblemaDeSalud(string id, string codigo, string etiqueta) = 0;
    virtual void reservaNuevaConsulta(string ciMedico, string ciSocio, const DTFecha fechaConsulta, const DTFecha fecReserva, const DTHora horaCosn) = 0;
    virtual void altaDiagnosticoConsulta(map<string, map<string, string>> *problAsoc, string descripDiagnostico, bool esQuirurgico, bool esFarmaco, list<string> *medeicamentos, string descripFarmaco, const DTFecha fechaCirujia, string ciMedicoCirujano, string descripcionQuirurji) = 0;
    virtual void seleccionarConsulta(string ciSocio, string ciMedico, const DTFecha fechaCons) = 0;
    virtual void crearHistorialPaciente()=0;
    virtual list<DTHistorial> obtenerHistorialPaciente(string ciSocio)=0;
    virtual void registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, DTHora hora, string descrpcion) = 0;
    virtual list<DTCategoriaRep> listarRepresentacionesEstandarizadas() = 0;
    

    virtual void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> listMedicamentos) = 0;
    virtual void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha) = 0;
    virtual void agregarDiagnostico(Diagnostico diagnostico) = 0;

    virtual ~IRegistroMedico() = default;
};
#endif