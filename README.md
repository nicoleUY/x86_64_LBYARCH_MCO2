# x86_64_LBYARCH_MCO2

## COMPARATIVE EXECUTION TIME (IN SECONDS)

### LAPTOP SPECS

| Component        | Laptop #1                             | Laptop #2                                      |
|------------------|---------------------------------------|------------------------------------------------|
| CPU              | Intel(R) Core(TM) i7-10710U @1.10GHz  | Intel(R) Core(TM) i7-1165G7 @2.80GHz           |
| GPU              | Intel(R) UHD Graphics                 | Intel(R) Iris(R) Xe Graphics & NVIDIA GeForce MX330 |
| RAM              | 16.0 GB                               | 16.0 GB                                        |
| Cores            | 6                                     | 4                                              |

### DEBUG

#### Table 1. Device 1 Debug Mode
| DEBUG    | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000233 | 0.002767 | 0.050767 | 0.741000 | 1.555000 | 3.586967 |
| ASM      | 0.000000 | 0.000067 | 0.001767 | 0.021400 | 0.343433 | 0.808533 | 1.575333 |


#### Table 2. Device 2 Debug Mode
| DEBUG    | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000200 | 0.003100 | 0.041900 | 0.639533 | 1.279667 | 4.082100 |
| ASM      | 0.000000 | 0.000067 | 0.001133 | 0.017567 | 0.283033 | 0.569933 | 1.520200 |



### RELEASE

#### Table 3. Device 1 Release Mode
| RELEASE  | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000100 | 0.001533 | 0.026133 | 0.323233 | 0.819367 | 3.110133 |
| ASM      | 0.000000 | 0.000067 | 0.001467 | 0.021267 | 0.345300 | 0.943600 | 1.722400 |


#### Table 4. Device 2 Release Mode
| DEBUG    | 2^11     | 2^16     | 2^20     | 2^24     | 2^28     | 2^29     | 2^30     |
|----------|----------|----------|----------|----------|----------|----------|----------|
| C        | 0.000000 | 0.000100 | 0.001533 | 0.020600 | 0.290967 | 0.574667 | 1.246300 |
| ASM      | 0.000000 | 0.000133 | 0.001567 | 0.019833 | 0.284067 | 0.567400 | 1.212267 |

## SHORT ANALYSIS OF PERFORMANCE OF KERNELS

The provided results show performance differences between C and assembly language kernels, and between debug and release modes.

Impact of Debug vs Release Mode:

Running the code in debug mode consistently resulted in slower execution times compared to release mode. This is because debuggers prioritize generating code that's easy to understand and troubleshoot, even if it means sacrificing some efficiency. Debuggers might also insert extra checks to verify memory access and variable values, adding to the execution time. In contrast, release mode leverages compiler optimizations to generate more efficient machine code, often using fewer instructions and taking advantage of processor features. This explains the noticeable performance improvement for both C and assembly kernels in release mode across both devices.

Assembly vs C Language Performance:

Assembly language offered fine-grained control, allowing for direct manipulation of registers and instructions. This can lead to highly optimized code for specific tasks like the dot product calculation in this case. However, assembly code comes at the cost of being less portable (tied to a specific processor architecture, in this case x86_64 for Windows) and harder to write and maintain compared to C.

The results confirmed these expectations. Initially, the assembly kernel consistently outperformed the C kernel, suggesting the assembly code effectively leveraged processor instructions for the dot product operation. However, later in release mode, the gap between C and assembly narrowed significantly. For smaller vector sizes, the C kernel even performed slightly better. 

This could be due to several factors:

    Compiler Optimizations: Using release mode optimized the efficiency of the C code, allowing it to be more efficient that ASM at times.
    Measurement Overhead: Timing measurements can introduce slight variations, especially for very short execution times on small vector sizes.

Additional Considerations:

The execution time increased for both C and assembly kernels as the vector size grew. This is simply because more iterations are needed to calculate the dot product for larger vectors. Additionally, hardware differences between the devices, such as processor models (i7-10710U vs i7-1165G7), clock speeds, and number of cores, can also contribute to performance variations. While not provided in the data, the number of cores could significantly impact performance, especially for larger vector sizes that could benefit from parallelization.

Overall, the assembly kernel generally performed better, but the C compiler could be surprisingly competitive on certain hardware configurations, especially with optimizations in release mode. 

## PROOFS OF CORRECTNESS

### Note: Using the C kernel as a check, the ASM kernel does the correct expected operations and gets the same value. However, checking both kernels with calculators online show that there may be discrepancies that are affected by the way rounding occurs in the program.

#### Proof 1
![Test 1](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test1.png)

#### Proof 2
![Test 2](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test2.png)

#### Proof 3
![Test 3](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test3.png)

#### Proof 4
![Test 4](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test4.png)


