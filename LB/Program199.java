import java.util.*;
class Factor
{
    void CommonFactorDisplay(int no1,int no2)
    {
        int iCnt=0;

        System.out.println("Common factors are:");

        for(iCnt=1;(iCnt<=no1/2)&&(iCnt<=no2/2);iCnt++)
        {
            if(no1%iCnt==0 && no2%iCnt==0)
            {
                System.out.println(iCnt);
            }

        }


    }
}
public class Program199
{
    
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        int iNo1 = 0;

        System.out.println("Enter first number : ");
        iNo1 = sobj.nextInt();

        System.out.println("Enter second number : ");
        int iNo2 = sobj.nextInt();


        Factor obj=new Factor();

        obj.CommonFactorDisplay(iNo1,iNo2);

    }
 
    
}
