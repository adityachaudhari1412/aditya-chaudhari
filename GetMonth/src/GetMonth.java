import java.util.*;
import java.io.File;

public class GetMonth {
     public static ArrayList<String> readfile(String filename)
    {
        File temp =new File(filename);
        Scanner input;
        try{
            input= new Scanner (temp);
            
        }
        catch (Exception e)
        {
            System.out.printf("Failed to open file %s \n", filename);
            return null;
            
        }
        ArrayList<String> result= new ArrayList();
        while(input.hasNextLine())
        {
            String line=input.nextLine();
            result.add(line);
        }
        input.close();
        return result;
    }
     public static int getMonth(String columns)
   {
       int result=0;
       
       String []month= columns.split("[ /]");
       if(month.length!=4)
       return 0;
       try
       {
           result=Integer.parseInt(month[1]);
       } 
           catch (Exception e)
           {
              return 0; 
           }
       return result;
   }
    public static void printMonths(String filename)
  {
    ArrayList<String> lines = readfile(filename);
    if (lines == null)
    {
      return;
    }
    for (int i = 1; i < lines.size(); i++)
    {    
      String line = lines.get(i);
      String[] columns = line.split(",");

      String date = columns[0];
      int line_month = getMonth(columns[0]);
      System.out.printf("row %d, month = %d\n", i, line_month);
    }
  }
 
  
  
   
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    while (true)
    {
      System.out.printf("Enter a filename (or q to quit): ");
      String filename = in.next();
      if (filename.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      printMonths(filename);
      System.out.printf("\n");
    }
    }
    
}
