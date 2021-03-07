/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class WeirdNumber {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       System.out.println("Enter a number: ");
       int N= in.nextInt();
        if(N%2!=0)
       {
           System.out.println("Weird");
       }
       else if((N>=2)&&(N<5))
       {
           System.out.println("Not weird");
       }
       else if((N>=6)&&(N<=20))
       {
           System.out.println("weird");
       }
       else
       {
           System.out.println("Not weird");
       }
    }
    
}
