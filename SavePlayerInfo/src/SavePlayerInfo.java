    import java.io.PrintWriter;
import java.util.*;
import java.io.File;

    
    public class SavePlayerInfo {
    
    
   
    
    
    
  public static ArrayList<String> readfile(String filename)
    {
        File temp =new File(filename);
        Scanner in;
        try{
            in=new Scanner(temp);
        }
        catch (Exception e)
        {
            System.out.printf("Failed to open file %s \n", filename);
            return null;
        }
        ArrayList<String>result= new ArrayList();
        while (in.hasNextLine())
        {
         String line=in.nextLine();
         result.add(line);
        }
        in.close();
        return result;
    }
  public static String [][]readSpreadsheet(String filename)
  {
      ArrayList<String> lines=readfile(filename);
      if(lines==null)
          return null;
      String [][]result=new String[lines.size()][];
      for(int i=0;i<lines.size();i++)
      {
          String line=lines.get(i);
          String []value=line.split(",");
          result[i]=value;
      }
      return result;
  }
  public static void savePlayerInfo(String [][]data, String player, String outfile)
  {
      PrintWriter out=null;
      try{
          out = new PrintWriter(outfile);
          
      }
      catch (Exception e)
      {
          System.out.printf("Failed to open file %s for writing",outfile);
          
      }
    if(data!=null)
    {
      for(int i=0;i<data.length;i++)
      {
          
           if(data[i].length<data[0].length)
                   continue;
          String s1=data[i][0].toLowerCase();
          player=player.toLowerCase();
          if(s1.indexOf(player)!=-1)
              for(int j=0;j<data[0].length;j++)
                  out.printf("%20s:%s \n",data[0][j],data[i][j]);
          out.println();
      }
    }
    else
        out.println();
      out.close();
      
  }
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    while (true)
    {
      System.out.printf("\nEnter the name of a file to read: ");
      String input_name = in.next();
      System.out.printf("\nEnter the name of the output file: ");
      String output_name = in.next();
      String[][] data = readSpreadsheet(input_name);
      System.out.printf("\nEnter part of a player's name (or q to quit): ");
      String player = in.next();
      if (player.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      savePlayerInfo(data, player, output_name);
    }
  }
}

