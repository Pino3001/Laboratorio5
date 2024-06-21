#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>
class Historial;
class Usuario;
class Medico;
class Socio;
using namespace std;

class Actividad
{
private:
    Socio *socioConsulta;
    Medico *medicoRealiza;
    Historial *historialAsoc;

public:
    //Actividad();
    Actividad(Socio *socio, Medico *medico);
    //Actividad(Actividad &actividad);

    void setSocioConsulta(Socio *socio);
    void setMedicoRealiza(Medico *medico);
    void setHistorialAsoc(Historial *historial);

    Socio *getSocioConsulta();
    Medico *getMedicoRealiza();

    string cedulaSocio();
    string cedulaMedico();
    string nombreSocio();
    string nombreMedico();

    virtual Historial *getHistorialAsoc()=0;



    ~Actividad();
};
#endif
