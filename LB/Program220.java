import java.util.*;
class MarvellousX
{
    public int Display(String str)
    {
        int iCnt=0;
        char Arr[]=str.toCharArray();

        for(int i=0;i<Arr.length;i++)
        {
            if(Arr[i]>='A' && Arr[i]<='Z')
            {
                iCnt++;
            }
        }
        return iCnt;
    }
}
class Program220
{
    public static void main(String args[])
    {
        int iRet=0;
        Scanner sobj=new Scanner(System.in);

        System.out.println("ENter string:");
        String str=sobj.nextLine();

        MarvellousX obj=new MarvellousX();

        iRet=obj.Display(str);
        
        System.out.println("Numbers of Capital letters:"+iRet);
        }

}