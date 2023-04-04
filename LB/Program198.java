import java.util.*;
class Factor
{
    void EvenFactor(int no)
    {
        int iCnt;

        for(iCnt=2;iCnt<=no/2;iCnt+=2)
        {
            if(no%iCnt==0)
            {
                System.out.println("Factors are:"+iCnt);
            }
            

        }
    }
}
public class Program198
{
    
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        int iNo = 0,iRet=0;

        System.out.println("Enter first number : ");
        iNo = sobj.nextInt();

        Factor obj=new Factor();

        obj.EvenFactor(iNo);

    }
 
    
}
