import java.util.*;
class Pattern
{
    public void Display(int iNo)

    {
        //char Arr[]=str.toCharArray();
        int iDigit=0;

        while(iNo%10!=0)
        {
            iDigit=iNo%10;
            System.out.print(iDigit+"\t");
            iNo=iNo/10;

        }
        System.out.println();
        } 
    }


class Program238
{
    public static void main(String a[])
    {
        Pattern pobj = new Pattern();
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number: ");
        int i = sobj.nextInt();

        pobj.Display(i);
    }
}