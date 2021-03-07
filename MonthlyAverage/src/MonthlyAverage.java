import java.util.*;
import java.io.File;

public class MonthlyAverage {
 public static int userInteger(String message)
  {
    Scanner in = new Scanner(System.in);
    int result;
    while (true)
    {
      System.out.printf(message);
      String s = in.next();
      if (s.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      
      try
      {
        result = Integer.parseInt(s);
      } 
      catch (Exception e)
      {
        System.out.printf("%s is not a valid number, try again.\n\n", s);
        continue;
      }
      
      return result;
    }
  }  
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
  public static String [][] readSpreadsheet(String filename)
    {
        ArrayList<String> lines= readfile(filename);
        if(lines==null)
        {
            return null;
        }
        int rows= lines.size();
        String [][]result= new String[rows][];
        
            
        for(int i=0;i<lines.size();i++)
        {
            String line=lines.get(i);
            String []values=line.split(",");
            result[i]=values;
        }
        return result;
    }
  
  
  public static String columnName(String filename,int column)
    {
        String name="";
       int sum=0;
        String [][]lines=readSpreadsheet(filename);
        if(lines==null)
            return null;
        if(column<lines[0].length)
            return lines[0][column];
        else
            return null;
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
  public static double monthlyAverage(String filename, int column, int month)
  {
      double sum=0,num=0;
      int count=0;
      boolean found=false;
      String [][]lines=readSpreadsheet(filename);
      for(int i=1;i<lines.length;i++)
      {
          if(lines[i].length<=column)
              continue;
          try{
              num=Double.parseDouble(lines[i][column]);
          }
          catch(Exception e)
          {
              continue;
          }
          int currentmonth=getMonth(lines[i][0]);
          if(currentmonth==month)
          {
              sum+=num;
              count++;
              found=true;
          }
          
      }
      if(found==false)
          return -1;
      return sum/count;
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
      int column = userInteger("Enter a column: ");
      String name = columnName(filename, column);
      if (name == null)
      {
        System.out.printf("Failed to extract a valid column name for column %d of %s\n\n",
                          column, filename);
        continue;
      }
      int month = userInteger("Enter a month: ");
      
      double average = monthlyAverage(filename, column, month);
      if (average == -1.00)
      {
        System.out.printf("In file %s, there is no data for %s for month %d.\n\n",
                          filename, name, month);
      }
      else
      {
        System.out.printf("In file %s, the average %s for month %d is %.2f.\n\n",
                          filename, name, month, average);
      }
    }

    }
    
}
