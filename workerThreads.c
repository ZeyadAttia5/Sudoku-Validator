//
// Created by zeyad on 7/6/23.
//

#include <malloc.h>
#include "workerThreads.h"
#include "pthread.h"
#include "sudoku.h"

pthread_t threadArrays[3][ROW_COUNT];
int validThreads[3][ROW_COUNT];

void createWorkerThreads(void) {

    pthread_attr_t attrs;
    pthread_attr_init(&attrs);


    for (int row = 0; row < ROW_COUNT; row++) {
        threadArgs *args = (threadArgs *) malloc(sizeof(threadArgs));
        args->col = 0;
        args->sqr = 0;
        args->row = row;
        pthread_create(&threadArrays[ROWS][row], &attrs, runnerRow, args);
    }

    for (int col = 0; col < COL_COUNT; col++) {
        threadArgs *args = (threadArgs *) malloc(sizeof(threadArgs));
        args->col = col;
        args->sqr = 0;
        args->row = 0;
        pthread_create(&threadArrays[COLS][col], &attrs, runnerCol, args);
    }

    int square_count = 0;
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            threadArgs *args = (threadArgs *) malloc(sizeof(threadArgs));
            args->row = row;
            args->col = col;

            args->sqr = square_count++;
            pthread_create(&threadArrays[SQRS][args->sqr], &attrs, runnerSqr, args);
        }
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

void *runnerRow(void *input) {
    threadArgs *args = (threadArgs *) input;
    args->valid = VALID;

    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < ROW_COUNT; ++i) {
        int curr_digit = sudoku[args->row][i];
        if (nums[curr_digit] == 1) {
            args->valid = INVALID;
        } else {
            nums[curr_digit] = 1;
            (args->valid) &= VALID;
        }
    }
    if (args->valid == VALID) {
        validThreads[ROWS][args->row] = VALID;
    }
    free(args);
    pthread_exit(NULL);
}

void *runnerCol(void *input) {
    threadArgs *args = (threadArgs *) input;
    args->valid = VALID;

    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < COL_COUNT; ++i) {
        int curr_digit = sudoku[i][args->col];
        if (nums[curr_digit] == 1) {
            args->valid = INVALID;
        } else {
            nums[curr_digit] = 1;
            (args->valid) &= VALID;
        }
    }
    if (args->valid == VALID) {
        validThreads[COLS][args->col] = VALID;
    }
    free(args);
    pthread_exit(NULL);
}

void *runnerSqr(void *input) {
    threadArgs *args = (threadArgs *) input;
    args->valid = VALID;
    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int row_args = args->row;
    int col_args = args->col;

    for (int row = row_args; row < row_args + 3; ++row) {
        for (int col = col_args; col < col_args + 3; ++col) {
            int curr_digit = sudoku[row][col];
            if (nums[curr_digit] == 1) {
                args->valid = INVALID;
            } else {
                nums[curr_digit] = 1;
                (args->valid) &= VALID;
            }
        }
    }
    if(args->valid == VALID){
        validThreads[SQRS][args->sqr] = VALID;
    }

    free(args);
    pthread_exit(NULL);
}