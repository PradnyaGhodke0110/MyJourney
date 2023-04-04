import java.io.*;
import java.util.*;
import java.nio.charset.StandardCharsets;  

class Program23
{
    public static void main(String a[])
    {
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the string:");

        String str=sobj.nextLine();

        String Arr[]=str.split(" ");

        System.out.println("Number of words are:"+Arr.length);
        
        System.out.println("words from the string are:");
        for(int i=0;i<Arr.length;i++)
        {
            System.out.println(Arr[i]+" " +  "length : "  +Arr[i].length());
        }
    } 
}   