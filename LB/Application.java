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
class Application
{
    public static void main(String args[])
    {
        DBMS dobj=new DBMS();
        

        dobj.StartDBMS();

        dobj.Insert("Kartik",90);
        dobj.Insert("pradnya",89);
        dobj.Insert("gopal",45);
        dobj.Insert("sahil",78);
        dobj.Insert("Ram",99);


        dobj.DisplayAll();
       
        dobj.DisplaySpecific(3);
        dobj.DisplaySpecific("pradnya");
        dobj.Delete(2);
        dobj.Delete("gopal");
        System.out.println("");
        System.out.println("Final data");
        dobj.DisplayAll();

        System.out.println("");
        dobj.Sum();
        System.out.println("");
        dobj.Max();
        System.out.println("");
        dobj.Min();
        System.out.println("");
        dobj.Avg();
    
    
    }
}
