#include "Complex.h"
#include <cmath>

// =================== CONSTRUCTORS/DECONSTRUCTOR =====================================================================

Complex::Complex(){
    this->imag = 1;
    this->real = 1;
}

Complex::Complex(int valReal, int valImag){
    this->imag = valImag;
    this->real = valReal;
}

Complex::Complex(int no){
    this->imag = 0;
    this->real = no;
}

Complex::Complex(const Complex &c){
    this->imag = c.imag;
    this->real = c.real;
}

Complex::~Complex()= default;

// =================== GETTERS/SETTERS ================================================================================

void Complex::setImag(int valImag) {
    imag = valImag;
}

void Complex::setReal(int valReal) {
    real = valReal;
}

int Complex::getImag() const{
    return imag;
}

int Complex::getReal() const{
    return real;
}

// ===================== OPERATORS ====================================================================================

// Formula: sqrt(a^2 + b^2), a = real value, b = imag value
bool Complex::operator<(const Complex &c) const{
    double val1 = sqrt(this->real*this->real + this->imag*this->imag);
    double val2 = sqrt(c.real*c.real + c.imag*c.imag);
    return (val1 < val2);
}

bool Complex::operator>(const Complex &c) const{
    double val1 = sqrt(this->real*this->real + this->imag*this->imag);
    double val2 = sqrt(c.real*c.real + c.imag*c.imag);
    return (val1 > val2);
}

const Complex& Complex::operator+() const {
    return (*this);
}

Complex Complex::operator-() const {
    return {-this->real, -this->imag};
}

Complex& Complex::operator=(const Complex& cRight) {
    if(this != &cRight){
        this->real = cRight.real;
        this->imag = cRight.imag;
    }
    else
        cout << "self assignment";
    return *this;
}

int Complex::operator==(const Complex& cRight) const{
    return ((this->real == cRight.real) && (this->imag == cRight.imag));
}

Complex& Complex::operator+=(const Complex& cRight){
    this->real = this->real + cRight.real;
    this->imag = this->imag + cRight.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& cRight){
    this->real = this->real - cRight.real;
    this->imag = this->imag - cRight.imag;
    return *this;
}

ostream &operator<<(ostream &os, const Complex &c) {
    if (c.imag < 0)
        os << c.real << c.imag << "i";
    else
        os << c.real << "+" << c.imag << "i";
    return os;
}

istream &operator>>(istream& is, Complex& c) {
    string input;
    is >> input;

    size_t pos = input.find(',');
    if (pos != string::npos) {
        string realPart = input.substr(0, pos);
        string imagPart = input.substr(pos + 1);

        // Convert string parts to integers
        int real = stoi(realPart);
        int imag = stoi(imagPart);

        c.setReal(real);
        c.setImag(imag);
    }

    return is;
}

// ========== METHODS =================================================================================================

// Returns the quadrant in which the complex number is situated
int Complex::quadrant() const {
    if (this->real > 0 && this->imag > 0)   return 1;
    if (this->real < 0 && this->imag > 0)   return 2;
    if (this->real < 0 && this->imag < 0)   return 3;
    if (this->real > 0 && this->imag < 0)   return 4;
    return 0;
}
