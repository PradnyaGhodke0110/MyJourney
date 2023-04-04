import java.util.*;
class Program208
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);

        System.out.println("ENter the  size of array:");
        int iSize=sobj.nextInt();

        int Arr[]=new int[iSize];

        System.out.println("enter the elemensts of array:");
        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            Arr[iCnt]=sobj.nextInt();
        }

        int iSum=0;

        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {   
            iSum=iSum+Arr[iCnt];

        }
        System.out.println("Addition of elements is:"+iSum);
        
    }
}