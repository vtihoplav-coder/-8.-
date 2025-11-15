#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double re;
    double im;
public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    double real() const {
        return re;
    }

    double imag() const {
        return im;
    }

    Complex operator+(const Complex &b) const {
        return Complex(re + b.re, im + b.im);
    }

    Complex operator-(const Complex &b) const {
        return Complex(re - b.re, im - b.im);
    }

    Complex operator*(const Complex &b) const {
        return Complex(re * b.re - im * b.im, re * b.im + im * b.re);
    }

    Complex operator/(const Complex &b) const {
        double d = b.re * b.re + b.im * b.im;
        return Complex((re * b.re + im * b.im) / d,
                       (im * b.re - re * b.im) / d);
    }

    Complex conjugate() const {
        return Complex(re, -im);
    }

    double abs() const {
        return sqrt(re * re + im * im);
    }

    double arg() const {
        return atan2(im, re);
    }

    Complex powInt(int n) const {
        double r = abs();
        double phi = arg();
        double rn = std::pow(r, n);
        double phiN = phi * n;
        return Complex(rn * cos(phiN), rn * sin(phiN));
    }

    Complex sqrtOneRoot() const {
        double r = abs();
        double phi = arg();
        double rootR = std::sqrt(r);
        double halfPhi = phi / 2.0;
        return Complex(rootR * cos(halfPhi), rootR * sin(halfPhi));
    }

    void print() const {
        cout << "(" << re << (im >= 0 ? " + " : " - ") << fabs(im) << "i)";
    }
};

int main() {
    double aRe, aIm, bRe, bIm;
    cout << "Введіть дійсну та уявну частини числа A: ";
    cin >> aRe >> aIm;
    cout << "Введіть дійсну та уявну частини числа B: ";
    cin >> bRe >> bIm;

    Complex A(aRe, aIm);
    Complex B(bRe, bIm);

    Complex sum = A + B;
    Complex diff = A - B;
    Complex prod = A * B;
    Complex quot = B.real() != 0.0 || B.imag() != 0.0 ? A / B : Complex(0, 0);
    Complex conjA = A.conjugate();
    Complex powA3 = A.powInt(3);
    Complex sqrtA = A.sqrtOneRoot();

    cout << "\nA = ";
    A.print();
    cout << "\nB = ";
    B.print();

    cout << "\n\nA + B = ";
    sum.print();
    cout << "\nA - B = ";
    diff.print();
    cout << "\nA * B = ";
    prod.print();
    cout << "\nA / B = ";
    if (B.real() == 0.0 && B.imag() == 0.0) {
        cout << "ділення на нуль неможливе";
    } else {
        quot.print();
    }
    cout << "\nconj(A) = ";
    conjA.print();
    cout << "\nA^3 = ";
    powA3.print();
    cout << "\nsqrt(A) (один з коренів) = ";
    sqrtA.print();
    cout << endl;

    return 0;
}
