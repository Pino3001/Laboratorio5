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
    Diagnostico* diagnosticoMem;
    map<string, CategoriaProblemaSalud *> *categoriasProblemas;
    map<DTFecha, list<Actividad *>> *memActividades;

    CRegistroMedico();

public:
    static CRegistroMedico *getInstance();

    void addMemActividad(Actividad *act, DTFecha fecha);
    list<DTConsulta> mostrarConsultas(const DTFecha fechaHoy);
    void registroConsulta(string ci, string ciMedico, const DTFecha fechaHoy);
    void cancelarReservaConsuta(string ci, string ciMedico, const DTFecha fechaConsulta);
    list<DTCategoriaRep> mostrarDatosCategorias();
    void altaCategoriaRepresentacion(string id, string descripcion);
    void altaProblemaDeSalud(string id, string codigo, string etiqueta);
    void reservaNuevaConsulta(string ciMedico, string ciSocio, const DTFecha fechaConsulta, const DTFecha fecReserva,const DTHora horaCosn);
    void altaDiagnosticoConsulta(map<string, pair<string, string>> problAsoc, string descripDiagnostico, bool esQuirurgico, bool esFarmaco, list<string> *medeicamentos, string descripFarmaco, const DTFecha fechaCirujia, string ciMedicoCirujano, string descripcionQuirurji);
    void seleccionarConsulta(string ciSocio, string ciMedico, const DTFecha fechaCons);
    list<DTConsulta> obtenerHistorialPaciente(string ciSocio);
    void registroConsultaEmergencia(string ci, string ciMedico, const DTFecha fecha, const DTHora hora, string descrpcion);
    list<DTCategoriaRep> listarRepresentacionesEstandarizadas();

    void agregarTratamientoFarmaco(string descripcion, list<string> * listMedicamentos);
    void agregarTratamientoQuirurgico(string ciMedicoCirujano, string descripcion, DTFecha fecha);
    void agregarDiagnostico(map<string, list<string>> problAsoc, string descripcion);

    ~CRegistroMedico();
};
#endif
