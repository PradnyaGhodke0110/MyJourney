import java.util.*;
class string1
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("Enter string");
        String str=sobj.nextLine();

        char arr[]=str.toCharArray();

        System.out.println(str.length());
        System.out.println(arr.length);

    }
}