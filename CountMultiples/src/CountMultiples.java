    

    import java.util.Scanner;
    public class CountMultiples{
    public static void main(String[] args) {
    Scanner in= new Scanner(System.in);
        System.out.print(" Enter an integer M: ");
        int M=in.nextInt();
        System.out.print(" Enter an integer N: ");
        int N=in.nextInt();
        int num=0;
        if(M<N)
        {
            
            
            for (int i=M;i<=N;i++)
            {
                if(i%11==0)
                {
                    num++;
                }
                
            }   
            System.out.printf("%d numbers between %d and %d are multiples of 11. \n", num,M,N);
        }
        else 
        {
            System.out.printf("0 numbers between %d and %d are multiples of 11.\n",M,N);
        }
    }
    
}
