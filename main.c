#include <stdio.h>
#include "workerThreads.h"
extern int validThreads[3][ROW_COUNT];

int main() {

    createWorkerThreads();
    unsigned long valid = VALID;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 9; ++j) {
            valid &= validThreads[i][j];
        }
    }
    if (valid) {
        printf("The sudoku solution is valid\n");
    } else
        printf("The sudoku solution is Invalid\n");
    return 0;
}
