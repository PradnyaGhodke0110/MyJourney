 import java.util.*;
class ArrayX
{
    protected int Arr[];
    public ArrayX(int iSize)
    {
         Arr=new int[iSize];
    }
    protected void Accept()
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("Please enter "+Arr.length + "elements");

        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            System.out.println("ENter the element no:"+(iCnt+1));
            Arr[iCnt]=sobj.nextInt();

        }

    }
    protected void Display()
    {
        System.out.println("Elements of array are:");
        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            System.out.println(Arr[iCnt]+"\t");
        }
        System.out.println();

    }
}
class MarvellousX extends ArrayX
{
    public MarvellousX(int iSize)
    {
        super(iSize);
    }
    public boolean Checkpalindrome()
    {
       int iStart=0;
       int iEnd=Arr.length-1;
        boolean flag=true;

       while(iStart<iEnd)
       {
            if(Arr[iStart] != Arr[iEnd])
            {
                flag =false;
                break;

            }
        iStart++;
        iEnd--;
       }
       return flag;
 
       }
   }
class Program210

{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("ENetr the size of array that you want to create");

        int iSize=sobj.nextInt();

        MarvellousX obj=new MarvellousX(iSize);

        
        obj.Accept();
        obj.Display();
       

        boolean bRet=obj.Checkpalindrome();

        if(bRet==true)
        {
            System.out.println("Number is palindrormw:");
         }
         else
         {
            System.out.println("Number is not palindrormw:");
         

         }

    }
}
 
 
