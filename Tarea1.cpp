#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>    // Para srand() y rand()
#include <chrono>     // Para std::this_thread::sleep_for
#include <mutex>
#include <algorithm>  // Para std::sort
#include <map>        // Para el podio
#include <iomanip>    // Para formateo de la salida (setw)

std::mutex mtx;  // Mutex para sincronizar la salida en la consola
std::vector<std::pair<int, int>> podio;  // Almacena el orden de llegada: (auto_id, tiempo total)
std::mutex podio_mtx;

class Auto {
public:
    Auto(int id, int total_distance) : id(id), distance_covered(0), total_distance(total_distance) {}

void run() {
    int total_time = 0;

    while (distance_covered < total_distance) {
        int advance = rand() % 11;  

        if (advance == 0) {
            advance++;
        }
        
        distance_covered += advance;
        
        // Simula un tiempo aleatorio de entre 100 y 500 ms
        int sleep_time = 100 + (rand() % 401);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        total_time += sleep_time;
        // Bloquear el mutex para proteger la salida
        {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Auto" << id << " avanza " << std::setw(2) << advance 
            << " metros (total: " << std::setw(3) << distance_covered << " metros)\n";
        }
        // Verificar si ha llegado a la meta
        if (distance_covered >= total_distance) {
            std::lock_guard<std::mutex> lock(mtx);
                {
                std::cout << "\033[1;32mAuto" << id << " avanza " << std::setw(2) << advance 
                << " metros y termina la carrera en el lugar " 
                << (podio.size() + 1) << "!\033[0m\n";
                }
                // Agregar el auto al podio
                std::lock_guard<std::mutex> podio_lock(podio_mtx);
                podio.push_back(std::make_pair(id, total_time));
                break;
        }
    }
}

int getId() const { return id; }

private:
    int id;
    int distance_covered;
    int total_distance;
};

// Función que simula la carrera
void start_race(int M, int N) {
    std::vector<Auto> autos;
    std::vector<std::thread> threads;
    // Inicializar autos
    for (int i = 1; i <= N; ++i) {
        autos.emplace_back(i, M);
    }
    // Iniciar hebras para cada auto
    for (int i = 0; i < N; ++i) {
        threads.emplace_back(&Auto::run, &autos[i]);
    }
    // Esperar a que todas las hebras terminen
    for (int i = 0; i < N; ++i) {
        threads[i].join();
    }
    // Mostrar podio
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "\nLugar    Auto\n";
        std::cout << "_____________________\n";
        for (size_t i = 0; i < podio.size(); ++i) {
            std::cout << std::setw(2) << (i + 1) << "        Auto" << podio[i].first << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    srand(time(nullptr));  // Inicializa la semilla para los números aleatorios
    
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <distancia> <numero_de_autos>\n";
        return 1;
    }
    
    int M = std::atoi(argv[1]);  // Convierte el primer argumento a entero (distancia)
    int N = std::atoi(argv[2]);  // Convierte el segundo argumento a entero (número de autos)
    
    if (M <= 0 || N <= 0) {
        std::cerr << "Error: No se pueden ingresar valores negativos o iguales a 0 para la distancia o el número de autos.\n";
        return 1;
    }
    std::cout << "Iniciando carrera con " << N << " autos y una distancia de " << M << " metros.\n";
    start_race(M, N);
    return 0;
}
