/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class CountDigits {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner in= new Scanner(System.in);
       System.out.printf("Please enter an integer: \n");
       int n= in.nextInt();
       if(n<0)
       {
           System.out.printf("%d is negative.\n", n);
       }
       else if((n>=0)&&(n<10))
       {
           System.out.printf("%d has one digit.\n", n);
       }
       else if((n>=10)&&(n<100))
       {
           System.out.printf("%d has two digits.\n", n);
       }
       else if((n>=100)&&(n<1000))
       {
           System.out.printf("%d has three digits.\n", n);
       }
       else if((n>=1000)&&(n<10000))
       {
           System.out.printf("%d has four digits.\n", n);
       }
       else if((n>=10000)&&(n<100000))
       {
           System.out.printf("%d has five digits.\n", n);
       }
       else if((n>=100000)&&(n<1000000))
       {
           System.out.printf("%d has six digits.\n", n);
       }
       else
       {
           System.out.printf("%d has more than six digits.", n);
       }
    }
    
}
