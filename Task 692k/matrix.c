#include "matrix.h"
#include <stdlib.h>



void mat_output(float mat[max_size][max_size], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void mat_random(float mat[max_size][max_size], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            mat[i][j] = 1.0 * rand() / RAND_MAX * 200 - 100;
        }
    }
}

float mat_max(float mat[max_size][max_size], unsigned n){
    float max_mat = mat[0][n];
    for (unsigned i = 0; i < n; ++i){
        for (unsigned j = 0; j < n; ++j){
            if ( (j >= n - i - 1) && (max_mat > mat[i][j]) )
            max_mat = mat[i][j];
        }
    } 
    return max_mat;  
}