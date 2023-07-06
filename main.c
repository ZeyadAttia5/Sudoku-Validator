#include <stdio.h>
#include "workerThreads.h"




int main() {
    pthread_t workerThreads[3][ROW_COUNT];
    createWorkerThreads(workerThreads);
    return 0;
}
