/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner ;
public class FourCapitalizations {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.printf("Please enter a string:");
        String entered= s.nextLine();
        System.out.printf("1st version: %s\n",entered);
        String s1= entered.toUpperCase();
        System.out.printf("2nd version: %s\n",s1);
        String s2= entered.toLowerCase();
        System.out.printf("3rd version: %s\n",s2);
        String s3= entered.substring(0, 1).toUpperCase() + entered.substring(1).toLowerCase();
        System.out.printf("4th version: %s\n",s3);
    }
    
}
