import java.util.Scanner;
public class casting {

    
    public static void main(String[] args) {
           Scanner in = new Scanner(System.in);
          System.out.printf("Please enter a double number: ");
          double a = in.nextDouble();
          int a1 = (int) a;
          System.out.printf("a cast into an int becomes %d.",a1 );
    }
    
}
