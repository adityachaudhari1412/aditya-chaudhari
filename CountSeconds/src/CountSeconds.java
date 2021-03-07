/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */import java.util.Scanner;
public class CountSeconds {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.printf("Please specify the number of seconds (between 1 and 86400): ");
        int n1= in.nextInt();
        if(n1>86400)
        {
         System.out.printf("The number of seconds must be between 1 and 86400.\n");
         }
        int n2= n1/3600;
        int n3= n1%3600;
        int n4= n3/60;
        int n5= n3%60;
        System.out.printf("%d seconds correspond to %d hours, %d minutes, and %d seconds.", n1,n2,n4,n5);
    }
    
}
