
import java.io.BufferedReader;
import java.util.*;
import java.io.*;
import MemberList.*;
import TransactionList.*;
import BookList.*;


class LibraryManagement {
    MemberList ml;
    BookList bl;
    TransactionList tl;

    LibraryManagement() {
        ml = new MemberList(10000);
        bl = new BookList(10000);
        tl = new TransactionList(10000);
    }

    void run() throws IOException{
        int choice = 10;
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        do {
            System.out.println(
                    "1. Add a new book to book list\n2. Add more copies for a book\n3. Show all the book details\n4. Show a book detail\n5. Issue a book\n6. Add a member\n7. Show all members\n8. Show a particular member\n9. Return a book");
            choice = Integer.parseInt(br.readLine());
            switch (choice) {
            case 1:
                Book b = new Book();
                b.input();
                bl.addBook(b);
                break;

            case 2:
                System.out.println("Book ID : ");
                int id = sc.nextInt();
                int final_val;
                System.out.println("How many more copies were added : ");
                final_val = sc.nextInt();
                bl.addCopies(id, final_val);
                break;
            case 3:
                bl.displayList();
                break;
            case 4:
                System.out.println("Book ID : ");
                int id1 = sc.nextInt();
                bl.displayBookInformation(id1);
                break;
            case 5:
                System.out.println("Member ID : ");
                int memid = sc.nextInt();
                System.out.println("Book ID : ");
                int id2 = sc.nextInt();
                if (ml.existsMember(memid) != -1) {
                   {
                   	if(ml.addBooks(memid) != -1){
                    	if(bl.existsID(id2) != -1){
                        if(bl.removeCopies(id2, 1)!= -1)
                        	tl.addTransaction(memid, id2);
                        }
                        else{
                        	System.out.println("Book does not exist\n");
                        	
                        }
                    }
			}
                } else {
                    System.out.println("Member does not exist");
                }
                break;
            case 6:
                Member m = new Member();
                ml.insertMember(m);
                break;
            case 7:
                ml.displayList();
                break;
            case 8:
                System.out.println("Member ID : ");
                int mem = sc.nextInt();
                ml.displayMemberInformation(mem);
                break;
            case 9:
                System.out.println("Member ID : ");
                int m1 = sc.nextInt();
                System.out.println("Book ID : ");
                int b1 = sc.nextInt();
                if (tl.removeTransaction(m1, b1) != -1) {
                    ml.removeBooks(m1);
                    bl.addCopy(b1);
                }
                break;
            default:
                System.out.println("Invalid Input\n");

            }
            

        } while (choice != -1);
        //sc.close();
    }

    public static void main(String args[]) throws IOException{
        LibraryManagement lm = new LibraryManagement();
        lm.run();
    }
}
