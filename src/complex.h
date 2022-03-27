// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#ifndef COMPLEX_H
#define COMPLEX_H

float absolut(float a);

class Complex
{
public:   
    Complex(float r = 0, float i = 0): r(r), i(i)
    {
        // Nothing to do
    }

    Complex(const Complex& other)
        : r(other.r), i(other.i)
    {
        // Nothing to do
    }

    void operator+=(const Complex& other)
    {
        r += other.r;
        i += other.i;
    }

    void operator*=(const Complex& other)
    {
       float newR = r*other.r - i*other.i;
       float newI = r*other.i + other.r*i;

       r = newR;
       i = newI;

    }

    void square()
    {
        float newR = r*r - i*i;
        float newI = 2*r*i;

        r = newR;
        i = newI ;
    }

    float manhattan() const
    {
        return absolut(r) + absolut(i);
    }

    float length() const;

    float r;
    float i;
};

Complex operator+(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);

#endif // COMPLEX_H
