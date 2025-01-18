#ifndef CMXN
#define CMXN

#include <iostream>
#include <cmath>
#include <vector>

class Complex {
private:
    double real;
    double imag;
    std::vector<Complex> roots;

public:
    Complex(double r = 0, double i = 0);

    double getReal() const;
    double getImag() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex inverse() const;
    Complex conjugate() const;
    double argument() const;
    void exponentialForm() const;

    void root(int n);
    void printRoots() const;

    double modulus() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif // CMXN
