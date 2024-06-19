# Nombre del ejecutable
TARGET = programa

# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directorios de inclusión
INCLUDES = -I. -IObjetos -IControladores -IFabrica -IDatatypes

# Todos los archivos fuente organizados por directorio
SRCS = main.cpp \
       Objetos/Usuario.cpp \
       Objetos/CategoriaUsuario.cpp \
       Objetos/Socio.cpp \
       Objetos/Medico.cpp \
       Objetos/Administrativo.cpp \
       Objetos/Actividad.cpp \
       Objetos/Consulta.cpp \
       Objetos/Comun.cpp \
       Objetos/Emergencia.cpp \
       Objetos/Historial.cpp \
       Objetos/Diagnostico.cpp \
       Objetos/Tratamiento.cpp \
       Objetos/Quirúrgico.cpp \
       Objetos/Farmaco.cpp \
       Objetos/CategoríaProblemaSalud.cpp \
       Objetos/ProblemaDeSalud.cpp \
       Controladores/CUsuario.cpp \
       Controladores/CRegistroMedico.cpp \
       Fabrica/Fabrica.cpp \
       Datatypes/DTHora.cpp \
       Datatypes/DTFecha.cpp \
       Datatypes/DTDatosUsuario.cpp \
       Datatypes/DTHistorial.cpp \
       Datatypes/DTDiagnostico.cpp \
       Datatypes/DTTratamiento.cpp \
       Datatypes/DTReserva.cpp \
       Datatypes/DTConsulta.cpp \
       Datatypes/DTCategoriaRep.cpp \
       Datatypes/DTProblemaDeSalud.cpp

# Archivos objeto generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto: compilar todo y enlazar
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean