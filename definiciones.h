#define MAX_TIPO_USUARIO 2

// Colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum TipoUsuario{
    none,
    Tipo_Socio,
    Tipo_Medico,
    Tipo_Administrativo,
    Administrativo_defecto
};

enum EstadoConsulta{
   Reservada,
   Cancelada,
   Asistio,
   NoAsistio 
};