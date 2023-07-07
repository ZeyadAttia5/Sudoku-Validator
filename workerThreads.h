//
// Created by zeyad on 7/6/23.
//

#ifndef SUDOKOVALIDATOR_WORKERTHREADS_H
#define SUDOKOVALIDATOR_WORKERTHREADS_H

#include "pthread.h"

#define ROWS 0
#define COLS 1
#define SQRS 2
#define VALID 1
#define INVALID 0

#define ROW_COUNT 9
#define COL_COUNT 9
#define SQR_COUNT 9

typedef struct {
    int row;
    int col;
    int sqr;
    int valid;
} threadArgs;



void createWorkerThreads();

void *runnerRow(void *args);

void *runnerCol(void *args);

void *runnerSqr(void *args);

#endif //SUDOKOVALIDATOR_WORKERTHREADS_H
