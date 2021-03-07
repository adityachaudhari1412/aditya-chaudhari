    import java.io.File;
    import java.util.*;

    public class MinimumLength {
     public static ArrayList<String> readFile(String filename)
  {
    File temp = new File(filename);
    Scanner input_file;
    try
    {
      input_file = new Scanner(temp);
    }
    catch (Exception e)
    {
      System.out.printf("Failed to open file %s\n",
                        filename);
      return null;
    }

    ArrayList<String> result = new ArrayList<String>();
    while(input_file.hasNextLine())
    {
      String line = input_file.nextLine();
      result.add(line);
    }
    
    input_file.close();
    return result;
  } 
    public static int findMinimumLength(ArrayList<String>A)
{
   if(A.size()==0)
        return -1;
    int minlength=A.get(0).length();
   int position=0;
    
    for(int i=0;i<A.size();i++)
    {                  
      if(A.get(i).length()<minlength)
      {
          minlength=A.get(i).length();
           position=i;
      }
       
    }
    
    return position;
}
public static void removeMinimumLength(ArrayList<String> A)
{
    int a=findMinimumLength(A);
    A.remove(a);
        
    }
    
    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
    
    System.out.printf("Please enter the name of the input file: ");
    String filename = in.nextLine();
    ArrayList<String> a = readFile(filename);
    if (a == null)
    {
      System.out.printf("Exiting...\n");
      System.exit(0);
    }
    
    while(true)
    {
      System.out.println(a);
      int position = findMinimumLength(a);
      System.out.printf("minimum position = %d\n\n", position);
      if (a.size() == 0)
      {
        break;
      }
      removeMinimumLength(a);
    }   
    }
    
}
