# CPU Baseline

Baseline C++ implementation for generating random spheres, computing pairwise distances, and detecting collisions.

## Focus

This experiment compares multiple data representations for the same geometry problem:

- packed coordinate arrays vs. split arrays
- packed vs. pointer-style distance storage
- row-major vs. column-major indexing

## Main files

- `src/main.cpp` — primary baseline implementation
- `src/stopwatch.*` — lightweight timing helper
