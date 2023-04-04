import java.util.*;
class MarvellousX
{
    public int Display(String str)
    {
        int iCnt=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)>='A' && str.charAt(i)<='Z')
            {
                iCnt++;
            }
        }
        return iCnt;
    }
}
class Program216
{
    public static void main(String args[])
    {
        int iRet=0;
        Scanner sobj=new Scanner(System.in);

        System.out.println("ENter string:");
        String str=sobj.nextLine();

        MarvellousX obj=new MarvellousX();

        iRet=obj.Display(str);
        
        System.out.println("Numbers of small letters:"+iRet);
        }

}