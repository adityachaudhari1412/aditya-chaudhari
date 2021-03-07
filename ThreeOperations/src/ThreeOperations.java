/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner ;
public class ThreeOperations {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        System.out.printf("Please enter real number N1: \n" );
        double n1= in.nextDouble();
        System.out.printf("Please enter real number N2: \n" );
        double n2= in.nextDouble();
        double n3= n1*n2;
        double n4= n1/n2;
        double n5= Math.pow(n1,n2);
        System.out.printf("%6.6f*%6.6f = %6.2f\n",n1,n2, n3);
        System.out.printf("%6.6f / %6.6f = %6.2f\n",n1,n2, n4);
        System.out.printf("n1 raised to the power of n2 = %6.2f\n", n5);
        
    }
    
}
