import java.util.*;

class Program192

{
    static int Addition(int i,int j)
    {
        int iSum=0;
        iSum=i+j;
        return iSum;
    }
    public  static void main(String args[])
     {
        Scanner sc = new Scanner(System.in);

        int iNo1=0,iNo2=0,iAns=0;

        System.out.println("Enter the First No");
        iNo1=sc.nextInt();

        System.out.println("Enter the Second No");
        iNo2=sc.nextInt();

        iAns=Addition(iNo1,iNo2);

        System.out.println("Addition is:"+iAns);
        
        
    }
    
}
