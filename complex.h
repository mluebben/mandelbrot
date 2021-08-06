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





    float r;
    float i;
};




#endif // COMPLEX_H
