#include "Socio.h"

#include "CategoriaUsuario.h"
#include "Actividad.h"
#include "Medico.h"
// #include "Historial.h"

#include <list>
#include <string>
using namespace std;
// Constructores
Socio ::Socio(Usuario *usr) : CategoriaUsuario(usr)
{
    this->cantConsultas = 0;

    list<Actividad *> *actSocio = new list<Actividad *>;
    this->actividadesSocio = actSocio;
    list<Medico *> *medConsult = new list<Medico *>;
    this->medicosConsultados = medConsult;
    list<Historial *> *histSocio = new list<Historial *>;
    this->historialSocio = histSocio;
}

Socio ::Socio(Socio &socio, CategoriaUsuario &catUsr): CategoriaUsuario(catUsr)
{
    this->cantConsultas = socio.getCantConsultas();

    for (Actividad *ac : socio.getActividadesSocio())
    {
        this->actividadesSocio->push_back(ac);
    }
    for (Medico *mc : socio.getMedicosConsultados())
    {
        this->medicosConsultados->push_back(mc);
    }
    for (Historial *hs : socio.getHistorialSocio())
    {
        this->historialSocio->push_back(hs);
    }
}

// Setters
void Socio ::setCantConsultas(int cantConsultas)
{
    this->cantConsultas = cantConsultas;
}

void Socio ::setActividadesSocio(list<Actividad *> *actividadesSocio)
{
    this->actividadesSocio = actividadesSocio;
}
void Socio ::setMedicosConsultados(list<Medico *> *medicosConsultados)
{
    this->medicosConsultados = medicosConsultados;
}
void Socio ::setHistorialSocio(list<Historial *> *historialSocio)
{
    this->historialSocio = historialSocio;
}

// Getters
int Socio ::getCantConsultas()
{
    return this->cantConsultas;
}
list<Actividad *> Socio ::getActividadesSocio()
{
    return this->actividadesSocio;
}
list<Medico *> Socio ::getMedicosConsultados()
{
    return this->medicosConsultados;
}
list<Historial *> Socio ::getHistorialSocio()
{
    return this->historialSocio;
}

string Socio ::verNombre(){
    return this->usuarioVinculado->getNombre();
}

string Socio ::verCi(){
    return this->usuarioVinculado->getCedula();
}
// Para implementar
void addActividad(Actividad actividad);

string verCi();
TipoUsuario Socio :: obtenerTipo(){}
Consulta buscarConsulta(string idConsulta);
void registrarAsistencia(EstadoConsulta estC);
Actividad AltaConsultaEmergencia(DTFecha fecha, DTHora hora, string descripcion);
set(DTReserva) mostrarReservasActivas();
void cancelarReserva(string idConsulta);
set(DTHistorial) mostrarHistorialPorMedico(Usuario usr);

~Socio();