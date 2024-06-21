#include "definiciones.h"
#ifndef TIPOUARIO_ENUM
#define TIPOUARIO_ENUM
enum TipoUsuario{
    UNKNOWN,
    Tipo_Socio,
    Tipo_Medico,
    Tipo_Administrativo,
    Administrativo_defecto,
    ERROR
};
#endif
#ifndef ESTADOCONSULTA_ENUM
#define ESTADOCONSULTA_ENUM
enum EstadoConsulta{
   Reservada,
   Cancelada,
   Asistio,
   NoAsistio 
};
#endif
#ifndef TIPOTRATAMIENTO_ENUM
#define TIPOTRATAMIENTO_ENUM
enum TipoTratamiento{
    Tipo_Farmaco,
    Tipo_Quirurjico
};
#endif