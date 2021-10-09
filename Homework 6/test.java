import java.util.HashSet;
import java.util.LinkedList;

/**
 * test
 */
public class test {
    public static void main(String[] argsv){
        hashset<Integer> set1 = new hashset<Integer>();
        arraylist<Integer> list1 = new arraylist<Integer>();
        linkedlist<Integer> list2 = new linkedlist<Integer>();
        linkedlist<Integer> list3 = new linkedlist<Integer>();  
        for(int i=0;i<3;i++){
            list1.add(i*2);
            list2.add(i*3); 
            set1.add(i);
        }
        list1.add(9);
        list1.add(7);
        set1.add(4);
        set1.add(0);
        System.out.println("Elements of Array List:");
        list1.print();
        System.out.println("------------------");
        System.out.println("Elements of Linked List:");
        list2.print();        
        System.out.println("------------------");
        System.out.println("Elements of HashSet:");
        set1.print();
        System.out.println("------------------");        
        System.out.println("After the Array List added to Linked List:");
        list2.addAll(list1);
        list2.print();
        System.out.println("------------------");             
        System.out.println("After the clear Linked List:");
        list2.clear();
        list2.print();
        System.out.println("------------------");             
        System.out.println("Check the Array List whether contain 0 or not:");
        System.out.println(list1.contains(0));
        System.out.println("Check the Array List whether contain Hash Set elements or not:");
        System.out.println(list1.containsAll(set1));
        System.out.println("Check the Array List whether empty or not:");
        System.out.println(list1.isEmpty());
        System.out.println("Check the Linked List whether empty or not:");
        System.out.println(list2.isEmpty());
        System.out.println("After the '0' removed from Hash Set.");
        set1.remove(0);
        set1.print();
        System.out.println("------------------");             
        set1.add(0);
        set1.add(2);
        System.out.println("Before the remove all called.Hash Set:");
        set1.print();
        System.out.println("------------------");             
        System.out.println("Before the remove all called.Array List:");
        list1.print();
        System.out.println("------------------");     
        System.out.println("After the remove all called for Array List which take as a argument Hash Set:");
        list1.removeAll(set1);
        list1.print();
        System.out.println("------------------");             
        System.out.println("Size of the Array List:");
        System.out.println(list1.size());  
        System.out.println("After the retain all called for Array List which take as a argument Hash Set:");
        list1.retainAll(set1);            
        list1.print();    
        System.out.println("Before the queue's functions called Linked List:");
        list2.add(2);
        list2.add(1);
        list2.add(3);
        list2.add(4);
        list2.add(0);
        list2.add(4);
        list2.offer(5);
        list2.print();
        System.out.println("Head of the Linked List:");        
        System.out.println(list2.element());
        System.out.println("Removed element of Empty Linked List:");
        try {
            System.out.println(list3.poll());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }     
}
