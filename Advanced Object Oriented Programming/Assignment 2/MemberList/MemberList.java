package Member;
import java.io.BufferedReader;
import java.util.*;
import java.io.*;



class Date {
    int day, month, year;
    Date(int a, int b, int c){
        day = a;
        month = b;
        year = c;
    }

    void print() {
        System.out.println(day + "/" + month + "/" + year);
    }


}

class Member {
    int memberid;
    String name;
    Date dob;
    int books;
    static int total_books = 5;

    Member() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Member ID : ");
        memberid = sc.nextInt();
        sc.nextLine();
        System.out.println("Name : ");
        name = sc.nextLine();
        books = 0;
        dob = new Date(1, 1, 2000);
        //sc.close();
    }

    Member(int id, String t, Date dob) {
        memberid = id;
        name = t;
        this.dob = dob;
        books = 0;
    }

    void printMember() {
        System.out.println("Member ID : " + memberid + "\nName : " + name + "\nBooks Issued : " + books);
        dob.print();
    }
}

public class MemberList {
    int size;
    int max_size;
    Member members[];

    MemberList(int s) {
        max_size = s;
        s = 0;
        members = new Member[max_size];
        
    }

    int addBooks(int id) {
        int val = existsMember(id);
        if (members[val].books < Member.total_books) {
            members[val].books++;
            return 1;
        } else {
            System.out.println("Maximum books issued");
            return -1;
        }
    }

    int removeBooks(int id) {
        int val = existsMember(id);
        members[val].books--;
        return 1;
    }

    int existsMember(int x) {
        for (int i = 0; i < size; i++) {
            if (members[i].memberid == x) {
                return i;
            }

        }
        return -1;
    }

    int insertMember(Member m) {
        int val = existsMember(m.memberid);
        if (val == -1) {
            if (size < max_size) {
                members[size] = m;
                size++;
                return 1;
            } else {
                System.out.println("Member List is full");
                return -1;
            }
        } else {
            System.out.println("Member already exists");
            return -1;
        }
    }

    void displayList() {
        for (int i = 0; i < size; i++) {
            members[i].printMember();
        }
    }

    void displayMemberInformation(int val) {
        int id = existsMember(val);
        System.out.println(id);
        members[id].printMember();
    }
}

