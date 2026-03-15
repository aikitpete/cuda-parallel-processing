/*
 * Lightweight wall-clock timer utility.
 */

#include "stopwatch.h"
#include <iostream>
using namespace std;

StopWatch::StopWatch() {
    
}

/**
 * Marks end time
 */
void StopWatch::stop() {
    gettimeofday(&t2, NULL);
    stopTime = t2.tv_sec + (t2.tv_usec / 1000000.0);
}

/**
 * Marks start time
 */
void StopWatch::start() {
    gettimeofday(&t1, NULL);
    startTime = t1.tv_sec + (t1.tv_usec / 1000000.0);
}

double StopWatch::elapsedTime() {
    return stopTime - startTime;
}
