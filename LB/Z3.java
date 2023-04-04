import java.util.*;
class Demo
{

}
class Z3
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the String:\n");
        String str=sc.nextLine();

        char ch[]=str.toCharArray();
        int count=0;
        for(int i=0;i<ch.length;i++)
        {
            if(ch[i]>='a' && ch[i]<='z')
            {
                count++;
            }
        }
        System.out.println(count);


    }
}