#ifndef LAB06COMPLEXNUMBERS_COMPLEX_H
#define LAB06COMPLEXNUMBERS_COMPLEX_H

#include <iostream>
using namespace std;

class Complex{
private:
    int imag;
    int real;
public:
    // Constructors, Deconstructor
    Complex();
    Complex(int valImag, int valReal);
    explicit Complex(int no);
    Complex(const Complex &c);
    ~Complex();

    // Getters, Setters
    void setImag(int valImag);
    void setReal(int valReal);
    [[nodiscard]] int getImag() const;
    [[nodiscard]] int getReal() const;

    // Operators
    bool operator<(const Complex &) const;
    bool operator>(const Complex &) const;
    const Complex& operator+() const;
    Complex operator-() const;
    Complex& operator=(const Complex& cRight);
    int operator==(const Complex& cRight) const;
    Complex& operator+=(const Complex& cRight);
    Complex& operator-=(const Complex& cRight);

    // Friend operators
    friend ostream& operator<<(ostream &, const Complex &);
    friend istream& operator>>(istream &, Complex &);

    // Methods
    [[nodiscard]] int quadrant() const;
};

#endif //LAB06COMPLEXNUMBERS_COMPLEX_H
