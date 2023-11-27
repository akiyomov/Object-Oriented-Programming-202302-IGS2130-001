#include<iostream>

using namespace std;

// Function to find the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 1, int denominator = 2) : m_numerator(numerator), m_denominator(denominator) {}

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.m_denominator < 0) {
            out << -f.m_numerator << "/" << -f.m_denominator;
        } else {
            out << f.m_numerator << "/" << f.m_denominator;
        }
        return out;
    }

    Fraction operator*(const Fraction& f) const {
        Fraction result;
        result.m_numerator = this->m_numerator * f.m_numerator;
        result.m_denominator = this->m_denominator * f.m_denominator;

        // Find the greatest common divisor (GCD) of the numerator and denominator
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);

        // Reduce the fraction by dividing both numerator and denominator by the GCD
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;

        return result;
    }

    Fraction operator*(int value) const {
        Fraction result(*this); // Create a copy of the current fraction

        result.m_numerator *= value;

        // Find the greatest common divisor (GCD) of the new numerator and the original denominator
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);

        // Reduce the fraction by dividing the numerator by the GCD
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;

        return result;
    }

    Fraction operator+(Fraction& f) const {
        Fraction result;
        result.m_denominator = this->m_denominator * f.m_denominator;
        result.m_numerator = this->m_numerator * f.m_denominator + this->m_denominator * f.m_numerator;
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;
        return result;
}
    Fraction operator-(Fraction& f) const {
        Fraction result;
        result.m_denominator = this->m_denominator * f.m_denominator;
        result.m_numerator = this->m_numerator * f.m_denominator - this->m_denominator * f.m_numerator;
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;
        return result;
}

    friend Fraction operator*(int value, const Fraction& f) {
        Fraction result(f); // Create a copy of the provided fraction

        result.m_numerator *= value;

        // Find the greatest common divisor (GCD) of the new numerator and the original denominator
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);

        // Reduce the fraction by dividing the numerator by the GCD
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;

        return result;
    }
    friend Fraction operator+(int value,const Fraction& f){
        Fraction result(f);
        result.m_numerator += f.m_denominator*value;
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);

        // Reduce the fraction by dividing the numerator by the GCD
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;

        return result;
    }
    friend Fraction operator-(int value,const Fraction& f){
        Fraction result(f);
        result.m_numerator = f.m_denominator*value - f.m_numerator;
        int commonDivisor = gcd(result.m_numerator, result.m_denominator);

        // Reduce the fraction by dividing the numerator by the GCD
        result.m_numerator /= commonDivisor;
        result.m_denominator /= commonDivisor;

        return result;
    }


};

int main() {
    Fraction f1(1, 2), f2(3, 4);
    cout << f1 << ", " << f2 << endl;
    cout <<f1 << "*"<<f2 <<"="<< f1 * f2 << endl;
    cout << f1 << "+" << f2 << "=" << f1+f2<<endl;
    cout << f1 << "-" << f2 << "=" << f1-f2<<endl;
    cout << 2 << "-" << f2 << "=" << 2-f2<<endl;
    cout << 2 << "+" << f1 << "=" << 2+f1<<endl;
    return 0;
}
