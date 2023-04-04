import java.util.*;
class string5
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("Enter string");
        String str=sobj.nextLine();

        char arr[]=str.toCharArray();

        int Count=0;

        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>='a' && arr[i]<='z')
            {
                arr[i]=(char)(arr[i]+32);
            }
        }

        String str1=new String(arr);
        
        System.out.println("String in UPPER  case letter: "+str1);

    }
}
