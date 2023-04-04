import java.util.*;
class string2
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
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>='a' && arr[i]<='z')
            {
                Count++;
            }
        }

        System.out.println("Small characters are: "+Count);
    }
}