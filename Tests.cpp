#include "Complex.h"
#include "Vector.h"
#include <cassert>
#include <vector>

// ========== Test Complex Number Class ==============================================================================

void testConstructors(){
    Complex c1;
    assert ((c1.getReal()) == 1 && (c1.getImag() == 1));

    Complex c2(3, 4);
    assert ((c2.getReal() == 3) && (c2.getImag() == 4));

    Complex c3(5);
    assert ((c3.getReal() == 5) && c3.getImag() == 0);
}

void testSetGet(){
    Complex c;
    c.setReal(4);
    c.setImag(5);

    assert ((c.getReal() == 4) && (c.getImag() == 5));
}

// Test +, -, =, ==, +=, -=
void testSign(){
    Complex c1(2, 3);
    Complex c2(5, 6);

    Complex c3 = +c2;
    assert ((c3.getReal() == 5) && (c3.getImag() == 6));

    Complex c4 = -c1;
    assert ((c4.getReal() == -2) && (c4.getImag()) == -3);

    Complex c5(4, 4);
    Complex c6(4, 4);

    assert ((c5 == c6));

    c5 += c6;
    assert ((c5.getImag() == 8) && (c5.getReal() == 8));

    c2 -= c1;
    assert ((c2.getImag() == 3) && c2.getReal() == 3);
}

// ========== Test Vector containing complex numbers ==================================================================

void testFindMaxComplex(){
    std::vector<Complex> complexVector;
    complexVector.reserve(5);

    Complex c1(1, 2);
    Complex c2(-2, -2);
    Complex c3(3, -5);
    Complex c4(9, -7);
    Complex c5(4, -3);

    complexVector.push_back(c1);
    complexVector.push_back(c2);
    complexVector.push_back(c3);
    complexVector.push_back(c4);
    complexVector.push_back(c5);

    assert (findMaxComplex(complexVector) == c4);
}

void testFindComplexNumbersInQuadrant1(){
    std::vector<Complex> complexVector;
    complexVector.reserve(4);

    Complex c1(5, -3);
    Complex c2(-1, -1);
    Complex c3(4, 4);
    Complex c4(7, 1);

    complexVector.push_back(c1);
    complexVector.push_back(c2);
    complexVector.push_back(c3);
    complexVector.push_back(c4);

    std::vector<Complex> complexNumbersInQuadrant1;
    complexNumbersInQuadrant1 = findComplexNumbersInQuadrant1(complexVector);

    assert (complexNumbersInQuadrant1[0] == c3);
    assert (complexNumbersInQuadrant1[1] == c4);
    assert (complexNumbersInQuadrant1.size() == 2);
}

void testFindLongestSubsequenceOfEqualNumbers(){
    std::vector<Complex> complexVector;
    complexVector.reserve(6);

    Complex c1(9, 1);
    Complex c2(4, -7);
    Complex c3(4, -7);
    Complex c4(4, -7);
    Complex c5(3, 5);
    Complex c6(-4, 2);

    complexVector.push_back(c1);
    complexVector.push_back(c2);
    complexVector.push_back(c3);
    complexVector.push_back(c4);
    complexVector.push_back(c5);
    complexVector.push_back(c6);

    std::vector<Complex> longestSubsequence;
    longestSubsequence = findLongestSubsequenceOfEqualNumbers(complexVector);

    assert (longestSubsequence.size() == 3);
    assert (longestSubsequence[0] == c2);
    assert (longestSubsequence[1] == c3);
    assert (longestSubsequence[2] == c4);
}

// =========== Test All ===============================================================================================

void testFunctions(){
    testConstructors();
    testSetGet();
    testSign();

    testFindMaxComplex();
    testFindComplexNumbersInQuadrant1();
    testFindLongestSubsequenceOfEqualNumbers();

    std::cout << "All tests passed!" << std::endl;
}