/*
 * Debug-print helpers for matrices and collision counts.
 */

#ifndef PRINT_H
#define PRINT_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void printArray(unsigned int*  array, int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
	    printf("%u ", array[i*n+j]);
	}
	printf("\n");
    }

    printf("\n");
}

void printArray(DT*  array, int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
	    printf("%5.4f ", array[i*n+j]);
	}
	printf("\n");
    }

    printf("\n");
}

void printArray(DT** array, int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.4f ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

#endif
