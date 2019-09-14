class Array{
	int *p;
	int size;
	public:
	 Array(int size)
	 {
	 	if(size >= 1)
	 	{
	 		p = new int[size];
	 		for(int i = 0 ; i < size ; i++)
	 		{
	 			cin >> p[i];
	 		}
	 	}
	 	else
	 	{
	 		p = NULL;
	 	}
	 }
	 ~Array()
		{
			if (p!= NULL)
				delete(p);
		}
	Array(Array &b)
	{
		size = b.size;
		if(size != 0)
		{
			p = new int[size];
		}
		else 
			p = null;
		for(int i = 0 ;  i < size ; i++)
		{
			p[i] = b.p[i];
		}
	}
	Array operator=(Array t)
	{
		size = a.size;
		if(size != 0)
		{
			p = new int[size];
		}
		else 
			p = null;
		for(int i = 0 ;  i < size ; i++)
		{
			p[i] = b.p[i];
		}
	}
	Array operator+(Array b)
	{
		if(size == b.size)
		{
			Array final_a(size);
			for(int i = 0 ; i < size ; i++)
			{
				final_a[i] = p[i] + b.p[i];
			}
			return final_a;
		}
		else
		{
			cout << "Addition not possible \n";
			Array final_a(0);
			return final_a;
		}
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
}

int main()
{
	Array a[5];
	Array b[5];
	Array c = a + b;
	
	
		}
		
