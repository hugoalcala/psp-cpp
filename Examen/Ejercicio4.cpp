#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t sem;

void secionCritica(int id) {
    sem_wait(&sem); // Bloquea el acceso

    std::cout << "Hilo " << id << " entrando.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simula trabajo
    std::cout << "Hilo " << id << " saliendo.\n";

    sem_post(&sem); // Libera el semáforo
}

int main() {
    sem_init(&sem, 0, 1); // Inicializa el semáforo con valor 1 (mutex)

    std::thread t1(secionCritica, 1);
    std::thread t2(secionCritica, 2);

    t1.join();
    t2.join();

    sem_destroy(&sem); // Destruye el semáforo

    return 0;
}
