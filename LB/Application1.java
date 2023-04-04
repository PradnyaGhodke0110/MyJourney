import java.util.*;
 class Application1 
 {
    public static void main(String args[])
    {
        LinkedList <Integer>obj=new LinkedList();
        obj.add(11);
        
        obj.addLast(789);
        obj.add(21); 
        obj.add(51);

        obj.remove(0);//11 will remove
        

        System.out.println("data is:"+obj);
    }
    
}
