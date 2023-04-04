import java.util.*;

interface Marvellous
{
    public void BubbleSort();
    public void SelectionSort();
    public void InsertionSort();
}
class Sorting implements Marvellous
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
    public void InsertionSort()
    {

        int i=0,j=0,selected=0;

        for(i=1;i<Arr.length;i++)
        {
            for(j=i-1,selected=Arr[i];(j>=0) && (Arr[j]>selected);j--)
            {
                Arr[j+1]=Arr[j];
            }
            Arr[j+1]=selected;
        }

    }
    public void SelectionSort()
    {
        int i=0,j=0,min_index=0,temp=0;

        for(j=0;j<Arr.length-1;j++)
        {
            if(Arr[j]<Arr[min_index])
            {
                min_index=j;
            }
        }
    }
    public void BubbleSort()
    {
        int i=0,j=0,temp=0;
        boolean flag =false;
            
        
        for(i=0;i<Arr.length;i++)
        {
             for(j=0;j<Arr.length-i-1;j++)
            {
                if(Arr[j]>Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;
                    flag =true;
                }
            }
            if(flag==false)
            {
                break;
            }
        }
    }
}
class sortingprogram5
{
    public static void main(String args[])
    {
        Scanner sobj=new Scanner(System.in);

       System.out.println("enter the size of array:");
       int size=sobj.nextInt(); 

       Sorting obj=new Sorting(size);
       obj.Accept();
       obj.Display();

       obj.SelectionSort();
       obj.Display();
       //obj.Display();
    
    }
}
