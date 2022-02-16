/*
operator overloading - complex number class
*/

#include <iostream>
#include <cstring>

class Complex {
    private:
        double real, img;
        double get_number(const char* str, int from, int to) const;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }

        // return value (not reference)
        Complex operator+(const Complex& c) const;  
        Complex operator+(const char* str) const;

        Complex operator-(const Complex& c) const;
        Complex operator*(const Complex& c) const;
        Complex operator/(const Complex& c) const;

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        void println() { std::cout << "(" << real << ", " << img << ")" << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

double Complex::get_number(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else  // else; --> error (why?)
            break;
    }

    if (minus) num *= - 1.0;
    return num;
}

Complex Complex::operator+(const char* str) const {
    // find 'real' and 'img' part of input string.
    // shape of string: [sign](real)[sign]i(img)  ex) "3+i2"
    // can skip the first sign.

    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    // find the position of 'i'.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // if there is no 'i', then input number has only real part.
    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);
        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    // if there is 'i', then do the job after divide real and img part.
    str_real = get_number(str, begin, pos_i - 1); 
    str_img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

    Complex temp(str_real, str_img);
    return (*this) + temp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img , real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    // 1) += operator
    // Complex a(1.0, 2.0);
    // Complex b(3.0, -2.0);

    // a += b;

    // a.println();
    // b.println();

    // 2) string from complex number calculating
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
}
