#include <iostream>
#include <cmath>
#include "ComplexNumbers.hpp"
#include <vector>

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex::Complex(double r, double thetaORimag, bool isExp) {
    if (isExp) {
        real = r * cos(thetaORimag);
        imag = r * sin(thetaORimag);
    } else {
        real = r;
        imag = thetaORimag;
    }
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    return Complex(newReal, newImag);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    double newReal = (real * other.real + imag * other.imag) / denominator;
    double newImag = (imag * other.real - real * other.imag) / denominator;
    return Complex(newReal, newImag);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Enter real part: ";
    is >> c.real;
    std::cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

double Complex::modulus() const {
    return sqrt(real * real + imag * imag);
}

Complex Complex::inverse() const {
    double denominator = real * real + imag * imag;
    if (denominator == 0) {
        throw std::runtime_error("Cannot calculate inverse for zero");
    }
    return Complex(real / denominator, -imag / denominator);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

double Complex::argument() const {
    return atan2(imag, real);
}

void Complex::exponentialForm() const {
    double r = modulus();
    double theta = argument();
    std::cout << "Exponential form: " << r << " * e^(i" << theta << ")" << std::endl;
}

void Complex::root(int n) const {
    roots.clear();
    double r = modulus();
    double theta = argument();

    for (int k = 0; k < n; k++) {
        double root_r = pow(r, 1.0 / n);
        double root_theta = (theta + 2 * M_PI * k) / n;
        roots.push_back(Complex(root_r * cos(root_theta), root_r * sin(root_theta)));
    }
}

void Complex::printRoots() const {
    for (size_t i = 0; i < roots.size(); i++) {
        std::cout << "Root " << i + 1 << ": " << roots[i] << std::endl;
    }
}
