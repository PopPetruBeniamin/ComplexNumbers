#include "Complex.h"
#include "Vector.h"
#include <iostream>
#include <vector>

// ========== ADDITIONAL READ/PRINT FUNCTIONS =========================================================================

int readListLength() {
    int length;
    std::cout << " Enter the length of the vector:";
    std::cin >> length;
    return length;
}

void printMaxComplexNumber(Complex& complexNum) {
    std::cout << "Max number in vector:" << complexNum << std::endl;
}

void printCommands() {
    std::cout << std::endl;
    std::cout << "========== COMMANDS =========================" << std::endl;
    std::cout << "1. Read vector of complex numbers" << std::endl;
    std::cout << "2. Print vector of complex numbers" << std::endl;
    std::cout << "3. Print the maximum complex number" << std::endl;
    std::cout << "4. Print all complex numbers in quadrant 1" << std::endl;
    std::cout << "5. Print longest subsequence with equal complex numbers" << std::endl;
    std::cout << "0. EXIT" << std::endl;
}

int readCommand() {
    int command;
    std::cout << " Enter your command:";
    std::cin >> command;
    std::cout << std::endl;
    return command;
}

// ========== MAIN CONSOLE ============================================================================================

int mainConsole() {
    int length;
    Complex maxComplex;
    std::vector<Complex> complexVector;
    std::vector<Complex> inQuadrant1;
    std::vector<Complex> longestSubsequence;

    while (true) {
        printCommands();
        int command = readCommand();
        switch (command) {
            case 1:
                length = readListLength();
                std::cout << " Enter " << length << " complex numbers (in format:'x,y'):" << std::endl;
                complexVector = createComplexVector(length);
                break;
            case 2:
                std::cout << "Complex numbers in vector: ";
                printComplexVector(complexVector);
                break;
            case 3:
                maxComplex = findMaxComplex(complexVector);
                printMaxComplexNumber(maxComplex);
                break;
            case 4:
                inQuadrant1 = findComplexNumbersInQuadrant1(complexVector);
                std::cout << "Complex numbers in quadrant 1: ";
                printComplexVector(inQuadrant1);
                break;
            case 5:
                longestSubsequence = findLongestSubsequenceOfEqualNumbers(complexVector);
                std::cout << "Longest subsequence of equal complex numbers: ";
                printComplexVector(longestSubsequence);
                break;
            case 0:
                std::cout << "Application closed!";
                return 0;
            default:
                std::cout << "Invalid command" << std::endl;
                break;
        }
    }
}
