# Tarea1_OS - Carrera de Autos Multihilo

Este proyecto simula una carrera de autos utilizando múltiples hilos en C++. Cada auto avanza aleatoriamente en intervalos de tiempo hasta completar una distancia determinada. El resultado de la carrera se muestra en la consola y se ordena en un podio al final.

## Requisitos

- **Compilador C++**: Se recomienda un compilador compatible con C++11 o superior (por ejemplo, g++).
- **Make**: Se necesita `make` para automatizar la compilación.
- **Sistema operativo**: El código ha sido probado en sistemas basados en Linux, pero debería funcionar en cualquier sistema con soporte para hilos en C++ (Windows, macOS, etc.).

## Compilación

Para compilar el código usando `make`, simplemente ejecuta el siguiente comando en la carpeta donde se encuentra el archivo `Makefile`:

# Instrucciones para ejecutar el programa `carrera_autos`

## Requisitos previos
Antes de ejecutar el programa, asegúrate de contar con los siguientes archivos:
- `Makefile`
- `Tarea1.cpp`
  
## Pasos para descargar y ejecutar

1. **Descargar los archivos**  
   - Descarga los archivos usando `wget` o directamente desde GitHub.

2. **Abrir la terminal**  
   - Dirígete a la carpeta donde descargaste los archivos.
   - Para verificar que estás en el directorio correcto, usa el comando:
     ```bash
     ls
     ```
     Esto debería mostrarte los archivos `Makefile` y `Tarea1.cpp`.

3. **Compilar el programa**  
   - Ejecuta el comando para compilar el programa:
     ```bash
     make
     ```
   - Valida que se haya creado el ejecutable usando `ls`.

4. **Ejecutar el programa**  
   - Ejecuta el siguiente comando para correr el programa:
     ```bash
     ./carrera_autos M N
     ```
   - Donde:
     - `M` es la cantidad de metros.
     - `N` es la cantidad de autos.
   
   - Ejemplo:
     ```bash
     ./carrera_autos 100 3
     ```

5. **Limpiar archivos**  
   - Si deseas eliminar los archivos generados durante la compilación, ejecuta:
     ```bash
     make clean
     ```

Este comando eliminará los archivos ejecutables creados durante la compilación.


