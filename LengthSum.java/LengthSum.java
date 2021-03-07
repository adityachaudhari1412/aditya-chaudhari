import java.util.Scanner;
public class LengthSum {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       
       System.out.printf("Please enter a string:  \n");
          String s1 = in.next();
       System.out.printf("Please enter a second string:  \n");
       String s2 = in.next();
      
       int length1 = s1.length();
       System.out.printf("The first string has length %s.\n",length1);
       
       int length2 =  s2.length();
       System.out.printf("The second string has length %s.\n",length2);
       int sum = length1 + length2 ;
       System.out.printf("The sum of the two lengths is %s.",sum);
       
       
       
       
    
    }
    
}
