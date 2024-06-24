# Nombre del ejecutable
TARGET = programa

# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -std=c++11 -Wall -Wextra

# Flags para depuración (agrega -g para incluir símbolos de depuración)
DEBUGFLAGS = -g

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
       Objetos/Diagnostico.cpp \
       Objetos/Tratamiento.cpp \
       Objetos/Quirurgico.cpp \
       Objetos/Farmaco.cpp \
       Objetos/CategoriaProblemaSalud.cpp \
       Objetos/ProblemaDeSalud.cpp \
       Controladores/CUsuario.cpp \
       Controladores/CRegistroMedico.cpp \
       Fabrica/Fabrica.cpp \
       Datatypes/DTHora.cpp \
       Datatypes/DTFecha.cpp \
       Datatypes/DTDatosUsuario.cpp \
       Datatypes/DTDiagnostico.cpp \
       Datatypes/DTTratamiento.cpp \
       Datatypes/DTConsulta.cpp \
       Datatypes/DTCategoriaRep.cpp \
       Datatypes/DTProblemaDeSalud.cpp

# Archivos objeto generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto: compilar todo y enlazar
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	@echo "Enlazando $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)
	@echo "Ejecutable $(TARGET) generado."
	@$(MAKE) clean-objects

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp
	@echo "Compilando $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regla para limpiar los archivos objeto generados
clean-objects:
	@rm -f $(OBJS)

# Regla para limpiar todos los archivos generados
clean: clean-objects
	@rm -f $(TARGET)

# Regla para depurar: muestra las variables SRCS y OBJS
print-vars:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"

.PHONY: all clean clean-objects print-vars