import java.io.*;
import java.util.*;

class Program12
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        try
        {
            System.out.println("Enter folder name:");
            String Foldername=sobj.nextLine();

            File fobj=new File(Foldername);

            if(fobj.exists())
            {
                File allfiles[] = fobj.listFiles();

                System.out.println("Number of files are:"+allfiles.length);
                System.out.println("Files names are:");

                for(int i=0;i<allfiles.length;i++)
                {
                    System.out.println(allfiles[i].getName()+"  " +"Size:" +allfiles[i].length());
                }
            }
            else
            {
                System.out.println("There is no such folder");
            }



        }// End of try
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    } //end of main
}   // end of class