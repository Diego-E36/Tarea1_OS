# Compilador a utilizar
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -pthread

# Archivos fuente
SRCS = Tarea1.cpp

# Archivo ejecutable
TARGET = carrera_autos

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Limpiar archivos binarios generados
clean:
	rm -f $(TARGET)

