#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <string>
#include "DTFecha.h"
#include "DTHora.h"
using namespace std;

class DTReserva
{
private:
    string idConsulta;
    string nombre;
    string ci;
    string medico;
    DTFecha fechaReserva;
    DTFecha fechaConsulta;
    DTHora horaConsulta;

public:
    DTReserva();
    DTReserva(string idConsulta, string nombre, string ci, string medico, DTFecha fechaReserva, DTFecha fechaConsulta, DTHora horaConsulta);
    DTReserva(DTReserva &dtr);

    string getIdConsulta();
    string getNombre();
    string getCi();
    string getMedico();
    DTFecha getFechaReserva();
    DTFecha getFechaConsulta();
    DTHora getHoraConsulta();

    void mostrarDatosReserva();

    ~DTReserva();
};
#endif