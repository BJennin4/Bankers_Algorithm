// ////////////////////// //
// Brandon Jennings       //
// Computer Organization  //
// Project 2              //
// ////////////////////// //

#include <iostream>
#include <string>

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

std::string allocation[5] = {"010", "200", "302", "211", "002"};
std::string max[5] = {"753", "322", "902", "222", "433"};
std::string available[5] = {"332"};
std::string need[5];
std::string safeOrder[5];

int main(){
    for(int i = 0; i < 5; ++i) {
    	int tmpMax, tmpAlloc, tmpTotal;
        for(int j = 0; j < 3; ++j) {
            tmpMax = max[i][j] - 48;
            tmpAlloc = allocation[i][j] - 48;
            tmpTotal = tmpMax - tmpAlloc;
            need[i] += tmpTotal + 48;
        }
    }
    
    bool safe = false;
    int orderItr = 0;
    std::string tmp = "";
    
    for(int i = 0; i < 5; ++i) {
    	safe = true;
        std::cout << allocation[i] << std::endl;
        std::cout << available[i] << std::endl;
        std::cout << need[i] << std::endl;
        for(int j = 0; j < 3; ++j) {
            if (need[i][j] <= available[i][j]) {
                std::cout << "True" << std::endl;
            } else {
                std::cout << "False" << std::endl;
                safe = false;
            }
        }
        
        if (!safe) {
            available[i+1] = available[i]; 
        } else {
            available[i+1] = std::to_string(std::stoi(available[i]) + std::stoi(allocation[i]));
            
            tmp = "P" + std::to_string(i);
            
            safeOrder[orderItr] = tmp;
            ++orderItr;
        }
    }

    std::cout << std::endl;
    
    if (!safe){
        std::cout << "The system is not in a safe state" << std::endl;
    } else {
        std::cout << "The safe order is: ";
        for (int i = 0; i < orderItr; ++i){
            std::cout << safeOrder[i] << " ";
        }
    }
    
    return 0;
}
