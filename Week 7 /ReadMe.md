# Instruction 1 #
The first part of this assignment involves reshaping the program workspace into a row vector matrix by pushing qubits onto the stack. The Kron function is then used to expand the memory of the Kronecker product of the workspace and qubit weight vector

Pushing Qubits - a pushQubit function which takes in one parameter (weights), this was called to push the weights of the quibits onto the stack, this estentially doubles the workspace with each push.
Reshaping - np.reshape was used to reshape the workspace into a 2D array. Workspace will now have one row and a set number of columns
Kronecker - np.kron is used to determine the products of the reshaped weights and workspace. Kronecker product is a block matrix, where each element of workspace is multiplied by the entire weights matrix.
Workspace - the workspace defines the data type by creating a quantm stack. The empty quantum stack is a matrix of one row and one column containing the nummber.

# Instruction 2 #

This part of the assignment consists of performing operations called gates on the qubits defined by the workspace and kronecker.The gate is used to manipulate the entire workspace. Gates can be used as a way of multiplying, transposing or conjugating matrices. There is a large variety of gates that can be implemented for various purposes. X-gates are used as a not gate, which switches the probabilities for a qubit being zero or one through multiplication. Defined qubits are pushed into the workspace and the chosen gate is then applied to the workspace using applyGate(X_gate).

A hadamard gate or H_gate is another gate type that can be used which will give the input qubits in the matrix the same probabilites of occuring, this is also done through matrix multiplication. The implementation process for this gate is the same as the X-gate. 

T-gates are used for complex weight inputs and required initialisation before the gate is applied. This function also find the probabiltes of the input qubits. 

A SWAP_gate can be used for real number weight inputs. A swap gate will essentially swap the order of qubit matrix multiplication. For example if the workspace is defined to multiply qubit 1 x qubit 2, the swap_gate output will be qubit 2 x qubit 1.

Gates can also be used to put the matrix through a phase shift, rotation and XOR gate to name a few.

# Instruction 3 #
The third part of this assignment focuses on itterating through the full stack of qubits instead of only the top qubits in the stack. A function tosQubit(k) is used to shift to shift the stack of qubits by moving a qubit in position k to the top of the stack and shifting all the other qubits down one in the stack. This similar to using a Swap_gate. When using tosqubit the does not need to be reshaped as it does when using a swap gate. The reshaping built into the toswubit function can be undone by reshaping the tosquibit output.

# Instruction 4 #
When measuring qubits, the output is generally not a weight but instead either a zero or one. This is because when measuring the qubits the probabilities of the individual components are one or zero. To avoid this issue and obtain a more accurate probability, the linalg.norm function can be used. what this function does is compute the probability of the quantum states being 1 or 0 by assessing the squared magnitude of the workspace. Random choice is used for more accuracy of the qubit state, the random choice is based on the probabilites stored in the probability function. Once the probability and random choice measurements are made the workspace is updated to reflect the collapse of the quantum state. The workspace value and corresponding measurement value is normalised by dividing by the square root of the probability. This ensure the quantum states have a norm of 1 which is required. In a nutshell, this program will asses the superposition of the qubits and after measurements to qubit will collapse to one of the superposition states. The final state of the qubit is then output by the program. For larger workspaced containing three qubits, gates such as hadamard and toffoli gates may be required for further accuracy of the collapsed workspace. This will output a truth table.
