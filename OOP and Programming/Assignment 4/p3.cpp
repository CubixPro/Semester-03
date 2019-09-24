#include<iostream>

using namespace std;

class Array{
	int *p;
	int size;
	public:
	Array(int size)
	{
	 	if(size >= 1)
	 	{
	 		p = new int[size];
            this->size = size;
	 		for(int i = 0 ; i < size ; i++)
	 		{
                 p[i] = 0;
	 		}
	 	}
	 	else
	 	{
            this->size = 0;
	 		p = NULL;
	 	}
	}
	 ~Array()
	{
			if (p!= NULL)
				delete(p);
	}
	Array(const Array &b)
	{
		size = b.size;
		if(size != 0)
		{
			p = new int[size];
		}
		else 
			p = NULL;
		for(int i = 0 ;  i < size ; i++)
		{
			p[i] = b.p[i];
		}
	}
	void operator=(const Array t)
	{
		size = t.size;
		if(size != 0)
		{
			p = new int[size];
		}
		else 
			p = NULL;
		for(int i = 0 ;  i < size ; i++)
		{
			p[i] = t.p[i];
		}
	}
	Array operator+(const Array b)
	{
		if(size == b.size)
		{
			Array final_a(size);
			for(int i = 0 ; i < size ; i++)
			{
				final_a.p[i] = p[i] + b.p[i];
			}
            //final_a.display();
			return final_a;
		}
		else
		{
			cout << "Addition not possible \n";
			Array final_a(0);
			return final_a;
		}
		
	}
	Array operator*(int b)
	{
			Array final_a(size);
			for(int i = 0 ; i < size ; i++)
			{
				final_a.p[i] = p[i] * b; 
			}
            //final_a.display();
			return final_a;
		
		
	}
	int operator[](int k)
	{
		if(k < size)
		{
			return p[k];
		}
		else 
		 return -1;
	}
	void display()
	{
		if(size == 0)
		{
			printf("Null array");

		}
		else
		{
			for(int i = 0 ; i < size ; i++)
			{
				printf("%d ", p[i]);
			}
		}
        printf("\n");
	}
    void input()
    {
        for(int i = 0 ; i < size ; i++)
        {
            cin >> p[i];
        }
    }
	friend Array operator*(int k, Array b)
	{
		Array final_a(b.size);
		for(int i = 0 ; i < b.size ; i++)
		{
			final_a.p[i] = k * b.p[i];
		}
		return final_a;
	}
};

int main()
{
	Array a(5);
    a.input();
	Array b(5);
    b.input();
    Array c = 4 * a * 4;
	c.display();	
}
		