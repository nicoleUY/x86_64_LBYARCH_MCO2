# x86_64_LBYARCH_MCO2

## PROOF OF CORRECTNESS


## COMPARATIVE EXECUTION TIME

### LAPTOP SPECS

| Component        | Laptop #1                             | Laptop #2                                      |
|------------------|---------------------------------------|------------------------------------------------|
| CPU              | Intel(R) Core(TM) i7-10710U @1.10GHz | 11th Gen Intel(R) Core(TM) i7-1165G7 @2.80GHz |
| GPU              | Intel(R) UHD Graphics                 | Intel(R) Iris(R) Xe Graphics & NVIDIA GeForce MX330 \
| RAM              | 16.0 GB                               | 16.0 GB                                        |
| Cores            | 6                                     | 4                                              |
| Clock Speed      | 1608 Mhz                              | 2.80 GHz                                       |


### DEBUG

#### Table 1.
| DEBUG    | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000233 | 0.002767 | 0.050767 | 0.741000 | 1.555000 | 3.586967 |
| ASM      | 0.000000 | 0.000067 | 0.001767 | 0.021400 | 0.343433 | 0.808533 | 1.575333 |



### RELEASE
#### Table 2.
| RELEASE  | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000100 | 0.001533 | 0.026133 | 0.323233 | 0.819367 | 3.110133 |
| ASM      | 0.000000 | 0.000067 | 0.001467 | 0.021267 | 0.345300 | 0.943600 | 1.722400 |


## SHORT ANALYSIS OF PERFORMANCE OF KERNELS

- In Table 1, it can be seen that the asm kernel consistently performs much faster than the c kernel. 
- As expected, as the vector size increases, the run time also increases
- In Table 2, it can be seen that performance of the kernels are nearer in value. 
- However, in Table 2, when the size of the vector reaches 2^30, the difference is more drastic
