#include "DTTratamiento.h"
#include "definiciones.h"

DTTratamiento::DTTratamiento() : descripcion(""), tipo(TipoTratamiento::Tipo_Farmaco), listMedicamentos(){
    DTFecha f;
    this->fechaCirujia = f;
    DTDatosUsuario d;
    this->cirujano= d;

}

DTTratamiento::DTTratamiento(string descripcion, TipoTratamiento trat, list<string> medicamentos)
    : descripcion(descripcion), tipo(trat), listMedicamentos(medicamentos) {
        DTFecha fc;
        this->fechaCirujia = fc;
        DTDatosUsuario d;
        this->cirujano= d;
    }

DTTratamiento::DTTratamiento(string desc, TipoTratamiento t, const DTFecha fecha, DTDatosUsuario cirujano)
    : descripcion(desc), tipo(t), listMedicamentos(), fechaCirujia(fecha), cirujano(cirujano) {}

// Getters
string DTTratamiento::getDescripcion()const
{
    return descripcion;
}

TipoTratamiento DTTratamiento::getTipo()const
{
    return tipo;
}

list<string> DTTratamiento::getListMedicamentos()const
{
    return listMedicamentos;
}

DTFecha DTTratamiento::getFechaCirugia()const
{
    return fechaCirujia;
}

DTDatosUsuario DTTratamiento::getCirujano()const
{
    return cirujano;
}
