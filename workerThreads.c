//
// Created by zeyad on 7/6/23.
//

#include "workerThreads.h"
#include "pthread.h"

void createWorkerThreads(pthread_t threadArrays[3][ROW_COUNT]) {

    pthread_attr_t attrs;
    pthread_attr_init(&attrs);

    for (int row = 0; row < ROW_COUNT; row++) {
        int args[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        pthread_create(&threadArrays[ROWS][row], &attrs, runner, &args[row]);
    }

    for (int col = 0; col < COL_COUNT; col++) {
        int args[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        pthread_create(&threadArrays[COLS][col], &attrs, runner, &args[col]);
    }

    for (int sqrs = 0; sqrs < SQR_COUNT; sqrs++) {
        int args[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        pthread_create(&threadArrays[ROWS][sqrs], &attrs, runner, &args[sqrs]);
    }

    //wait for the threads to join
    for (int row = 0; row < ROW_COUNT; row++) {
        pthread_join(threadArrays[ROWS][row], NULL);
    }
    for (int col = 0; col < COL_COUNT; col++) {
        pthread_join(threadArrays[COLS][col], NULL);
    }
    for (int sqrs = 0; sqrs < SQR_COUNT; sqrs++) {
        pthread_join(threadArrays[SQRS][sqrs], NULL);
    }
}

void *runner(void *args) {
    int *argI = (int *) args;
    printf("in thread: %i\n", *argI);
    if (*argI == 8)
        printf("\n");
}