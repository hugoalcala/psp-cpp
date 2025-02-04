#include <iostream>
#include <thread>

void mostrarmensaje() {
    std::cout << "Este es un hilo" << std::endl;
}

int main() {
    std::thread t(mostrarmensaje); 

    t.join();

    std::cout << "Este es el hilo principal" << std::endl;
    return 0;
}
