#include <iostream>
#include "ComplexNumbers.hpp"

int main() {
    // Create complex numbers
    Complex c1(3, 4);  // 3 + 4i
    Complex c2(1, 2);  // 1 + 2i
    Complex c3(5, -6); // 5 - 6i

    // Addition
    Complex sum = c1 + c2;
    std::cout << "c1 + c2 = " << sum << std::endl;

    // Subtraction
    Complex diff = c1 - c2;
    std::cout << "c1 - c2 = " << diff << std::endl;

    // Multiplication
    Complex prod = c1 * c2;
    std::cout << "c1 * c2 = " << prod << std::endl;

    // Division
    try {
        Complex quotient = c1 / c2;
        std::cout << "c1 / c2 = " << quotient << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Modulus
    std::cout << "Modulus of c1 = " << c1.modulus() << std::endl;

    // Inverse
    try {
        Complex inv = c1.inverse();
        std::cout << "Inverse of c1 = " << inv << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Conjugate
    Complex conj = c1.conjugate();
    std::cout << "Conjugate of c1 = " << conj << std::endl;

    // Argument
    std::cout << "Argument of c1 = " << c1.argument() << std::endl;

    // Exponential form
    c1.exponentialForm();

    // Roots of c1 (2nd roots for simplicity)
    c1.root(2);
    c1.printRoots();

    return 0;
}
