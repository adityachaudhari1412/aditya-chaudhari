    import java.io.PrintWriter;
    import java.util.*;
    import java.io.File;

    
    public class PrintPlayerInfo {
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
            return null;
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
    public static void printPlayerInfo(String [][]data, String player)
    {
        if(data!=null)
        {
        for(int i=1;i<data.length;i++)
        {
            if(data[i].length<data[0].length)
                   continue;
            String s1= data[i][0].toLowerCase();
            player=player.toLowerCase();
            if(s1.indexOf(player)!=-1)
            {
                
                for(int j=0;j<data[0].length;j++)
               System.out.printf("%21s: %s \n",data[0][j],data[i][j]);
                System.out.println();
            }
            
       
        }
        }
       }
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    while (true)
    {
      System.out.printf("\nEnter the name of a file to read: ");
      String filename = in.next();
      String[][] data = readSpreadsheet(filename);
      System.out.printf("\nEnter part of a player's name (or q to quit): ");
      String player = in.next();
      if (player.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      printPlayerInfo(data, player);
    }
      
  }
}
 
    
  
     

  
