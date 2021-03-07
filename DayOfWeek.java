    import java.util.Scanner;
    public class DayOfWeek {
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
    public static int monthDays(int year,int month)
{    
    int result = 0;
    if (month == 1 || month == 3 || month == 5 || month ==7 || month == 8 || month == 10 || month == 12 )
         result = 31;
    else if ( month == 4 || month == 6 || month == 9 || month == 11)
        result = 30;
    else if (month == 2 && isLeapYear(year)==true )
        result = 29;
    else if (month == 2 && isLeapYear(year)==false)
        result = 28;
return result;
}
    public static int daysPassed(int year, int month, int day)
    {
        int days = 0;
        
        
        for (int i = 1000;i<year;i++)
        {    days = yearDays(i)+days; }
        
        for (int a = 1;a<month;a++)
        {days= monthDays(year,a)+days; }
        days = day + days;
        return days;
    }
    public static String dayOfWeek(int year, int month, int day)
    {
        int result = daysPassed(year,month,day);
        String day_name = "a";
        if (result % 7 == 0) 
        {
         day_name = "Tuesday";   
        }
        if (result % 7 == 1) 
        {
         day_name = "Wednesday";   
        }
        if (result % 7 == 2) 
        {
         day_name = "Thursday";   
        }
        if (result % 7 == 3) 
        {
         day_name = "Friday";   
        }
        if (result % 7 == 4) 
        {
         day_name = "Saturday";   
        }
        if (result % 7 == 5) 
        {
         day_name = "Sunday";   
        }
        if (result % 7 == 6) 
        {
         day_name = "Monday";   
        }
        return day_name;
    }
  
    
    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
    
    while (true)
    {
      int year = userInteger("Enter a year (must be >= 1000): ");      
      if (year < 1000)
      {
        System.out.printf("Invalid year.\n\n");
        continue;
      }

      int month = userInteger("Enter a month(must be between 1 and 12): ");
      if (month > 12)
      {
        System.out.printf("Invalid month.\n\n");
        continue;
      }
      
      int day = userInteger("Enter a day: ");
      
      int result = daysPassed(year, month, day);
      System.out.printf("%d days have passed from 12/31/999 to %d/%d/%d.\n", 
                        result, month, day, year);
      
      String day_name = dayOfWeek(year, month, day);
      System.out.printf("%d/%d/%d is a %s.\n\n", month, day, year, day_name);
    }
    }
    
}
