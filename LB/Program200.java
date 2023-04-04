import java.util.*;
class Factor
{
    int FactorMultiplication(int no)
    {
        int iCnt=0,iMult=1;

        for(iCnt=2;iCnt<=no;iCnt++)
        {
            if(no%iCnt==0)
            {
                iMult=iMult*iCnt;

            }
            

        }
        return iMult;
    }
}
public class Program200
{
    
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        int iNo = 0,iRet=0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        Factor obj=new Factor();

        iRet=obj.FactorMultiplication(iNo);

        System.out.println("Multiplication of "+iNo+" is "+iRet);

        

    }
 
    
}
