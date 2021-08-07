#include "complex.h"

float absolut(float a)
{
    return a < 0 ? a * (-1) : a;
}

Complex operator+(const Complex& a, const Complex& b) {
    Complex result(a);
    result += b;
    return result;
}

Complex operator*(const Complex& a, const Complex& b) {
    Complex result(a);
    result *= b;
    return result;
}
