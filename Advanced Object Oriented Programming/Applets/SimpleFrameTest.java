import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class SimpleFrameTest{
    public static void main(String [] args){
        
                MyWindow frame = new MyWindow();
                
            }
        
    }

 class SimpleFrame extends JFrame{
    private static final int wid = 300;
    private static final int ht = 200;
    public SimpleFrame(){
        setSize(wid, ht);
    }
}
class MyWindow extends JFrame{
    JPanel p;
    JLabel l1, l2;
    JTextField t1, t2;
    JButton b;
    MyWindow(){
        super();
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        buildPanel();
        add(p);
        setVisible(true);
        //System.exit(0);
    }
    void buildPanel(){
        p = new JPanel();
        p.setLayout(new FlowLayout());
        l1 = new JLabel("First number");
        l2 = new JLabel("Second Number");
        t1 = new JTextField(10);
        t2 = new JTextField(10);
        p.add(t1, FlowLayout.LEFT);
        p.add(l1, FlowLayout.CENTER);
        p.add(t2, FlowLayout.LEFT);
        p.add(l2, FlowLayout.CENTER);
        b = new JButton("ADD");
        b.addActionListener(new MyListener());
        p.add(b, FlowLayout.LEFT);
    }
    public class MyListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            int u1, u2;
            String s1, s2;
            s1 = t1.getText();
            s2 = t2.getText();
            u1 = Integer.parseInt(s1);
            u2 = Integer.parseInt(s2);
            JOptionPane.showMessageDialog(null, "Sum of " + s1 + " and " + s2 + " is " + (u1 + u2));
        }
    }
}
