
import java.util.*;

class Z15
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the string:");
        String str=sc.next();

        char arr[]=str.toCharArray();

        int count=0;

        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>='a' && arr[i]<='z')
            {
                count++;
            }
        }
        System.out.println(count);

    }
}