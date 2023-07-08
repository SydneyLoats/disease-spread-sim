
# Disease Simulation Project

## Files
`finalProjectWriteup.pdf` is the project writeup.  

`infectiousDisease.h` is the header file.  
`infectiousDisease.cpp` is the implementation.

Main methods differ based on desired simulation:  
`main1.cpp` runs a simulation of the spread of a disease in a population when an infected 
person can spread the disease to people they come into contact with.  
`main2.cpp` runs a simulation of the spread of a disease in a population when an infected
person can spread the disease to only their neighbors.

### Running Instructions
Run the first main method, `main1.cpp`:  
1. `icpc -o runMain1 infectiousDisease.cpp main1.cpp`  
2. `./runMain1`

Run the second main method, `main2.cpp`:  
1. `icpc -o runMain2 infectiousDisease.cpp main2.cpp`  
2. `./runMain2`
