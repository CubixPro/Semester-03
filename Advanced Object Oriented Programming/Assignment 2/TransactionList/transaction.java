package TransactionList;
import java.io.BufferedReader;
import java.util.*;
import java.io.*;


public class TransactionList {
    int bookids[];
    int memberids[];
    int max_size;
    int size;

    TransactionList(int s) {
        max_size = s;
        size = 0;
        memberids = new int[s];
        bookids = new int[s];
    }

    int addTransaction(int memid, int bookid) {
        if (size < max_size) {
            memberids[size] = memid;
            bookids[size] = bookid;
            size++;
            return 1;
        } else {
            System.out.println("Too many Transactions");
            return -1;
        }
    }

    int existsTransaction(int memid, int bookid) {
        for (int i = 0; i < size; i++) {
            if (memberids[i] == memid && bookids[i] == bookid) {
                return i;
            }
        }
        return -1;
    }

    int removeTransaction(int memid, int bookid) {
        int val = existsTransaction(memid, bookid);
        if (val == -1) {
            System.out.println("No such transaction\n");
            return -1;
        } else {
            memberids[val] = -9999;
            return 1;

        }
    }

}

