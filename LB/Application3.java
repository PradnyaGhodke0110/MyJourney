import java.util.*;

class Student
{
    public String Sname;
    public int marks;
    public  int RollNo;

    public static int Generator;

    static
    {
        Generator=0;
    }
    public Student(String str,int no)
    {
        this.Sname=str;
        this.marks=no;
        Generator++;
        this.RollNo=Generator;
    }
    public void Display()
    {
        System.out.println("Roll No:"+RollNo+" " +"SName:"+Sname+" " +"Marks:"+marks);
    }
} 
class DBMS
{
    public LinkedList <Student> lobj;

   public  DBMS()
    {
        lobj=new LinkedList();
    }

    public void  StartDBMS()
    {
        System.out.println("Pradnyas Customized DBMS started successfully...");

        Scanner sobj=new Scanner(System.in);
        String Query="";
        int QuerySize=0;


        while(true)
        {
            System.out.print("Marvellous DBMs:>");
            Query=sobj.nextLine();

            String Tokens[]=Query.split("");
            QuerySize=Tokens.length;

            if(QuerySize == 1)
            {
                if("help".equals(Tokens[0]))
                {
                    System.out.println("This application is used to demonstrate the fetures of customiesed dbms.");
                    System.out.println("Display all data : select * from student");
                    System.out.println("Insert new recored : insert into student values Name Marks");
                    System.out.println("Terminate the project : exit");
                    // Add more 
                }
                else if("exit".equals(Tokens[0]))
                {
                    System.out.println("Thank you for using our customised DBMS.");
                    break;
                }
            }
            else if(QuerySize==2)
            {

            }
            else if(QuerySize==3)
            {

            }
            else if(QuerySize==4)
            {
                if("select".equals(Tokens[0]))
                {
                    if("*".equals(Tokens[1]))
                    {
                        DisplayAll();
                    }        
                }
            }
            else if(QuerySize==6)
            {
                if("insert".equals(Tokens[0]))
                {
                    if("student".equals(Tokens[2]))
                    {
                        Insert(Tokens[4],Integer.parseInt(Tokens[5]));
                    }
                }
            }

        }
    }
    //All Sql queries should be implemebted here
    //insert into student values(______,_______);
    public void Insert(String str,int no)

    {
        Student sobj=new Student(str, no);
        lobj.add(sobj);

    }
    //select * from student;

    public void DisplayAll()
    {
       // Student sref;

        for(Student sref : lobj)
        {
            sref.Display();
        }
    }

    //select * from student where roll no=3

    public void DisplaySpecific(int Value)
    {
        for(Student sref:lobj)
        {
            if(sref.RollNo==Value)
            {
                sref.Display();
                break;
            }
        }
    }

    //select * from student where Name='pradnya';

    public void DisplaySpecific(String  str)
    {
        for(Student sref:lobj)
        {
            if(str.equals(sref.Sname))
            {
                sref.Display();
                break;
            }
        }
    }

    //Delete From Student where RollNo=3;

    public void Delete(int no)
    {
        int index=0;

        for(Student sref:lobj)
        {
            if(sref.RollNo==no)
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    //Delete From Student where Sname="gopal";


    public void Delete(String str)
    {
        int index=0;

        for(Student sref:lobj)
        {
            if(str.equals(sref.Sname))
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    public void Sum()
    {
        int iSum=0;

        for(Student sref:lobj)
        {
            iSum=iSum+(sref.marks);
        }
        System.out.println("Summation of marks:"+iSum);
    }

    public void Max()
    {
        int iMax=0;

        for(Student sref:lobj)
        {
            if(sref.marks>iMax)
            {
                iMax=sref.marks;
            }
        }
        System.out.println("Maximum marks Are:"+iMax);
    }

    public void Min()
    {
        Student s = lobj.get(0);

        int iMin = s.marks;

        for(Student sref:lobj)
        {
            if(sref.marks<iMin)
            {
                iMin=sref.marks;
            }
        }
        System.out.println("Minimum marks Are:"+iMin);
    }
    public void Avg()
    {
        int iSum=0;

        for(Student sref:lobj)
        {
            iSum=iSum+(sref.marks);
        }
        System.out.println("Average of marks:"+(iSum/lobj.size()));
    }
}
class Application3
{
    public static void main(String args[])
    {
        DBMS dobj=new DBMS();
        

        dobj.StartDBMS();

        
    }
}
 
