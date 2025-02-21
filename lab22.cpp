#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.

ComplexNumber operator+(double s,const ComplexNumber &c){
    return ComplexNumber(s+c.real,c.imag);
}
ComplexNumber operator-(double s,const ComplexNumber &c){
    return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = pow(c.real, 2) + pow(c.imag, 2);
    return ComplexNumber((real * c.real + imag * c.imag) / denominator,(imag * c.real - real * c.imag) / denominator);
}

ComplexNumber operator*(double s, const ComplexNumber &c) {
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c) {
    double denominator = pow(c.real, 2) + pow(c.imag, 2);
    return ComplexNumber((s * c.real) / denominator,(-s * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    if(real == c.real && imag == c.imag) return true;
    else return false;
}
double ComplexNumber::abs(){
    return sqrt(real*real + imag * imag);
}
double ComplexNumber::angle(){
        return atan2(imag,real)* 180 / M_PI;
}
ostream & operator<<(ostream &os,const ComplexNumber &c){
    if(c.real == 0 && c.imag != 0) return os<<c.imag<<"i";
    else if(c.real != 0 && c.imag == 0) return os<<c.real;
    else if(c.real == 0 && c.imag == 0) return os<<"0";
    if(c.imag>=0)return os<<c.real<<"+"<<c.imag<<"i";
    return os<<c.real<<c.imag<<"i";
}
bool operator==(double d,const ComplexNumber &c){
	if(d == c.real && 0 == c.imag) return true;
    else return false;
}
