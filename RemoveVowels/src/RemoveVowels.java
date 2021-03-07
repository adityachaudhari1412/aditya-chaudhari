
        import java.util.Scanner;
        public class RemoveVowels {
        public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.printf("Enter a word: ");
          String a= in.next();
        int b= a.length();
        String c= "AEIOUaeiou";
        String d="";
       
        for(int i=0;i<b;i++)
        {
            if(c.indexOf(a.charAt(i))==-1)
               d=d+a.charAt(i);
               
            }
        System.out.printf("%s \n",d);
        System.out.print("Exiting... \n");
        }
    }
         

