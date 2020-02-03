#include<bits/stdc++.h>

using namespace std;

#define MAX_BOOK_SIZE 1000
#define MAX_MEMBER_SIZE 1000
#define MAX_TRANSACTION_SIZE 10000

class TransactionList;

class Book{
    protected:
    string title;
    string author;
    string publisher;
    int id;
    public:
    int snNO;
    friend class BookList;

    public:
    void createBook(){
        cin >> title;
        cin >> author;
        cin >> publisher;
        cin >> id;
       // return this;
    }
    
    void setSerial(int num)
    {
        snNO = num;
    }

    bool compareBook(Book b)
    {
        if(b.title == title && b.author == author && b.id == id && b.snNO == snNO && b.publisher == publisher)
        {
            return true;
        }
        return false;
    }
    
    void print()
    {
        cout << title << " " << author; 
    }
};

class BookList{
    
    static int curr_books; 
    string _books[MAX_BOOK_SIZE][4];//0-2=> details 3=>avaibility
    int _booksID[MAX_BOOK_SIZE][3];

    public:void addNewBook(Book& b)
    {
        bool found = false;
        for(int i = 0 ; i < curr_books ; i++ )
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher )
            {
                _books[i][3] = _books[i][3] + '1';
                _booksID[i][1]++;
                _booksID[i][2]++;
                found = true;
                break;
            }

        }
        if(found == false)
        {
            curr_books++;
            if(curr_books <= MAX_BOOK_SIZE)
            {
                _books[curr_books - 1][0] = b.title;
                _books[curr_books - 1][1] = b.author;
                _books[curr_books - 1][2] = b.publisher;
                _books[curr_books - 1][3] = "1";
                _booksID[curr_books - 1][0] = b.id;
                _booksID[curr_books - 1][1] = 1;
                _booksID[curr_books - 1][2] = 1;
                
            }
        }
    }

    int getBookSnNO(Book& b)//returns the snNo of the next available book
    {
        for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher && _booksID[i][2] != 0)
            {
                //_booksID[i][2]--;
                for(int j = 0 ; j < _books[i][3].length() ; j++)
                {
                    if(_books[i][3][j] == '1')
                    {
                        //b.snNO = j + 1;
                        //_books[i][3][j] = '0';
                        return j;
                    }
                }
            }

        }
        return -1;

    }
    
    bool bookExists(Book& b)
    {
            for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher && _booksID[i][2] != 0)
            {
                    return true;
            
            }
        }
    return false;
    }

   void removeBook(Book& b)
   {
       int j = returnBookID(b);
       int k = getBookSnNO(b);
       _books[j][3][k] = '0';
       _booksID[j][2]--;
       b.setSerial(k);
   }

    void returnBook(Book b)
    {
        int j = returnBookID(b);
        int k = b.snNO;
        _books[j][3][k] = '1';
        _booksID[j][2]++;
    }

    int returnBookID(Book b)
    {
            for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher)
            {
                    return i;
            
            }
        }
        return -1;
    
    }
    
   void printBookList()
   {
       for(int i = 0 ; i < curr_books ; i++)
       {
           cout << _books[i][0] << "  " << _books[i][3] << "  " << _booksID[i][1] << '\n'; 
       }
   } 

     

};

 int BookList::curr_books = 0;

class Member{
    protected:
    string name;
    string id;
    int issued_books;
    int total_books;
    friend class MemberList;

    public:
    bool compareMembers(Member m)
    {
        if(m.id == id && m.name == name)
            return true;
        return false;
    }

    void createMember()
    {                                                                                                                                                                                                            
        cin >> name;
        cin >> id;
        issued_books = 0;
    }

    void print()
    {
       cout << name << " " << id; 
    }

    bool is_Eligible()
    {
        if(issued_books < total_books)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void update(int num)
    {
        issued_books-=num;
    }
    
};

class Student: public Member{
public:    
    Student(){
        issued_books = 0;
        total_books = 2; 
    }
};

class Faculty: public Member{
public:
    Faculty(){
        issued_books = 0;
        total_books = 10;
    }
};

class MemberList{
    static int curr_member_size;
    Member _members[MAX_MEMBER_SIZE]; 

    public:
    bool validateMember(Member m)
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            if(m.name == _members[i].name && m.id == _members[i].id)
            {
                return true;
            }
        }
        return false;
    }

    int findID(Member m)
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            if(m.name == _members[i].name && m.id == _members[i].id)
            {
                return i;
            }
        }
        return -1;
 
    }

    Member& returnMember(MemberList& m1, int i)
    {
        return m1._members[i];
    }

    
    int addNewMember(Member m)
    {
        if(curr_member_size <= MAX_MEMBER_SIZE && validateMember(m) == false )
        {
            _members[curr_member_size] = m;
            curr_member_size++;
            return 0;
        }
        else
        {
            return -1;
        }
    }

    void printMembers()
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            _members[i].print();
        }
    }

};
class Date{
    int month;
    int day;
    int year;

    public:
    void getDate()
    {
        scanf("%d/%d/%d", &day, &month, &year);
    }

