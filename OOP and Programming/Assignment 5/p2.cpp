#include<bits/stdc++.h>

using namespace std;


class Book
{
    protected: 
    int id;
    int copy_version;

    

    public:
    string title;
    string author;
    string publisher;
    bool already_issued;
    

    void set_id_copies(int id, int copies)
    {
        this->id = id;
        this->copy_version = copies;
        already_issued = false;
    }

    void BookInit()
    {
        cout << "ID : ";
        cin >> id;
        cout << "Serial Number : ";
        cin >> copy_version;
        cout << "Title : ";
        cin >> title;
        cout << "Author : ";
        cin >> author; 
        cout << "Publisher : ";
        cin >> publisher;
        already_issued = false;
    }

    int getID()
    {
        return id;
    }

    int getCopyVersion()
    {
        return copy_version;
    }
    
    void BookInitPartial();
    

};

class Member{

    protected:
    int idm;

    void getMemberType()
    {
        cout << "Enter student type : ";
        cin >> type;
        this->max_books = (type == 's') ? 2 : 10;
        books_issued = 0;
    }

    void getMemberDetails()
    {
        cout << "ID of member : ";
        cin >> idm;
        cout << "Name : ";
        cin >> name;
        cout << "Email : ";
        cin >> email;
        cout << "Address : ";
        cin >> address;
        
    } 

    public:
    string name;
    string email;
    string address;
    int books_issued;
    int max_books;
    char type;// s -> student and f -> faculty

    Member()
    {

    }

    Member(char type)
    {
        this->type = type;
        this->max_books = (type == 's') ? 2 : 10;
        books_issued = 0;
    }

    void MemberInit()
    {
        getMemberType();
        getMemberDetails();
    }

    bool validate()
    {
        if(max_books == books_issued)
        {
            return false;
        }
        else
        {
            return true;
        }
        //todo
        
    }

    int getMemberID()
    {
        return idm;
    }

};

vector <Book> books;
vector <Member> members;
vector <Book> book_transactions;

void Book::BookInitPartial()
{

    cout << "Title : ";
    cin >> title;
    cout << "Author : ";
    cin >> author;
    cout << "Publisher : ";
    cin >> publisher;
    for(int i = 0 ; i < books.size() ; i++)
    {
        if(title == books[i].title && author == books[i].author && publisher == books[i].publisher)
        {
            id == books[i].id;
            //copy_version = books[i].copy_version;

        }
    }
}
class Transaction : public Book, public Member{
    private :
    int pos;

    public: 
    char type;// b -> borrowing i -> issuing
    

    void TransactionInit()
    {
        cout << "Enter member ID";
        int mem_id;
        cin >> mem_id; 
        for(int i = 0 ; i < members.size() ; i++)
        {
            if (members[i].getMemberID() == mem_id)
            {
                pos = i;
                idm = mem_id;
                books_issued = members[i].books_issued;
            }
        }
        BookInitPartial();

    }
    void issueBook();
    void returnBook();
    void printTransaction();
    static void printAllTransactions();
};

vector<Transaction> transactions;

void Transaction::issueBook()
{
    for(int i = 0 ; i < transactions.size() ; i++)
    {
        if(transactions[i].idm == idm && already_issued == true)
        {
            books_issued++;
        }
    }

    if(validate())
    {
        books_issued++;
        bool found = false;
        for(int i = 0 ; i < books.size() ; i++)
        {
            if(books[i].title == title)
            {
                if(books[i].already_issued == false)
                {
                    found = true;
                    books[i].already_issued = true;
                    already_issued = books[i].already_issued;
                    set_id_copies(books[i].getID(), books[i].getCopyVersion());
                    transactions.push_back(*this); 
                    break;
                } 
            }
        }
        if(found == false)
        {
            cout << "Book is not available \n";
        }
    }
    else
    {
        cout << "More than required number of books have been issued.\n";
    }
   members[pos].books_issued = books_issued; 
}

void Transaction::returnBook()
{
    bool found = false;
    for(int i = 0 ; i < transactions.size() ; i++)
    {
        if(transactions[i].getID() == id && transactions[i].getCopyVersion() == copy_version )
        {
            transactions[i].already_issued = false;
            for(int j = 0 ; j < books.size() ; j++)
            {
                if(books[j].getID() == id && books[j].getCopyVersion() == copy_version)
                {
                    books[j].already_issued = false;
                }
            }
            printf("The book has been succesfully returned \n");
            found = true;
            
        }
    }
    if(found == false)
    {
        printf("Transaction not found \n");
    }
}

void Transaction::printTransaction()
{

    cout << id << copy_version << " " << title << "  " << idm ;
    if(already_issued == true)
    {
        cout << " Issued \n";
    }
    
    
    
}

void Transaction::printAllTransactions()
{
    for(int i = 0 ; i < transactions.size() ; i++)
    {
        cout << (i + 1);
        transactions[i].printTransaction();
        printf("\n");
    }
}


int main()
{
    
    printf("Enter books -->");
    int ch;
    scanf("%d", &ch);
    while(ch == 0)
    {
        Book b1;
        b1.BookInit();
        books.push_back(b1);
        scanf("%d", &ch);
    } 
    /*printf("Enter members -->");
    scanf("%d", &ch);
    while(ch == 0)
    {
        Member m1;
        
        m1.MemberInit();
        members.push_back(m1);
        scanf("%d", &ch);
    }*/
    Member m1, m2;
    m1.MemberInit();
    m2.MemberInit();
    members.push_back(m1);
    members.push_back(m2); 


   cout << "1. Issue a book \n2. Return a book\n3. See all transactions\n4. Bye\n";
   scanf("%d", &ch);
   while(ch != 4)
   {
       if(ch == 1)
       {
           Transaction t;
           t.TransactionInit();
           t.issueBook();
       }
       else if(ch == 2)
       {
           Transaction t;
           t.TransactionInit();
           t.returnBook();
       }
       else if(ch == 3)
       {
           Transaction::printAllTransactions();
       }
       else if(ch == 4)
       {
           break;
       }
       printf("\n");
       scanf("%d", &ch);
   }
} 


//add the members vector
//add the add new member and books functionality