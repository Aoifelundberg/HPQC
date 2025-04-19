# A quantum computer simulator using GPUs #
This code uses PyTorch to implement a quantum computer simulation using grovers algorithm on both CPU and GPU. Qubits are simulated using vectors (tensors) and quantum states are maintained in the workspace. PushQubit is used to add a new qubit into a state to the system which is then normalised and the Kronecker product is output. 

Tosqubit is a method of itterating through the stack by bringing the named qubit to the top of the stack and rearranging the rest of the stack. 

Gates are applied to the qubits and matmul is implemented to simulate the gate action on the quantum state. The probability of the qubit is then measured using ProbQubit(). MeasureQubit will then measure the qubit value and collapse the state to either 0 or 1. Th equbit will then be removed from the stack and the quantum state will be adjusted. Np.random.choice is used to give probabilistic quantum measurements of the qubit.

When measuring processing time with a GPU, the workspace is initialised and a groverSearch is run using a 16 qubit Grovers search. The processing time is measured and printed.

This is repeated for a CPU with the same number of qubits. 

For a computer with a Nvidia RTX the GPU time was 0.6s while the CPU time was 7.5s This shows that GPU is much faster than CPU