    void printDate()
    {
        printf("%d/%d/%d", day, month, year);
    }


};

class Transaction{
   
    Date d;
    protected:
    Member m;
    Book b;

    public:
    void InitializeTransaction(MemberList m1, BookList b1){
        d.getDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createBook();
            if(b1.bookExists(b))
            {
                printf("Processing Transaction\n");
            }
            else
            {
                printf("Book not available.\nTry again Later\n");
            }
            
            
        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
        }
    }

    void initializeDate()
    {
        d.getDate();
    }

    void printTransaction() {
            m.print();
            cout << " ";
            b.print();
    

    }

    friend class TransactionList;
};

class Issue:public Transaction{
    public:
    void issueBook(MemberList& m1, BookList& b1, TransactionList& t1);
    void InitializeTransaction(MemberList m1, BookList b1){
        initializeDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createBook();
            if(b1.bookExists(b))
            {
                printf("Processing Transaction\n");
            }
            else
            {
                printf("Book not available.\nTry again Later\n");
            }
            
            
        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
        }
    }

};

class Return:public Transaction{
    public:
    void returnBook(MemberList& m1, BookList& b1, TransactionList& t1);
        
    int  InitializeTransaction(MemberList m1, BookList b1){
        initializeDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createBook();
            int i = b1.returnBookID(b);
            if(i == -1)
            {
                printf("This is not a library book. \n");
                return -1;
            }  
            else
            {
                printf("Processing Transaction.\n");
                return 0;
            }
        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
            return -1;
        }
    }

};

int MemberList::curr_member_size = 0;



class TransactionList{
    Transaction _transactions[MAX_TRANSACTION_SIZE];
    string status[MAX_TRANSACTION_SIZE];
    static int curr_transaction_size;

    public:
    void addTransaction(Issue i)
    {
        _transactions[curr_transaction_size] = i;
        status[curr_transaction_size] = "Issued";
        curr_transaction_size++;
    }

    void addTransaction( Return r)
    {
        if(existsTransaction( r) != -1)
        {
            int i = existsTransaction( r);
            if(status[i] == "Issued")
            {
                status[i] = "Returned"; 
                printf("List Updated\n");
            }    

        }
        else{
            printf("Wrong book returned. Try again\n");
        }
    }

    void printAllTransactions()
    {
        for(int i = 0 ; i < curr_transaction_size ; i++)
        {
            _transactions[i].printTransaction();
            cout << " " << status[i] << '\n';
        }
    }

    int existsTransaction( Return r)
    {
        for(int i = 0 ; i < curr_transaction_size ; i++)
        {
            if(_transactions[i].m.compareMembers(r.m) && _transactions[i].b.compareBook(r.b) && status[i] == "Issued")
            {
               return i;
                
            } 
        }
        return -1;
    }

};

int TransactionList::curr_transaction_size = 0;

void Issue::issueBook(MemberList& m1, BookList& b1, TransactionList& t1)
{
        InitializeTransaction(m1, b1);
        int i = m1.findID(m);
        if(m1.returnMember(m1, i).is_Eligible())
        {
            if(b1.bookExists(b))
            {
            b1.removeBook(b);
            printf("Your book has been issued\n");
            m1.returnMember(m1, i).update(-1);
            cout << "Serial Number : " << b.snNO << "\n";
            t1.addTransaction(*this); 
            }
        }
        else
        {
            printf("You have already borrowed maximum number of books\n");
        }
        //Add transaction to transaction list       

}

void Return::returnBook(MemberList& m1, BookList& b1, TransactionList& t1)
{
        if(InitializeTransaction(m1, b1) != -1)
        {
            int i;
            cin >> i;
            b.setSerial(i);
            b1.returnBook(b);
            int j = m1.findID(m);
            Member& final_m = m1.returnMember(m1, j);
            final_m.update(1);
            t1.addTransaction(*this); 
        }
    
}


class Library{
    public:
    void start(){
        BookList bl1;
        MemberList ml1;
        TransactionList tl1; 

            int choice;
        do{
            cout << "1. Add a new book\n2. Add a new member\n3. Issue a book\n4. Return a book\n5. Show all transactions till now\n6. Exit Library\n";
            cout << "Choice : ";
            scanf("%d", &choice);
            if(choice == 1)
            {
                Book b;
                b.createBook();
                bl1.addNewBook(b);
            }
            else if(choice == 2)
            {
                cout << "Enter member type : ";
                string s;
                cin >> s;
                if(s == "student")
                {
                    Student s1;
                    s1.createMember();
                    ml1.addNewMember(s1);
                }
                else if(s == "faculty")
                {
                    Faculty f;
                    f.createMember();
                    ml1.addNewMember(f);
                }
                
            }
            else if(choice == 3)
            {
                Issue i;
                i.issueBook(ml1, bl1, tl1);
            }

            else if(choice == 4)
            {
                Return r;
                r.returnBook(ml1, bl1, tl1);

            }
            else if(choice == 5)
            {
                tl1.printAllTransactions();
            }
        }while(choice != 6);
    }
};

int main()
{
    
    Library l;
    l.start();
}


