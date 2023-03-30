#include<iostream>

// Número de Hilos a Ejecutar
const int THREAD_COUNT = 5;

// Variables de Control
bool thread_state[THREAD_COUNT] = { false };    // Arreglo de estados de los hilos
int turn = 0;                                   // Siguiente hilo a ejecutarse
int shared_counter = 0;                         // Variable Compartida para simular la zona crítica

// Inicialización de la ejecución de los hilos
void start_threads() {
    // Ejecutamos la cantidad de hilos especificados
    for (int i = 0; i < THREAD_COUNT; i++) {
        bool is_completed = false;
        std::cout << "-> Thread " << i << " execution initialized." << std::endl;
        do {
            // Sección de Entrada
            // Cambiamos el estado a verdadero puesto que queremos entrar a la zona crítica
            thread_state[i] = true;
            turn = (i + 1) % THREAD_COUNT;
            // Esperamos mientras el hilo sale de la zona crítica
            while (thread_state[(i + 1) % THREAD_COUNT] && turn == (i + 1) % THREAD_COUNT) {
                std::cout << "\t⌛ Waiting for a turn to enter..." << std::endl;
            }
            // Zona Crítica
            std::cout << "\t🛠 We do our thing inside the critical zone..." << std::endl;
            // Una vez dentro de la zona crítica se realizan las operaciones correspondientes
            ++shared_counter;
            is_completed = true;
            // Se actualiza el estado del hilo
            thread_state[i] = false;
            // Resto de la Ejecución
        } while (!is_completed);
        std::cout << "<- Thread " << i << " execution finished." << std::endl;
    }
}

// Inicialización del Algoritmo 
int main() {
    // Ejecución de los hilos de forma concurrente o paralela
    std::cout << "Started Execution" << std::endl;
    start_threads();
    // Terminación del Algoritmo
    std::cout << "Finished Execution" << std::endl;
    return 0;
}