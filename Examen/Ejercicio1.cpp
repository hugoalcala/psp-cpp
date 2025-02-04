#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    } else if (pid == 0) {
        printf("Soy el proceso hijo. Mi PID es %d\n", getpid());
        printf("El PID de mi padre es %d\n", getppid());
    } else {
        printf("Soy el proceso padre. El PID de mi hijo es %d\n", pid);
        wait(NULL);
    }

    return 0;
}
