#include<iostream>

using namespace std;

class Complex{
	int real;
	int imaginary;
	public:
	void input(int r, int i)
	{
		real = r;
		imaginary = i;
	}
	
	void display()
	{
		cout <<  real << " + " << imaginary << "i";
	}
	
	Complex operator+(Complex a)
	{
		Complex c;
		c.real = real + a.real;
		c.imaginary = imaginary + a.imaginary;
		return c;
	}
	
	Complex operator-(Complex a)
	{
		Complex c;
		c.real = real - a.real;
		c.imaginary = imaginary - a.imaginary;
		return c;
	}
	
	friend ostream & operator<<(ostream &t, Complex &c){
	     t <<  c.real << " + " << c.imaginary << "i" << '\n';
	     return t;
	}
	friend istream& operator>>(istream &t, Complex &c){
		t >> c.real;
		t >> c.imaginary;
		return t;
	}
};

int main()
{
	Complex c1, c2;
	cin >> c1;
	cout << c1;
	cin >> c2;
	cout << c2;
	Complex c3 = c1 + c2;
	cout << c3;
}
		

