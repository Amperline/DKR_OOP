#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
try
{
    std::cout << "----Example: " << std::endl;
    Complex a(Complex::Complex_Axes(1, 3), "a_log");
    Complex b(Complex::Complex_Axes(-1, 2));
    
    Complex c = Complex::addNubers(a, b);

    std::cout << "Algebraic: ";
    c.show();

    std::cout << "Exponential: ";
    c.show(true);

    std::cout << "----Type in (a + b):" << std::endl;

    double a_r;
    double a_i;
    double b_r;
    double b_i;

    std::cout << "(a) real: ";
    std::cin >> a_r;
    std::cout << "(a) imaginary: ";
    std::cin >> a_i;

    std::cout << "(b) real: ";
    std::cin >> b_r;
    std::cout << "(b) imaginary: ";
    std::cin >> b_i;
    
    Complex res = Complex::addNubers(Complex::Complex_Axes(a_r, a_i), Complex::Complex_Axes(b_r, b_i));
    res.show();
    res.show(true);
}
    catch(std::exception &e)
    {
        cout << endl << e.what() << endl;
    }

    return 0;
}