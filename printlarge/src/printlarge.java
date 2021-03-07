 import java.util.ArrayList;
public class printlarge {

    public static  void print_large(int[][] array){
    for(int i=0;i<array.length;i++)
    {
        for(int j=0;j<array[i].length;j++)
        {
            int[][] temp = null;
            array[i][j]=temp[j][i];
        System.out.printf("%d",temp[j][i]);
        
        }
         System.out.print("\n");
    }
  }
    public static void main(String[] args) {
    int[][] array1 = {{105, 10, 5},
                         {3,4,5}}; 
    print_large(array1);
    }
    
}
