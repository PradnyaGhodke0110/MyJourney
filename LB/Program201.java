import java.util.*;
class Factor
{
    private int CountDigits(int iNo)
    {
        int iCnt=0;
        while(iNo!=0)
        {
            iCnt++;
            iNo=iNo/10;
        }
        return iCnt;

    }
    private int Power(int Base,int index)
    {
        int iAns=1;
        for(int iCnt=1;iCnt<=index;iCnt++)
        {
            iAns=iAns*Base;
        }
        return iAns;

    }
    public boolean IsArmstrong(int no)
    {
        int iTemp=no;
        int iSum=0,iDigit=0,iRet=0;
        int iCount=CountDigits(no);
         while(no!=0)
         {
            iDigit=no%10;
            iRet=Power(iDigit,iCount);
            iSum=iSum+iRet;

            no=no/10;
        }
         if(iSum==iTemp)
         {
            return true;
         }
         else
         {
            return false;
         }

    }
        
 }

public class Program201
{
    
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        int iNo = 0;
        boolean bRet;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        Factor obj=new Factor();

       bRet= obj.IsArmstrong(iNo);

       if(bRet==true)
       {
        System.out.println("No is Armstrong");
       }
       else
       {
        System.out.println("No is not Armstrong");
       }

        //System.out.println("Multiplication of "+iNo+" is "+iRet);

        

    }
 
    
}
