#define MAX_TIPO_USUARIO 2

// Colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
#ifndef TTIPOCONSULTA_ENUM
#define TTIPOCONSULTA_ENUM
enum TipoConsulta{
    Tipo_Emergencia,
    Tipo_Comun
};
#endif