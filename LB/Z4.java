import java.util.*;

class MarvellousX
{
     int Display(String str)
    {
        int cnt=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)>='a' && str.charAt(i)<='z')
            {
                cnt++;
            }
        }
        return cnt;
    }
}
class Z4
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the string:\n");
        String str=sc.nextLine();

        MarvellousX m1=new MarvellousX();
        int iret=m1.Display(str);

        System.out.println(iret);
    }
}
