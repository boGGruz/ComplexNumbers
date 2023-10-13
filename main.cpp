#include <iostream>
#include <cmath>

template <typename T>
class Complex{

private:
    T p_re, p_im;

public:
    Complex(){
        p_re = 0;
        p_im = 0;
    }

    Complex(T real, T imag){
        p_re = real;
        p_im = imag;
    }

    T GetP_Re(){
        return p_re;
    }

    T GetP_Im(){
        return p_im;
    }

    T SetP_Re(T number){
        p_re = number;
    }

    T SetP_Im(T number){
        p_im = number;
    }

    Complex<T> operator+(Complex<T> &b){
        auto new_p_re = this->p_re + b.p_re;
        auto new_p_im = this->p_im + b.p_im;
        return Complex<T>(new_p_re, new_p_im);

    }

    Complex<T> operator*(Complex<T> &b){
        auto new_p_re = (this->p_re * b.p_re - this->p_im * b.p_im);
        auto new_p_im = (this->p_im * b.p_re + this->p_re * b.p_im);
        return Complex<T>(new_p_re, new_p_im);
    }

    Complex<T> operator-(Complex<T> &b){
        auto new_p_re = this->p_re - b.p_re;
        auto new_p_im = this->p_im - b.p_im;
        return Complex<T>(new_p_re, new_p_im);

    }

    Complex<T> operator/(Complex<T> &b){
        auto new_p_re = (this->p_re * b.p_re + this->p_im * b.p_im)/(b.p_re * b.p_re + b.p_im* b.p_im);
        auto new_p_im = (this->p_im * b.p_re - this->p_re * b.p_im)/(b.p_re * b.p_re + b.p_im* b.p_im);
        return Complex<T>(new_p_re, new_p_im);
    }

    T Abs(){
        return (std::sqrt(p_im*p_im + p_re*p_re));
    }

    T CompareToComplex (Complex<T> &b){
        if (this->p_re == b.p_re && this->p_im == b.p_im)
            return true;
        else
            return false;
    }

    T CompareToIntFloat(T b){
        if (this->p_re == b && this->p_im == 0)
            return true;
        else
            return false;
    }

    Complex<T> Pow( int n){
        auto new_p_re = pow(this->Abs(),n) * std::cos(n*std::acos(this->p_re/this->Abs()));
        auto new_p_im = pow(this->Abs(),n) * std::sin(n*std::acos(this->p_re/this->Abs()));
        return Complex<T>(new_p_re, new_p_im);
    }

    void Print(){
        if (p_im < 0) {
            double a = std::abs(p_im);
            std::cout << p_re << " - " << a << "_i";
        }
        else
            std::cout << p_re << " + " << p_im << "_i";
    }
};
