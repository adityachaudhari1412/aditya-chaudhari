/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner ;
public class ThreeWords {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      Scanner in= new Scanner(System.in);
      System.out.printf("Please enter an integer N:\n");
      int n= in.nextInt();
      System.out.printf("Please enter a word with at least N and at most 20 letters:\n");
      System.out.printf("Please enter a word with at least N and at most 20 letters:\n");
      System.out.printf("Please enter a word with at least N and at most 20 letters:\n");
      String s= in.next();
      String s1=in.next();
      String s2=in.next();
      String s3= s.substring(0,n);
      String s4= s1.substring(0,n);
      String s5= s2.substring(0,n);
      System.out.printf("%s starts with %s\n",s,s3);
      System.out.printf("%s starts with %s\n",s1,s4);
      System.out.printf("%s starts with %s\n",s2,s5);
      
      
              
      
    }
    
}
