// ////////////////////// //
// Brandon Jennings       //
// Computer Organization  //
// Project 2              //
// Banker's Algorithm     //
// ////////////////////// //
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

#include <iostream>
#include <string>
#include <array>

std::string allocation[5] = {"010", "200", "302", "211", "002"};
std::string max[5] = {"753", "322", "902", "222", "433"};
std::string available[5] = {"332"};
std::string need[5];
std::string safeOrder[5];

int main(){

    // Populating need array
    for(int i = 0; i < 5; ++i) {
    	int tmpMax, tmpAlloc, tmpTotal;
        for(int j = 0; j < 3; ++j) {
            tmpMax = max[i][j] - 48;
            tmpAlloc = allocation[i][j] - 48;
            tmpTotal = tmpMax - tmpAlloc;
            need[i] += tmpTotal + 48;
        }
    }

    bool safe = false, run = true, keepRunning = true;
    int orderItr = 0, loopItr = 0;
    std::string processNum = "", availableCarry = "";
    availableCarry = available[0];

    // Loops until done running
    // Stop running when every remaining resource is not safe
    while (keepRunning) {
    
        // Prevents infinite looping on 0 safe possibilities
        if (loopItr != 0 && orderItr == 0) keepRunning = false;
        
        // Prevents infinite looping if state is unsafe
        if (orderItr != 0) {
            ++loopItr;
            if (loopItr > 5) keepRunning = false;
        }
    
    	// Stops running when state is determined safe or unsafe
        if (orderItr == 5){
            keepRunning = false;
        }
    
        // Calculating need vs available / Order of processes    
        for(int i = 0; i < 5; ++i) {
    
            processNum = "P" + std::to_string(i);
    	    safe = true;
    	    run = true;
        
            // Determines if a process should be skipped
            for(int j = 0; j < orderItr; ++j) {
                if(safeOrder[j] == processNum) run = false;
            }
        
            // Skips the algorithm if it doesn't need run
            if(run){
                // Assigns correct available resource number
            	available[i] = availableCarry;
            
                // Determining if the state is safe for this process
                for(int j = 0; j < 3; ++j) {
                    if (need[i][j] > available[i][j]) {
                        safe = false;
                    }
                }
       
        	
                // Storing process number order
                if (safe) {
                    safeOrder[orderItr] = processNum;
                    ++orderItr;
                    
                    availableCarry = std::to_string(std::stoi(available[i]) + std::stoi(allocation[i]));
                }
            }
        }   
    }
    
    // Printing safe order if the system is safe
    if (!safe){
        std::cout << "The system is not in a safe state" << std::endl;
    } else {
        std::cout << "The system is in a safe state." << std::endl;
        std::cout << "The safe order is: < ";
        for (int i = 0; i < orderItr; ++i){
            std::cout << safeOrder[i] << " ";
        }
        std::cout << ">" << std::endl;
    }
    
    return 0;
}
