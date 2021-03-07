    import java.io.File;
    import java.util.*;
    public class SumIntegers {
     public static int sumIntegers(String filename)
  {   int q=0;
      int sum=0;
      ArrayList<String>a=readFile(filename);
      if(a==null)
      {
          System.out.printf(" 0\n");
      }
      
      for(int i=0;i<a.size();i++)
      {
          String line= a.get(i);
          try
          {
               q=Integer.parseInt(line);
          }
          catch(Exception e)
          {
              continue;
          }
          sum+=q;
      }
      return sum;
  }
  public static ArrayList<String> readFile(String filename)
  {
    File temp = new File(filename);
    Scanner inputfile;
    try
    {
      inputfile = new Scanner(temp);
    }
    catch (Exception e)
    {
      System.out.printf("0\n",
                        filename);
      return null;
    }

    ArrayList<String> result = new ArrayList<String>();
    while(inputfile.hasNextLine())
    {
      String line = inputfile.nextLine();
      result.add(line);
    }
    
    inputfile.close();
    return result;
  } 
 
    public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
    System.out.printf("Please enter the name of the input file: ");  
    String filename = in.nextLine();
 
    int result = sumIntegers(filename);
    System.out.printf("result = %d.\n", result); 
    }
    
}
