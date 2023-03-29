#include<iostream>

// Número de Hilos a Ejecutar
const int THREAD_COUNT = 2;

// Variables de Control
bool thread_state[THREAD_COUNT] = { false };    // Arreglo de estados de los hilos
int turn = 0;                                   // Siguiente hilo a ejecutarse
int shared_counter = 0;                         // Variable Compartida para simular la zona crítica

// Inicialización del Algoritmo 
int main() {
    // Ejecución de los hilos de forma concurrente o paralela
    start_threads();
    // Terminación del Algoritmo
    return 0;
}