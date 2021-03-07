    import java.util.Scanner;
    import java.util.ArrayList;
    import java.io.File;
    import java.io.PrintWriter;

    public class CheckPrimes {
      public static ArrayList<String> fileread( String filename)
    {
     File in = new File(filename);
    Scanner read;
    try
    {
        read=new Scanner(in);
    }
    catch( Exception e)
    {
        System.out.println("Error in opening file for reading");
        return null;
    }   
    ArrayList<String> result =new ArrayList();
    while(read.hasNextLine())
    {
        String line=read.nextLine();
        result.add(line);
    }
    read.close();
    return result;
    }    
    public static void checkPrimes(String infile, String outfile )
    {
        double number;
     ArrayList<String> lines=fileread(infile);
     PrintWriter out =null;
     try
     {
         out= new PrintWriter(outfile);
     }
     catch (Exception e)
     {
         System.out.println("Error in opening file for writing");
         return;
     }
  
     for(int i=0;i<lines.size();i++)
     {
         try
         {
             number=Double.parseDouble(lines.get(i));
         }
         catch (Exception e)
         {
             return;
         }
        
         boolean j=isPrime(number);
         if(j==true)
             out.printf("%.0f is prime \n",number);
        else
             out.printf("%.0f is not prime \n",number);
         
     }
    out.close();
    }
    public static boolean isPrime(double number)
    {
        if (number < 2)
        return false;
    else if (number <= 3 )
        return true;

    boolean notPrime = true;

    for (int k = 2; k <= Math.sqrt(number); k++) {
        notPrime = (number % k == 0);
        if (notPrime)
            break;
    }

    return !notPrime;
}
   
    public static void main(String[] args) {
    checkPrimes("in4.txt", "out4.txt");
    System.out.printf("Exiting...\n");
   
    }
    
}
