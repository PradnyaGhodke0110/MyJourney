import java.util.*;
class ArrayX
{
    public int Arr[];
    int i;

    public ArrayX(int size)
    {
        Arr=new int[size];
    }

    public void Accept()
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the elements");

        for(i=0;i<Arr.length;i++)
        {
            Arr[i]=sc.nextInt();
        }
    }

    public void Display()
    {
        

        System.out.println( "elements");

        for(int i=0;i<Arr.length;i++)
        {
            System.out.println(Arr[i]+"\t");
        }
        System.out.println();
    }
}
class Z10 
{

    public static void main(String args[])
    {
    ArrayX  a=new ArrayX(5);
    a.Accept();
    a.Display();
    

    }

}
