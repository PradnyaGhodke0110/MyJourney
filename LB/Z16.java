import java.util.*;
 class Z16 
 {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the string :\n");
        String str=sc.next();

        char arr[]=str.toCharArray();


        int count=0;

        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>='A' && arr[i]<='Z')
            {
                arr[i]=(char)(arr[i]+32);
            }
        }
        String str1=new String(arr);
        System.out.println(str1);


    }
    
}
