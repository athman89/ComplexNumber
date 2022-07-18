#include <iostream>
#include <cmath>


//A class for complex numbers using polar representation
class Complex{
private:
double r;    //distance
double theta;   //angle
public:
    Complex(double re,double im){   //constructor that takes in rectangular coordinates
        r = sqrt(re*re + im*im);
        theta = std::atan2(im,re);
    }
    double re();   //accessor method
    double im();  //accessor method
    Complex plus(Complex b);
    Complex times(Complex b);
    double ab();
    void toString();
    Complex(const Complex& other);//copy constructor
    Complex& operator=(const Complex& other);//copy assignment
    ~Complex();
};

double Complex::re() {
    return r * cos(theta);
}

double Complex::im() {
    return r * sin(theta);
}
//return complex number plus b
Complex Complex::plus(Complex b) {
   Complex a = *this;
   double re = a.r * cos(a.theta) + b.r * cos(b.theta);
   double im = a.r * sin(a.theta) + b.r * sin(b.theta);
   return Complex(re,im);
}
//return complex number times b
Complex Complex::times(Complex b) {
    Complex* a = this;
    Complex* c = new Complex(0,0);
    c->r = a->r * b.r;
    c->theta = a->theta + b.theta;
    return *c;
}
//return absolute value of complex number
double Complex::ab() {
    return r;
}
//return a string representation of the complex number
void Complex::toString() {
    std::cout << re() << " + " << im() << "i";
}

Complex::Complex(const Complex &other) {
 r = other.r;
 theta = other.theta;
}

Complex& Complex::operator=(const Complex& other) {
   r = other.r;
   theta = other.theta;
   return *this;
}

Complex::~Complex() {

}

//client testing - return roots of unity
int main() {
    Complex c (5.0,6.0);
    std::cout <<"c = " << c.re() <<" + " << c.im()<<"i" <<std::endl;
    Complex d (-2.0,3.0);
    std::cout <<"d = " << d.re() <<" + " << d.im()<<"i" <<std::endl;
    Complex e = d.times(c);
    Complex f = d.plus(c);
    std::cout <<"e = " << e.re() <<" + "<< e.im()<<"i" <<std::endl;
    std::cout <<"f = " << f.re() <<" + "<< e.im()<<"i" <<std::endl;
    e.toString();
    std::cout <<std::endl;
    f.toString();
    return 0;
}
