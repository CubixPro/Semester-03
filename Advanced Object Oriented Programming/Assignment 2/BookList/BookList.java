package Book;
import java.io.BufferedReader;
import java.util.*;
import java.io.*;

//import javax.imageio.plugins.tiff.ExifTIFFTagSet;

class Book {
    int bookid;
    String title;

    Book() {

    }

    Book(int id, String t) {
        bookid = id;
        title = t;
    }

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Book ID : ");
        bookid = sc.nextInt();
        sc.nextLine();
        System.out.print("Title : ");
        title = sc.nextLine();
        //sc.close();

    }

    void printBook() {
        System.out.println("Book ID : " + bookid + "\nTitle : " + title);
    }
}

public class BookList {
    int size;
    int max_size;
    int bookids[];
    String titles[];
    int total_copies[];
    int available[];

    BookList(int s) {
        max_size = s;
        size = 0;
        bookids = new int[max_size];
        titles = new String[max_size];
        total_copies = new int[max_size];
        available = new int[max_size];
    }

    int existsID(int id) {
        for (int i = 0; i < size; i++) {
            if (id == bookids[i])
                return i;
        }
        return -1;
    }

    int addBook(Book b) {
        int val = existsID(b.bookid);
        if (val == -1) {
            System.out.println("Unique Book ID identified");
            if (size < max_size) {
                bookids[size] = b.bookid;
                titles[size] = b.title;
                total_copies[size] = 1;
                available[size] = 1;
                size++;
                return 1;
            } else {
                System.out.println("Cannot add anymore books");
                return -1;
            }
        } else {
            System.out.println("Book ID is not unique, book cannot be added to List");
            return -1;
        }
    }

    int addCopies(int id, int new_val) {
        int val = existsID(id);
        if (val == -1) {
            System.out.println("Book does not exist");
            return val;
        } else {
            available[val] += new_val;
            total_copies[val] += new_val;
            return 1;
        }
    }
    
    int addCopy(int id){
    	int val = existsID(id);
    	if(val != -1)
    	{
    		available[val]++;
    		return 1;
    	}
    	return -1;
    }

    int removeCopies(int id, int sub) {
        int val = existsID(id);
        if (val == -1) {
            System.out.println("Book does not exist");
            return val;
        } else {
            available[val] -= sub;
            if (available[val] < 0) {
                System.out.println("No more books left, cannot be issued/removed");
                available[val] = 0;
                return -1;
            }
            return 1;
        }

    }

    void displayBookInformation(int id) {
        int val = existsID(id);
        if (val != -1) {
            Book b = new Book(bookids[val], titles[val]);
            b.printBook();
        } else {
            System.out.print("Book does not Exist.\n");
        }
    }

    void displayList() {
        System.out.println("Book ID\tTitle\tCopies Left");
        for (int i = 0; i < size; i++) {
            System.out.println(bookids[i] + "\t" + titles[i] + "\t" + available[i]);
        }
    }
    
    public static void main(String args[]){}

}

