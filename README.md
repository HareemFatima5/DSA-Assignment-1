# CPU Scheduling using Circular Linked List

This project implements a circular linked list to manage and schedule CPU processes using a fixed time approach. Each process is represented as a node in the circular linked list, allowing efficient traversal and removal of completed processes.

## Features

- **Circular Linked List**: Efficiently manages processes in a circular manner.
- **Fixed Time**: Each process is allocated a fixed time for execution.
- **Dynamic Memory Management**: Proper handling of process completion and memory cleanup.

## Assumptions

- Each process is represented by a unique process ID.
- Remaining execution times are non-negative and initialized correctly.
- The fixed time input for process execution is valid and greater than zero.

## Challenges

- Efficiently managing memory when processes are completed and nodes are removed from the circular linked list.
- Ensuring the proper traversal of the circular linked list without falling into infinite loops or skipping nodes.

# Flexible CPU Scheduling using Cicrular Linked List

This project implements a circular linked list to simulate a CPU scheduling algorithm. The program manages processes with their execution and remaining times, allowing for dynamic updates and scheduling.

## Features

- **Circular Linked List**: Efficiently manages processes in a circular manner.
- **Fixed Time**: Each process is allocated a fixed time for execution.
- **Dynamic Process Management**: Users can add new processes during scheduling.
- **Dynamic Memory Management**: Proper handling of process completion and memory cleanup.

## Assumptions

- Processes have non-negative remaining times.
- The fixed time input is valid and greater than zero.

## Challenges

- Handling dynamic scheduling effectively when new processes are introduced during execution.
- Ensuring proper memory management when removing completed processes from the circular linked list.
 
# 1024-bit Primality Testing 

This implements a primality testing algorithm for a 1024-bit number using a in C++. The program generates a random 64-bit number and reconstructs a larger number to check its primality using the Miller-Rabin primality test.

## Features

- **Random Number Generation**: Generates random 64-bit numbers to form a 1024-bit number.
- **Circular Linked List**: Uses a linked list to store and manage the large number.
- **Miller-Rabin Primality Test**: Efficiently tests if the constructed number is prime.
- **Display of Smaller Primes**: Lists smaller prime numbers for reference.

 ## Assumptions

- Input consists of 16 linked nodes representing a valid 1024-bit integer.
- Random numbers generated are sufficiently random and independent.
- Smaller prime range in the print function is fixed at 100.

## Challenges

- Memory management issues may lead to leaks if nodes are not properly deleted.
- Random number generation may produce duplicates, affecting randomness.
- Integer overflow may occur when reconstructing the 1024-bit number from 64-bit chunks.
- Algorithm complexity may impact performance with large inputs.
- Primality testing can be slow for larger numbers with high iteration counts.

## Requirements

- C++ Compiler (e.g., vs code , visual studio)

## Contributors
- [Hareem Fatima](https://github.com/HareemFatima5)

