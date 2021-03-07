/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class MonthsToNumbers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
           Scanner in= new Scanner(System.in);
        System.out.printf("Please enter the name of a month: \n");
        String m= in.next();
        String m1= m.toLowerCase();
        String m2= "January";
        String m3="February";
        String m4="March";
        String m5="April";
        String m6="May";
        String m7="June";
        String m8="July";
        String m9="August";
        String m10="September";
        String m11="October";
        String m12="November";
        String m13="December";
        if (m1.equals(m2))
        {
            System.out.printf("%s is the first month.\n",m2);
        }    
        else if (m1.equals(m3.toLowerCase()))
        {
            System.out.printf("%s is the second month.\n",m3);
        }
        else if (m1.equals(m4.toLowerCase()))
        {
            System.out.printf("%s is the third month.\n",m4);
        }
        else if (m1.equals(m5.toLowerCase()))
        {
            System.out.printf("%s is the fourth month.\n",m5);
        }
        else if (m1.equals(m6.toLowerCase()))
        {
            System.out.printf("%s is the fifth month.\n", m6);
        }
        else if (m1.equals(m7.toLowerCase()))
        {
            System.out.printf("%s is the sixth month.\n", m7);
        }
        else if (m1.equals(m8.toLowerCase()))
        {
            System.out.printf("%s is the seventh month.\n", m8);
        }
        else if (m1.equals(m9.toLowerCase()))
        {
            System.out.printf("%s is the eighth month.\n", m9);
        }
        else if (m1.equals(m10.toLowerCase()))
        {
            System.out.printf("%s is the ninth month.\n", m10);
        }
        else if (m1.equals(m11.toLowerCase()))
        {
            System.out.printf("%s is the tenth month.\n", m11);
        }    
        else if (m1.equals(m12.toLowerCase()))
        {
            System.out.printf("%s is the eleventh month.\n", m12) ;
        }
        else if (m1.equals(m13.toLowerCase()))
        {
            System.out.printf("%s is the twelveth month.\n", 13);
        }
        else
        {
            System.out.printf("Unknown month: %s\n",m );
        }
    }
    
}
