// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#include "stdpch.h"
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

float Complex::length() const
{
    return qSqrt(r * r + i * i);
}
