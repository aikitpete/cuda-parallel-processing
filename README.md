# CUDA Parallel Processing

A repository for experimenting with parallel distance computation and collision detection for randomly generated spheres.

## What this repository contains

The project currently contains two experiment tracks:

- `experiments/cpu-baseline` — a CPU baseline that evaluates different in-memory layouts for sphere coordinates and pairwise distances.
- `experiments/gpu-cuda` — a CUDA-based implementation that moves distance computation and collision detection to the GPU.

## Why this project matters

This repository shows work beyond typical CRUD applications:

- data-parallel problem decomposition
- memory-layout experimentation
- CPU vs. GPU implementation trade-offs
- benchmarking-oriented engineering
- low-level C/C++ and CUDA work

## Repository layout

```text
experiments/
  cpu-baseline/
    src/            # source files for the CPU baseline
    scripts/        # benchmark scripts
    legacy/         # alternative implementation and build files
  gpu-cuda/
    src/            # CUDA/C++ source files
    scripts/        # benchmark scripts
    legacy/         # launcher/build artifacts
docs/               # project notes
LICENSE
```

## Methodology

I compared several memory layouts for sphere-collision detection to understand how data organization affects runtime.

### Test setup
- 100 runs per configuration
- Input sizes: N = 10, 50, 100, 200, 500, 1000, 2000, 5000
- Measured elapsed time from array initialization through full collision detection
- Used a custom `StopWatch` implementation because the provided version was incompatible; it preserves the same interface

### Layouts evaluated
- packed `XYZR`
- split `X, Y, Z, R`
- grouped `XYZ, R`
- row-major access
- column-major access

## Findings

The main takeaway was that **memory layout mattered, but not all seemingly “better” layouts produced meaningful gains**.

- Row-major layouts generally performed better for this workload
- Column-major variants underperformed because cached row data was fetched but not fully reused
- Several packed row-major representations performed similarly, suggesting that layout quality mattered more than micro-differences between otherwise cache-friendly formats

## Engineering takeaway

This experiment reinforced a practical lesson: in performance-sensitive code, **data layout and memory access patterns can matter as much as algorithm choice**, especially when cache behavior dominates runtime.