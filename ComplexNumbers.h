#include <iostream>
#include <cmath>
#include <concepts>

template<typename T>
concept is_numeric = std::is_integral<T>::value || std::is_floating_point<T>::value;

template<is_numeric T>
class Complex {

private:
    T p_re, p_im;
    const double epsilon = 1e-9;

public:
    Complex() : p_re(0), p_im(0) {}

    Complex(T real, T imag) {
        p_re = real;
        p_im = imag;
    }

    T GetP_Re() {
        return p_re;
    }

    T GetP_Im() {
        return p_im;
    }

    T SetP_Re(T number) {
        p_re = number;
    }

    T SetP_Im(T number) {
        p_im = number;
    }

    Complex<T> operator+(const Complex<T> &b) const {
        auto new_p_re = this->p_re + b.p_re;
        auto new_p_im = this->p_im + b.p_im;
        return Complex<T>(new_p_re, new_p_im);

    }

    Complex<T> operator*(const Complex<T> &b) const {
        auto new_p_re = (this->p_re * b.p_re - this->p_im * b.p_im);
        auto new_p_im = (this->p_im * b.p_re + this->p_re * b.p_im);
        return Complex<T>(new_p_re, new_p_im);
    }

    Complex<T> operator-(const Complex<T> &b) const {
        auto new_p_re = this->p_re - b.p_re;
        auto new_p_im = this->p_im - b.p_im;
        return Complex<T>(new_p_re, new_p_im);

    }

    Complex<T> operator/(const Complex<T> &b) const {
        if (std::abs(b.p_re) < epsilon && std::abs(b.p_im) < epsilon) {
            throw std::runtime_error("Division by zero");
        }
        auto new_p_re = (this->p_re * b.p_re + this->p_im * b.p_im) / (b.p_re * b.p_re + b.p_im * b.p_im);
        auto new_p_im = (this->p_im * b.p_re - this->p_re * b.p_im) / (b.p_re * b.p_re + b.p_im * b.p_im);
        return Complex<T>(new_p_re, new_p_im);
    }

    T Abs() const {
        return std::sqrt(p_im * p_im + p_re * p_re);
    }

    bool CompareToComplex(const Complex<T> &b) const {
        if (std::abs(this->p_re - b.p_re) < epsilon && std::abs(this->p_im - b.p_im) < epsilon) {
            return true;
        } else {
            return false;
        }
    }

    bool CompareToIntFloat(T b) const {
        if (std::abs(this->p_re - b < epsilon) && this->p_im < epsilon) {
            return true;
        } else {
            return false;
        }
    }

    Complex<T> Pow(int n) const {
        auto new_p_re = pow(this->Abs(), n) * std::cos(n * std::acos(this->p_re / this->Abs()));
        auto new_p_im = pow(this->Abs(), n) * std::sin(n * std::acos(this->p_re / this->Abs()));
        return Complex<T>(new_p_re, new_p_im);
    }

    void Print() const {
        if (p_im < 0) {
            double a = std::abs(p_im);
            std::cout << p_re << " - " << a << "_i";
        } else {
            std::cout << p_re << " + " << p_im << "_i";
        }
    }
};
