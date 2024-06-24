#include "DTConsulta.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include "iostream"
#include <iomanip>
using namespace std;

DTConsulta::DTConsulta() : motivo(""), tipo(TipoConsulta::Tipo_Comun)
{
    DTDatosUsuario socio;
    this->socio = socio;
    DTDatosUsuario medico;
    this->medico = medico;
    DTFecha fc;
    this->fechaConsulta = fc;
    DTFecha fr;
    this->fechaReserva = fr;
    DTHora hc;
    this->horaConsulta = hc;
}
DTConsulta::DTConsulta(DTDatosUsuario socio, DTDatosUsuario medico, list<DTDiagnostico> diagnosticos, string motivo, const DTFecha fechaConsul, const DTHora horaConsul, const DTFecha fechaReserva, TipoConsulta tipo)
    : socio(socio), medico(medico), diagnosticos(diagnosticos), motivo(motivo), fechaConsulta(fechaConsul), horaConsulta(horaConsul), fechaReserva(fechaReserva), tipo(tipo) {}

DTDatosUsuario DTConsulta::getSocio() const
{
    return this->socio;
}
DTDatosUsuario DTConsulta::getMedico() const
{
    return this->medico;
}

string DTConsulta::getMotivo() const
{
    return this->motivo;
}

DTFecha DTConsulta::getFechaConsulta() const
{
    return this->fechaConsulta;
}

DTHora DTConsulta::getHoraConsulta() const
{
    return this->horaConsulta;
}
DTFecha DTConsulta::getFechaReserva() const
{
    return this->fechaReserva;
}

TipoConsulta DTConsulta::getTipo() const
{
    return this->tipo;
}

list<DTDiagnostico> DTConsulta::getDiagnosticos() const
{
    return this->diagnosticos;
}

void DTConsulta::mostrarDTConsulta() const
{

    cout << "\n";
    cout << setw(50) << setfill('_') << "\n\n";
    cout << "  C.I Socio: " << this->socio.getCi() << "\n";
    cout << "  Socio: " << this->socio.getNombre() << " " << this->socio.getApellido() << "\n";
    cout << "  Medico: " << this->medico.getNombre() << this->medico.getApellido() << "\n";
    cout << "  Fecha de Consulta: ";
    this->fechaConsulta.imprimirDTFecha();
    cout << "  Hora de Consulta: ";
    this->horaConsulta.imprimirDTHora();
    cout << "  Tipo de Consulta: ";
    if (this->tipo == TipoConsulta::Tipo_Comun)
    {
        cout << "Consulta Comun. \n";
    }
    else
    {
        cout << "Consulta Emergencia. \n";
    }
    cout << setw(50) << setfill('_') << "\n";
}

void DTConsulta::mostrarReservas() const
{

    cout << "\n";
    cout << setw(50) << setfill('_') << "\n\n";
    cout << "  Socio: " << this->socio.getNombre() << " " << this->socio.getApellido() << "\n";
    cout << "  Medico: " << this->medico.getNombre() << this->medico.getApellido() << "\n";
    cout << "  C.I Medico: " << this->medico.getCi() << "\n";
    cout << "  Fecha de Reserva: ";
    this->fechaReserva.imprimirDTFecha();
    cout << "  Fecha de Consulta: ";
    this->fechaConsulta.imprimirDTFecha();
    cout << "  Hora de Consulta: ";
    this->horaConsulta.imprimirDTHora();
    cout << setw(50) << setfill('_') << "\n";
}

void DTConsulta::mostrarVersionHistorial() const
{
    cout << "\n";
    cout << setw(50) << setfill('_') << "\n\n";
    cout << "  Medico Tratante: " << this->medico.getNombre() << " " << this->medico.getApellido() << "\n";
    cout << "  Fecha de Consulta: ";
    this->fechaConsulta.imprimirDTFecha();
    cout << "  Hora de Consulta: ";
    this->horaConsulta.imprimirDTHora();
    cout << "  Tipo de Consulta: ";
    if (this->tipo == TipoConsulta::Tipo_Comun)
    {
        cout << "Consulta Comun. \n";
        cout << "  Fecha Reserva: ";
        this->fechaReserva.imprimirDTFecha();
    }
    else
    {
        cout << "Consulta Emergencia. \n";
        cout << "\tMotivo de consulta: \n"
             << this->motivo << "\n";
    }
    if (!this->diagnosticos.empty())
    {
        cout << setw(50) << setfill('_') << "\n";
        cout << "\tDiagnosticos: \n";

        for (DTDiagnostico di : this->diagnosticos)
        {
            cout << "\t\tDescripcion: " << di.getDescripcion() << "\n";
            cout << "\t\tProblemas de Salud:\n";
            for (DTProblemaDeSalud pds : di.getPDeSalud())
            {
                cout << "\t\t\t" << pds.getCodigo() << " - " << pds.getEtiqueta() << "\n";
            }
            cout << "\t\tTratamientos:\n";
            for (DTTratamiento tra : di.getTratamientos())
            {
                bool esQuirurjico = tra.getTipo() == TipoTratamiento::Tipo_Quirurjico;
                if (esQuirurjico)
                    cout << "\t\t\tTipo: Quirurjico\n";
                else
                    cout << "\t\t\tTipo: Farmaco\n";
                cout << "\t\t\tDescripcion: " << tra.getDescripcion() << "\n";
                if (esQuirurjico)
                {
                    cout << "\t\t\tFecha cirugia: ";
                    tra.getFechaCirugia().imprimirDTFecha();
                    cout << "\t\t\tCirujano: " << tra.getCirujano().getNombre() << " " << tra.getCirujano().getApellido() << "\n";
                }
                else
                {
                    cout << "\t\t\tMedicamentos:\n";
                    for (string medicamento : tra.getListMedicamentos())
                    {
                        cout << "\t\t\t\t" << medicamento << "\n";
                    }
                }
            }
        }
    }
    else
    {
        cout << "\t\nNo existen diagnosticos Asociados a la Consulta.\n";
    }
    cout << setw(50) << setfill('_') << "\n";
}
