#include<iostream>
using namespace std;

class Transaction;

class Date{
    int month;
    int day;
    int year;

    public:
	void setInfo(int x, int y, int z)
	{
		month = y;
		day = x;
		year = z;
	}
    void getInfo()
    {
        scanf("%d/%d/%d", &day, &month, &year);
    }
    void printInfo()
    {
        printf("%d/%d/%d", day, month, year);
    }

};

class Balance{
	int acc_no;
	double balance;
	Date last_update;
	
	
	double getBalance()
	{
		return balance;
	}
	void printDetails()
	{
		cout << "Account Number : " << acc_no << '\n';
		cout << "Balance : " << balance << '\n';
		cout << "Date of last Transaction : " ;
		last_update.printInfo();
		cout << '\n';
	}
	public:
	void setBalance(double val)
	{
		balance = val;
	}
	
	friend class Transaction;
	public:
	Balance(int acc)
	{
		acc_no = acc;
		balance = 0.0;
		last_update.setInfo(1, 1, 2019);
	}
	
};

class Transaction{
	string type;
	int acc_no;
	double amount;
	Date newDate;
	public:
	void setTransaction(int acc, string t, double d)
	{
		acc_no = acc;
		type = t;
		amount = d;
		newDate.getInfo();
	}
	void doTransaction(Balance &b)
	{
		if(b.acc_no == acc_no)
		{
			if(type == "deposit")
			{
				b.balance = b.balance + amount;
				b.last_update = newDate;

			}
			else if(type == "withdrawal")
			{
				if(b.getBalance() >= amount)
				{
					printf("Transaction successful\n");
					b.balance = b.balance - amount;
					b.last_update = newDate;
				}
				else
				{
					printf("Insufficient Balance\n");
					
				}
			}
		}
		else
		{
			printf("Account details don't match\n");
		}
		b.printDetails();
	}		
};
/*int main()
{
	Balance b1(0), b2(1);
	Transaction t1, t2;
	t1.setTransaction(0, "deposit", 3000);
	t1.doTransaction(b1);
	t2.setTransaction(0, "withdrawal", 500);
	t2.doTransaction(b1);
}*/
	
