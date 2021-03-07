/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class DivisibilityTests {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        System.out.printf("Please enter an integer: \n");
        int n= in.nextInt();
        if(n<0)
        {
            System.out.printf("The number is negative.\n");
        }
        else if((n%2==0)&&(n%3==0))
        {
            System.out.printf("The number is even and divisible by 3.\n");
        }
        else if((n%2==0)&&(n%3!=0))
        {
            System.out.printf("The number is even and not divisible by 3.");
        }
        else if((n%2!=0)&&(n%3==0))
        {
            System.out.printf("The number is odd and divisible by 3.");
        }
        else
        {
            System.out.printf("The number is odd and not divisible by 3.");
        }
    }
    
}
