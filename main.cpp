#include <iostream>
#include<string>
#include<stdexcept>
#include<numeric>
#include<cmath>


class Rational { 
public:
    std::string AsString() const { return std::to_string(num_) + '/' + std::to_string(den_); }
    Rational(int num = 0, int den = 1): num_ { num }, den_{ den } {
        if (den_ == 0) {
            throw "Denominator can`t be zero";
        }
        Normalize();
    }
    int GetNum() const { return num_; }
    int GetDen() const { return den_; }

    Rational operator+(const Rational& rhs) const {
        int den = GetDen() * rhs.GetDen();
        int num = GetNum() * rhs.GetDen() + rhs.GetNum() * GetDen();
        return Rational(num, den);
    }
    bool operator>(const Rational& rhs) const {
        int den = GetDen() * rhs.GetDen();
        int num = GetNum() * rhs.GetDen() - rhs.GetNum() * GetDen();
        if (num<0) {
            return false;
        }
        else {
            return true;
        }
    }

private:
    int num_;
    int den_;
    int gcd(int a, int b) const {
        return (b == 0) ? a : gcd(b, a % b);
    }
    void Normalize() {
        int g = gcd(std::abs(num_), std::abs(den_));
        num_ /= g;
        den_ /= g;
    }
};

Rational max(const Rational a, const Rational b) {
        if (a>b) {
            return a;
        } 
        else {
            return b;
        }
    }

int main() {
    Rational r0;
    Rational r1(5);
    Rational r2(4, 6);
    Rational r3 = r1 + r2;
    std::cout << r0.AsString() << std::endl;
    std::cout << r1.AsString() << std::endl;
    std::cout << r2.AsString() << std::endl;
    std::cout << r3.AsString() << std::endl;
    std::cout << max(r2,r3).AsString() << std::endl;

}