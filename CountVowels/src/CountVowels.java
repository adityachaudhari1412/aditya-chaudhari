    import java.util.Scanner;
    import java.util.ArrayList;
    import java.io.File;
    public class CountVowels {
     public static ArrayList<String> fileread(String namefile)
    {
        File in=new File(namefile);
        Scanner read;
        try
        {
            read=new Scanner(in);
            
        }
        catch (Exception e)
        {
            System.out.println("Error in opening file for reading");
            return null;
        }
        ArrayList<String> result= new ArrayList();
        while(read.hasNextLine())
        {
            String line=read.nextLine();
            result.add(line);
        }  
          read.close();
                  return result;
    }
    
  public static int filelength(String namefile)
  {
    ArrayList<String> lines = fileread(namefile);
    if (lines == null)
    {
      return 0;
    }

    int length = 0;
    for (int j = 0; j < lines.size(); j++)
    {
      String line = lines.get(j);
      length += line.length();
    }
    
    return length;
  }
    public static void countVowels(String infile)
    {
        int acount=0,ecount=0,icount=0,ocount=0,ucount=0;
        ArrayList<String> lines=fileread(infile);
       for(int j=0;j<lines.size();j++)
       {
         String line=lines.get(j);
         if(line==null)
      {
          System.out.printf("Failed to open file %s\n");
      }
         for(int i=0;i<line.length();i++)
         {
           if("a".indexOf(line.charAt(i))>=0)
               acount++;
           else if("e".indexOf(line.charAt(i))>=0)
               ecount++;
           else if("i".indexOf(line.charAt(i))>=0)
               icount++;
           else if("o".indexOf(line.charAt(i))>=0)
               ocount++;    
          else if("u".indexOf(line.charAt(i))>=0)
               ucount++;    
          else if("A".indexOf(line.charAt(i))>=0)
               acount++;
          else if("E".indexOf(line.charAt(i))>=0)
               ecount++;
          else if("I".indexOf(line.charAt(i))>=0)
               icount++;
          else if("O".indexOf(line.charAt(i))>=0)
               ocount++;
          else if("U".indexOf(line.charAt(i))>=0)
               ucount++;     
         }
    }
       System.out.printf("a: %d times \n",acount);
       System.out.printf("e: %d times \n",ecount);
       System.out.printf("i: %d times \n",icount);
       System.out.printf("o: %d times \n",ocount);
       System.out.printf("u: %d times \n",ucount);
       
    }
    
    public static void main(String[] args) {
     countVowels("in5.txt");  
    }
    
}
