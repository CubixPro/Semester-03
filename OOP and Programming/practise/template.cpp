#include<iostream>
using namespace std;

template<class T, class R>

void add_two_numbers(T t, R r){
    cout << (t + r) << '\n';
}

template<class T>
class Array{
    public:
    T* arr;
    
    int size;
    public:
    Array(int n){
        size = n;
        arr = new T[n];
    }
    ~Array(){
        cout << "Destructor has been called \n";
        delete(arr);
    }
    friend istream& operator>>(istream& t, Array<T> &arr){
        for(int i = 0 ; i < arr.size ; i++){
            t >> arr.arr[i];
        }
        return t;
    }
    friend ostream& operator<<(ostream& t, Array<T> &arr){
        for(int i = 0 ; i < arr.size ; i++){
            t << arr.arr[i] << " ";
        }
        return t;
    }
};

template<class T, class R>
class Complex{
	T real;
	R imaginary;
	public:
	void input(T r, R i)
	{
		real = r;
		imaginary = i;
	}
	
	void display()
	{
		cout <<  real << " + " << imaginary << "i";
	}
	
	Complex operator+(Complex<T, R>  a)
	{
		Complex c;
		c.real = real + a.real;
		c.imaginary = imaginary + a.imaginary;
		return c;
	}
	
	Complex operator-(Complex<T, R > a)
	{
		Complex c;
		c.real = real - a.real;
		c.imaginary = imaginary - a.imaginary;
		return c;
	}
	
	friend ostream & operator<<(ostream &t, Complex<T , R> &c){
	     t <<  c.real << " + " << c.imaginary << "i" << '\n';
	     return t;
	}
	friend istream& operator>>(istream &t, Complex<T, R > &c){
		t >> c.real;
		t >> c.imaginary;
		return t;
	}
};


		

int main(){
    Array<Complex<double, double> > arr(5);
    cin >> arr;
    cout << arr;

}