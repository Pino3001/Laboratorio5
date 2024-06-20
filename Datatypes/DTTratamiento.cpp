#include "DTTratamiento.h"
#include "definiciones.h"

DTTratamiento::DTTratamiento() : descripcion(""), tipo(TipoTratamiento::Tipo_Farmaco), listMedicamentos(), nombreCirujano(""){
    DTFecha f;
    this->fechaCirujia = f;
}

DTTratamiento::DTTratamiento(string descripcion, TipoTratamiento trat, list<string> medicamentos)
    : descripcion(descripcion), tipo(trat), listMedicamentos(medicamentos), nombreCirujano("") {
        DTFecha fc;
        this->fechaCirujia = fc;
    }

DTTratamiento::DTTratamiento(string desc, TipoTratamiento t, const DTFecha fecha, string cirujano)
    : descripcion(desc), tipo(t), listMedicamentos(), fechaCirujia(fecha), nombreCirujano(cirujano) {}

// Getters
string DTTratamiento::getDescripcion()
{
    return descripcion;
}

TipoTratamiento DTTratamiento::getTipo()
{
    return tipo;
}

list<string> DTTratamiento::getListMedicamentos()
{
    return listMedicamentos;
}

DTFecha DTTratamiento::getFechaCirugia()const
{
    return fechaCirujia;
}

string DTTratamiento::getNombreCirujano()
{
    return nombreCirujano;
}