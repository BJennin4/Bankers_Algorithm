# Bankers_Algorithm
This is an implementation of the Banker's Algorithm in C++. 

This program reads in an included text file, formatted to give allocation and max values for 5 processes across 3 resources, as well as the available resources for Program 0. It prints out the values on the text file, then determines if the system is in a safe state. If the system is in a safe state, it will output the safe order of processes. If it is not in a safe state, it will notify the user that the state is not safe.


## Example Output
>allocation: 010 200 302 211 002 \
>max: 753 322 902 222 433 \
>available: 332 \
>The system is in a safe state. \
>The safe order is: < P1 P3 P4 P0 P2 >
