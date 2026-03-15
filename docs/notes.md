# Notes

## CPU baseline

The CPU implementation explores multiple storage strategies for:

- sphere coordinates (`xyz[N][3]`, `xyzr[N][4]`, or split `x/y/z/r` arrays)
- distance matrices (simulated contiguous arrays vs. pointer-based arrays)
- row-major vs. column-major access patterns

This makes the baseline useful for discussing cache behavior, contiguous memory, and representation trade-offs.

## GPU implementation

The CUDA implementation allocates device memory, copies generated sphere data to the GPU, launches kernels for pairwise distance computation, then performs collision detection from precomputed distances.

Key topics visible in the code:

- thread/block grid setup
- host-to-device copies
- pitched memory for packed sphere data
- host-side aggregation of collision counts
- manual lifecycle management of device buffers
