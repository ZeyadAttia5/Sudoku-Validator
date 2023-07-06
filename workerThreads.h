//
// Created by zeyad on 7/6/23.
//

#ifndef SUDOKOVALIDATOR_WORKERTHREADS_H
#define SUDOKOVALIDATOR_WORKERTHREADS_H

#include "pthread.h"
#define ROWS 0
#define COLS 1
#define SQRS 2

#define ROW_COUNT 9
#define COL_COUNT 9
#define SQR_COUNT 9

void createWorkerThreads(pthread_t threadArrays[3][ROW_COUNT]);
void *runner(void *args);

#endif //SUDOKOVALIDATOR_WORKERTHREADS_H
