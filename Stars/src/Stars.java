   
   
    import java.util.Scanner;
    public class Stars {
    public static void main(String[] args) {
       Scanner in= new Scanner(System.in);
        System.out.printf("Enter a positive integer N > 0: ");
        int N=in.nextInt();
        if(N>0)
        {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
                System.out.print("*");
            System.out.println("");
        }
        System.out.println("Exiting...");
        }
        else
        {
            System.out.println("Exiting...");
        }
    }
    
}
