import java.util.*;
/*
  1 2 3 4
  5 6 7 8
  9 1 2 3
  4 5 6 7
  */
class Pattern
{
    public void Display(int row,int col)
    {
        int i=0,j=0,iCnt=1;;

        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
               if(iCnt==10)
                iCnt=1;
                System.out.print(iCnt+"\t");
                iCnt++;
                
            }
            System.out.println();

        }

    }
}
 class Program231

{
    public static void main(String args[])
    {
        Pattern pobj=new Pattern();
        Scanner sobj=new Scanner(System.in);

        System.out.println("enter no of rows:");
        int i=sobj.nextInt();

        System.out.println("enter no of cols:");
        int j=sobj.nextInt();
       
        pobj.Display(i,j);

    }

    
}
