# A quantum computer simulator using GPUs #
This code uses PyTorch to implement a quantum computer simulation using grovers algorithm on both CPU and GPU. Qubits are simulated using vectors (tensors) and quantum states are maintained in the workspace. PushQubit is used to add a new qubit into a state to the system which is then normalised and the Kronecker product is output. 

Tosqubit is a method of itterating through the stack by bringing the named qubit to the top of the stack and rearranging the rest of the stack. 

Gates are applied to the qubits and matmul is implemented to simulate the gate action on the quantum state. The probability of the qubit is then measured using ProbQubit(). MeasureQubit will then measure the qubit value and collapse the state to either 0 or 1. Th equbit will then be removed from the stack and the quantum state will be adjusted. Np.random.choice is used to give probabilistic quantum measurements of the qubit.

When measuring processing time with a GPU, the workspace is initialised and a groverSearch is run using a 16 qubit Grovers search. The processing time is measured and printed.

This is repeated for a CPU with the same number of qubits. 

For a computer with a Nvidia RTX the GPU time was 0.6s while the CPU time was 7.5s This shows that GPU is much faster than CPU

# Complete Implementation #
This program will simulate Grovers Search Algorithm to fund a specific value in a disordered databaseas described in week 8. A quadratic speed up is seen when compared to classical computers.

The workspace is an array which stores the vector state of the quantum system and is initialise to an amplitude of 1.0 for a qubit in state 0. Namestack will keep track of the order qubits are pushed and will ensure the correct qubit is at the top of the stack. Pushqubit is used as before to normalise the wights and apply a kronecher function. 

H,Z and X gates are applied to specific qubits to order then correctly in the stack. A sample_phaseOracle function is used to output the correct state for the qubit by flipping the qubit phase as described in previous weeks. 

Grovers search will then initialise n qubits into equal superposition and iterate through the stack. Once enough iterations are performed the qubits are measured. In this case, grovers search is run on 8 qubits so it will search over 2^8 times which equals 256 items.  The amplitude of the correct answer is amplified so that the specific solution is marked clearly.

# Miminal Implementation #

This program is similar to the previous one however it does not print all the qubit measurements, instead only the final grovers algorithm output. This program used a 10 qubit system and a diagonal matrix to flip the amplitude of the states depending on the phase oracle. A 10-bit biary string with the amplified solution is output
