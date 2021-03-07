
import java.util.Scanner;

public class PrintPowers {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.printf("Enter a positive integer N > 1: ");
        double N = in.nextInt();
        if (N > 1) {
            double M = 0;
            for (double i = 0; i <= M; i++) {
                M = Math.pow(N, i);
                if (M >= 40000) {
                    break;
                }
                System.out.printf("%.0f\n", M);
            }

        } 
        System.out.println("Exiting...");
        

    }

}
