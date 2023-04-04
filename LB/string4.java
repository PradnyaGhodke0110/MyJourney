import java.util.*;
class string4
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("Enter string");
        String str=sobj.nextLine();

        char arr[]=str.toCharArray();

        System.out.println(str.length());
        System.out.println(arr.length);

        int Count=0;
        int i=0;
        
        while(i<arr.length)
        {
            if(arr[i]>='a' && arr[i]<='z')
            {
                Count++;
            }
        }
        i++;

        System.out.println("Small characters are: "+Count);
    }
}