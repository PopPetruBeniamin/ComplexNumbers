#include "Vector.h"
#include "Complex.h"

// Creates a vector instance containing complex numbers
std::vector<Complex> createComplexVector(int length) {
    std::vector<Complex> complexVector;
    complexVector.reserve(length);

    for (int i = 0; i < length; ++i) {
        std::cin >> complexVector[i];
        complexVector.push_back(complexVector[i]);
    }

    return complexVector;
}

// Displays all complex numbers inside the vector
void printComplexVector(const std::vector<Complex>& complexVector) {
    for (const auto & complexNumber : complexVector)
        std::cout << complexNumber << " | ";
    std::cout << std::endl;
}

// Returns the maximum complex number from the vector
Complex findMaxComplex(const std::vector<Complex>& complexVector) {
    Complex maxComplex = complexVector[0];
    for (int i = 1; i < complexVector.size(); ++i)
        if (complexVector[i] > maxComplex)
            maxComplex = complexVector[i];
    return maxComplex;
}

// Returns a vector containing complex numbers that are situated in quadrant 1
std::vector<Complex> findComplexNumbersInQuadrant1(const std::vector<Complex>& complexVector) {
    std::vector<Complex> inQuadrant1;

    for (const auto & complexNumber : complexVector)
        if (complexNumber.quadrant() == 1)
            inQuadrant1.push_back(complexNumber);

    return inQuadrant1;
}

// Returns a vector containing the longest subsequence of equal complex numbers
std::vector<Complex> findLongestSubsequenceOfEqualNumbers(const std::vector<Complex>& complexVector) {
    int start = 0, end;
    int maxStart = 0, maxEnd = 0;

    for (int i = 1; i < complexVector.size(); ++i) {
        if (complexVector[i] == complexVector[i - 1]) {
            end = i;
            if ((end - start) > (maxEnd - maxStart)) {
                maxEnd = end;
                maxStart = start;
            }
        } else {
            start = i;
        }
    }

    std::vector<Complex> longestSequence;
    for (int j = maxStart; j <= maxEnd; ++j)
        longestSequence.push_back(complexVector[j]);

    return longestSequence;
}
