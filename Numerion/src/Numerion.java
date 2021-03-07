
 import java.util.Scanner;
public class Numerion {

    
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        System.out.printf("Enter an integer N: ");
        int N= in.nextInt();
       boolean N_is_numerion = false;
         int i=0;
         while(i<N)
         {
         if(N==i*i+i)
         {
         N_is_numerion=true;
         }
         i++;
         }
         if(N_is_numerion)
         {
         System.out.printf(" %d is a holy number in Numerion.\n", N);
         }
         else
         {
         System.out.printf("%d is not a holy number in Numerion.\n",N); 
         }
         System.out.printf("Exiting...");
    }
    
}
