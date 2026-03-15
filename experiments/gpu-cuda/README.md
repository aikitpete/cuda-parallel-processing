# GPU CUDA Implementation

CUDA/C++ implementation for accelerating distance computation and collision detection across randomly generated spheres.

## Focus

This experiment demonstrates:

- GPU memory allocation and transfer
- CUDA kernel launches for pairwise geometry computation
- collision counting on the device
- CPU-side post-processing of kernel output

## Main files

- `src/main.cpp` — primary CUDA-enabled implementation
- `src/utils.cpp` — allocation and cleanup helpers
- `src/print.cpp` — debug-print utilities
- `src/stopwatch/*` — timing helper
