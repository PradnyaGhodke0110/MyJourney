import java.util.*;
class Factor
{
    void EvenFactor(int no)
    {
        int iCnt;

        for(iCnt=1;iCnt<no;iCnt++)
        {
            if(no%iCnt==0 &&  iCnt%2==0)
            {
                System.out.println("Factors are:"+iCnt);
            }
            

        }
    }
}
public class Program197
{
    
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        
        int iNo = 0;

        System.out.println("Enter first number : ");
        iNo = sobj.nextInt();

        Factor obj=new Factor();

        obj.EvenFactor(iNo);

    }
 
    
}
