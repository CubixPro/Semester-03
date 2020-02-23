class Stock{
    int itcode;
    int qty;
    static int size = 0;
    Stock(){
        itcode = size;
        size++;
        qty = 10;
    }
    Stock(int q){
        itcode = size;
        size++;
        qty = q;
    }
    synchronized public void update(int add){
        qty += add;
        System.out.println("Final quantity : " + qty + "inside " + Thread.currentThread());
    }
}
class StockList{
    Stock stocks[];
    StockList(){
        stocks = new Stock[10];
        for(int i = 0 ; i < 10 ; i ++){
            stocks[i] = new Stock();
        }
    }
    public void update(int itc, int amt){
        for(int i  = 0 ; i < 10 ; i ++){
            if(stocks[i].itcode == itc){
                stocks[i].update(amt);
            }
        }
    }
}
class myRunnable implements Runnable{
    StockList s;
    myRunnable(StockList st){
        s = st;
    }
    public void run(){
        while(true){
            int itc = (int)(10 * Math.random());
            int amt = (int)(5  * Math.random());
            System.out.println("Adding " + amt + " to Stock : " + itc + " inside " + Thread.currentThread());
            s.update(itc, amt);
            
        }
    }
}

class myThread {
    public static void main(String args[]) throws InterruptedException{
        StockList s = new StockList();
        myRunnable r = new myRunnable(s);
        Thread t = new Thread(r);
        Thread t1 = new Thread(r);
        t.start();
        t1.start();
        t.join();
        t1.join();
    }
}