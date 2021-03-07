import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.PrintWriter;
public class phonebook {
  public static void savePhonebook(String [][] data, String name, String number)
    {
        PrintWriter out= null;
        try
        {
            out= new PrintWriter("phonebook.txt");
            
        }
        catch (Exception e)
        {
            System.out.printf("Failed to open file 'phonebook.txt' for writing");
        }
        
                  for(int i=0;i<data.length;i++)
                  {
                    if(data.length!=2)
                        continue;
                          out.printf("%s,%s \n",data[i][0],data[i][1]);
                  }
                   out.printf("%s,%s \n",name,number);
                   out.close();
        
    }
    
  public static String[][] inputNewEntry(String[][] data)
  {
    Scanner in = new Scanner(System.in);
    
    System.out.printf("\nEnter a name: ");
    String name = in.nextLine();
    System.out.printf("\nEnter a number: ");
    String number = in.nextLine();
   savePhonebook(data, name, number);
    data = readPhonebook();
    return data;
  } 
  
  public static void searchData(String [][]data)
  {
      Scanner in= new Scanner(System.in);
      System.out.println("Enter part of the name: ");
      String s= in.nextLine();
      s=s.toLowerCase();
      for(int i=0;i<data.length;i++)
      {
         String name=data[i][0].toLowerCase();
       if(data[i].length!=2)
           continue;
         if(name.indexOf(s)!=-1)
         {
             System.out.printf("%20s: %s\n",data[i][0],data[i][1]);
         }
      }
  }
  
  
  public static String[][] processOption(String[][] data, String option)
  {
    if (option.equals("1"))
    {
      printSpreadsheet(data);
      
    }
    else if (option.equals("2"))
    {
      data = inputNewEntry(data);
    }
    else if (option.equals("3"))
    {
     searchData(data);
    }
    else if (option.equals("q"))
    {
      System.out.printf("Exiting...\n");
      System.exit(0);
    }
    else
    {
      System.out.printf("Unrecognized option %s.\n", option);
    }
    
    return data;
  }
  
  public static String askOption()
  {
    Scanner in = new Scanner(System.in);
    
    System.out.printf("\n1: Print phonebook.\n");
    System.out.printf("2: Input a new entry.\n");
    System.out.printf("3: Search by name.\n");
    System.out.printf("q: Quit program.\n");
    System.out.printf("Please enter an option: ");
    String option = in.next();
    return option;
  }

  public static ArrayList<String> readfile(String filename)
  {
      File temp= new File(filename);
      Scanner input;
      try
      {
          input =new Scanner(temp);
      }
      catch (Exception e)
      {
       System.out.printf("Failed to open file %s \n", filename);
            return null;   
      }
      ArrayList<String> result = new ArrayList();
      while (input.hasNextLine())
      {
          String line= input.nextLine();
          result.add(line);
      }
      input.close();
      return result;
  }
  public static String [][] readPhonebook()
  {
      ArrayList<String> lines=readfile("phonebook.txt");
      String [][]result= new String [lines.size()][];
      for(int i=0;i<lines.size();i++)
      {
          String line=lines.get(i);
          String []values= line.split(",");
          result[i]=values;
      }
      return result;
      
  }
  
  public static void printSpreadsheet(String [][]data)
  {
      int count=0;
      for(int i=0;i<data.length;i++)
      {
         
              
              System.out.printf("%4d: %20s,%s \n",count,data[i][0],data[i][1]);
              count++;
          
      }
  }
  public static void main(String[] args)
  {
    String[][] data = readPhonebook();
    printSpreadsheet(data);

    while(true)
    {
      String option = askOption();
      data = processOption(data, option);
    }

    }
    
}
