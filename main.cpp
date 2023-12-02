#include <iostream>

/*
Allocation:
A B C
_____
0 1 0 = P0
2 0 0 = P1
3 0 2 = P2
2 1 1 = P3
0 0 2 = P4

Max:
7 5 3
3 2 2
9 0 2
2 2 2 
4 3 3

Available:
3 3 2

Is the system in a safe state? If Yes, what is the safe sequence?
*/

// Available Array // (allocation + available) when Need <= Available
// Max Array
// Allocation Array 
// Need Array // (max - allocation)

string allocation[5] = {"010", "200", "302", "211", "002"};
string max[5] = {"753", "322", "902", "222", "433"};
string available[1] = {"332"};

int recA = 12, recB = 5, recC = 7;

int main(){
    bool safe = false;
    
    
    
    if (!safe){
        std::cout << "The system is not in a safe state";
    }
    
    return 0;
}
