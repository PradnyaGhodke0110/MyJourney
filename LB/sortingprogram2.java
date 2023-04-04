import java.util.*;

class Sorting 
{
    private int Arr[];
    public Sorting(int Size)
    {
        Arr=new int[Size];
    }
    public void Accept()
    {
        Scanner  sobj=new Scanner(System.in);

        System.out.println("Enter the elements:");
        for(int i=0;i<Arr.length;i++)
        {
            Arr[i]=sobj.nextInt();
        }
    }
    public void Display()
    {
        
        System.out.println("elements of array are:");
        for(int i=0;i<Arr.length;i++)
        {
            System.out.println(Arr[i]);           
        }
    }
}
class sortingprogram2
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);

       System.out.println("enter the size of array:");
       int size=sobj.nextInt(); 

       Sorting obj=new Sorting(size);
       obj.Accept();
       obj.Display();
    }
}
