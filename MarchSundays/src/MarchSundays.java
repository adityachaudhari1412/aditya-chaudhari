import java.util.Scanner;
public class MarchSundays {
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        System.out.printf("When is the first Sunday this March?");
        int date=in.nextInt();
        
        if((date<1)||(date>7))
        {
            System.out.printf("invalid entry\n");
        }
        else
        {
            System.out.printf("This March, Sundays fall on: \n");
            int i=date;
            while (i<=31)
            {
            System.out.printf(" March %d\n", i);
            i=i+7;
            }
        }
    }
    
}
