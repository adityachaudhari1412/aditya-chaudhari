/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 14693
 */ import java.util.Scanner;
public class WordStart {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.printf("Please enter a word: \n");
         String s = "";
        s += in.nextLine();
        String s= in.next();
        char s1= s.charAt(0);
        if(s1=='a'||s1=='e'||s1=='i'||s1=='o'||s1=='u'||s1=='A'||s1=='E'||s1=='I'||s1=='O'||s1=='U')
        {
            System.out.printf("%s  starts with a vowel.\n", s);
        }
        else if((s1>='a'&&s1<='z')||(s1>='A'&&s1<='Z'))
        {
            System.out.printf("%s starts with a consonant.\n", s);
        }
        else
        {
            System.out.printf("%s starts with neither a vowel nor a consonant.",s);
        }
    }
    
}
