#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // pour sleep()
#include <omp.h>

// Déclaration des verrous pour les ressources
omp_lock_t lockA, lockB, lockC;

// Fonction qui simule une tâche
void execute_task(char* resource, int duration, omp_lock_t* lock) {
    
    // 🔒 Verrouillage de la ressource (exclusivité)
    omp_set_lock(lock);

    printf("Thread %d utilise Ressource %s pendant %d sec\n",
           omp_get_thread_num(), resource, duration);

    sleep(duration);  // simulation de la tâche

    printf("Thread %d libère Ressource %s\n",
           omp_get_thread_num(), resource);

    // 🔓 Libération de la ressource
    omp_unset_lock(lock);
}

int main() {

    // Initialisation des verrous
    omp_init_lock(&lockA);
    omp_init_lock(&lockB);
    omp_init_lock(&lockC);

    double start = omp_get_wtime(); // début chrono

    #pragma omp parallel num_threads(3)
    {
        int id = omp_get_thread_num();

        // Chaque thread exécute une séquence différente
        if (id == 0) {
            // Séquence 1
            execute_task("A", 2, &lockA);
            execute_task("B", 3, &lockB);
            execute_task("C", 1, &lockC);
        }
        else if (id == 1) {
            // Séquence 2
            execute_task("A", 1, &lockA);
            execute_task("B", 2, &lockB);
            execute_task("C", 4, &lockC);
        }
        else if (id == 2) {
            // Séquence 3
            execute_task("A", 3, &lockA);
            execute_task("B", 1, &lockB);
            execute_task("C", 2, &lockC);
        }
    }

    double end = omp_get_wtime(); // fin chrono

    printf("Temps total d'execution: %f sec\n", end - start);

    // Destruction des verrous
    omp_destroy_lock(&lockA);
    omp_destroy_lock(&lockB);
    omp_destroy_lock(&lockC);

    return 0;
}