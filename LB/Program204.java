import java.util.*;
class ArrayX
{
    public int Arr[];
    public ArrayX(int iSize)
    {
         Arr=new int[iSize];
    }
    public void Accept()
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("Please enter "+Arr.length + "elements");

        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            System.out.println("ENter the element no:"+(iCnt+1));
            Arr[iCnt]=sobj.nextInt();

        }

    }
    public void Display()
    {
        System.out.println("Elements of array are:");
        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            System.out.println(Arr[iCnt]+"\t");
        }
        System.out.println();

    }
}
class Program204
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);
        System.out.println("ENetr the size of array that you want to create");

        int iSize=sobj.nextInt();

        ArrayX obj=new ArrayX(iSize);

        
        obj.Accept();
        obj.Display();
    }
}
