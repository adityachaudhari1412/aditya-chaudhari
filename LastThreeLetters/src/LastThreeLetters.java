/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class LastThreeLetters {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         Scanner s= new Scanner(System.in);
       System.out.printf("Please enter a string, at least 3 letters long: " );
        String entered =s.next();
        int length= entered.length();
        if (entered.length() >3)
         {
             String s2= entered.substring(entered.length()-3);
        System.out.printf( "The last three letters are %s.\n",s2);
         }
         else
         {
         String s3=entered;
         System.out.printf("The last three letters are %s.\n",s3 );
         }
    }
    
}
