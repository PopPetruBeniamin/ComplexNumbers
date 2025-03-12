#ifndef LAB06COMPLEXNUMBERS_VECTOR_H
#define LAB06COMPLEXNUMBERS_VECTOR_H

#include "Complex.h"
#include <vector>

std::vector<Complex> createComplexVector(int length);

void printComplexVector(const std::vector<Complex>& complexVector);

Complex findMaxComplex(const std::vector<Complex>& complexVector);

std::vector<Complex> findComplexNumbersInQuadrant1(const std::vector<Complex>& complexVector);

std::vector<Complex> findLongestSubsequenceOfEqualNumbers(const std::vector<Complex>& complexVector);

#endif //LAB06COMPLEXNUMBERS_VECTOR_H
