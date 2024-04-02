# x86_64_LBYARCH_MCO2

## PROOFS OF CORRECTNESS

#### Proof 1
![Test 1](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test1.png)

#### Proof 2
![Test 2](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test2.png)

#### Proof 3
![Test 3](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test3.png)

#### Proof 4
![Test 4](https://github.com/nicoleUY/x86_64_LBYARCH_MCO2/blob/master/images/lbyarch%20test4.png)



## COMPARATIVE EXECUTION TIME

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

- In Table 1, it can be seen that the asm kernel consistently performs much faster than the c kernel. 
- As expected, as the vector size increases, the run time also increases
- In Table 2, it can be seen that performance of the kernels are nearer in value. 
- However, in Table 2, when the size of the vector reaches 2^30, the difference is more drastic
