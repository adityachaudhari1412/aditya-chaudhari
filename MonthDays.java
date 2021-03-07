
    import java.util.Scanner;
    public class MonthDays {
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
      
      if (result <= 0)
      {
        System.out.printf("%s is <= 0, try again.\n\n", s);
        continue;
      }
      return result;
    }
  }
     public static boolean isLeapYear(int year) 
  {
    if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
    { return true; }        
        else
    {   return false; }
  }
 
    public static int yearDays(int year){
     boolean isLeap = isLeapYear(year);
    if (isLeap)
        return 366;
    else 
        return 365;
}

    public static int  monthDays(int year,int month)
    {
      int result = 0;
    if (month == 1 || month == 3 || month == 5 || month ==7 || month == 8 || month == 10 || month == 12 )
         result = 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        result = 30;
    else if (month == 2 && isLeapYear(year)==true)
        result = 29;
    else if (month == 2 && isLeapYear(year)==false)
        result = 28;
return result;
}
    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
    
    while (true)
    {
      int year = userInteger("Enter a year (must be > 0): ");      
      int month = userInteger("Enter a month (must be between 1 and 12): ");
      if (month > 12)
      {
        System.out.printf("Invalid month.\n\n");
        continue;
      }

      int result = yearDays(year);
      int result2 = monthDays(year, month);

      System.out.printf("Year %d has %d days.\n", year, result);
      System.out.printf("Month %d, %d has %d days.\n\n", month, year, result2);
    } 
  
    }
    
}
