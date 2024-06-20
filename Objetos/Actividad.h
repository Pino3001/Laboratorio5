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
    Socio *socioTiene;
    string nombreSocio;
    string ciSocio;
    Medico *medicoRealiza;
    string nombreMedico;
    string ciMedico;
    Historial *historialAsoc;

public:
    //Actividad();
    Actividad(Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio);
    //Actividad(Actividad &actividad);

    void setSocioTiene(Socio *socio);
    void setMedicoRealiza(Medico *medico);
    void setHistorialAsoc(Historial *historial);
    void setNombreSocio(string nombre);
    void setCiSocio(string ci);
    void setNombreMedico(string nombre);
    void setCiMedico(string ci);

    Socio *getSocioTiene();
    Medico *getMedicoRealiza();
    Historial *getHistorialAsoc();
    virtual string getNombreSocio()= 0;
    virtual string getCiSocio()=0;
    virtual string getNombreMedico()=0;
    virtual string CiMedico()=0;

    ~Actividad();
};
#endif
