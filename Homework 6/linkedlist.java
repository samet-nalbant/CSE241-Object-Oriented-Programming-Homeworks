/**
 * linkedlist
 */

public class linkedlist<E> implements list<E>,queue<E>{
    protected int size;
    protected E[] array;
    public linkedlist(){
        size =0;
        array = (E[])new Object[size];
    }
    /**
     * Returns an iterator over the collection.
     */
    @Override
    public Iterator iterator(){
        Iterator<E> temp = new Iterator<E>(array,this);
        return temp;
    }
    /**
     * Ensures that this collection contains the specified element.
     */
    @Override
    public boolean add(E e){
        E[] tempArray;
        tempArray = (E[])new Object[size];
        for(int i=0;i<size;i++){
            tempArray[i] = array[i];
        }
        size++;
        array = (E[])new Object[size];
        for(int i=0;i<size-1;i++){
            array[i] = tempArray[i];
        } 
        array[size-1] = e;
        return true;
    }
    /**
     * Adds all of the elements in the specified collection to this collection.
     */
    @Override
    public boolean addAll(Collection<E> c){
        Iterator<E> temp = c.iterator();
        while(temp.hasNext()!= false){
            this.add(temp.next());
        }
        return true;
    }
    /**
     * Removes all of the elements from this collection.
     */
    @Override
    public void clear(){
        for(int i=0;i<size;i++){
            array[i] = null;
        }
        size = 0;
        array = null;
    }
    /**
     * Returns true if this collection contains the specified element.
     */
    @Override
    public boolean contains(E e){
        for(int i=0;i<size;i++){
            if(array[i] == e){
                return true;
            }
        }
        return false;
    }
    /**
     * Returns true if this collection contains all of the elements in the specified collection.
     */
    @Override
    public boolean containsAll(Collection<E> c){
        Iterator<E> temp = c.iterator();
        while(temp.hasNext()!=false){
            if(this.contains(temp.next()) == false){
                return false;
            }
        }
        return true;
    }
    /**
     * Returns true if this collection contains no elements
     */
    @Override
    public boolean isEmpty(){
        for(int i=0;i<size;i++){
            if(array[i] != null){
                return false;
            }
        }
        return true;
    }
    /**
     * Removes a single instance of the specified element from this collection, if it is present.
     */
    @Override
    public boolean remove(E e){
        int flag = 0,index = 0;
        E[] tempArray;
        for(int i=0;i<size;i++){
            if(array[i] == e){
                array[i] = null;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return false;
        }
        else{
            tempArray = (E[])new Object[size-1];
            for(int i=0;i<size;i++){
                if(array[i] != null){
                    tempArray[index] = array[i];
                    index++;
                }
            }
            size--;
            array = (E[])new Object[size];
            for(int i=0;i<size;i++){
                array[i] =tempArray[i];
            }
        }
        return true;
    }
    /**
     * Removes all of this collection's elements that are also contained in the specified collection.
     */
    @Override
    public void removeAll(Collection<E> c){
        Iterator<E> temp = c.iterator();
        while(temp.hasNext()!=false){
            this.remove(temp.next());
        }       
    }
    /**
     * Retains only the elements in this collection that are contained in the specified collection.
     */
    @Override
    public void retainAll(Collection<E> c){
        Iterator<E> temp = c.iterator();
        E tempE;
        for(int i=0;i<size;i++){
            if(c.contains(array[i]) == false){
                this.remove(array[i]);
            }
        }
    }
    /**
     * Returns the number of elements in this collection.
     */
    @Override
    public int size(){
        return size;
    }
    /**
     * Inserts the specified element into this queue.
     */
    @Override
    public void offer(E e){
        this.add(e);
    }
    /**
     * Retrieves and removes the head of this queue, or throws if this queue is empty.
     */
    @Override
    public E poll()throws Exception{
        if(size == 0){
            throw new Exception("There is no element!");
        }
        E temp = array[0];
        this.remove(array[0]);
        return temp;
    }
    /**
    * Prints the elements in the linked list to terminal.
    */   
    @Override
    public void print(){
        for(int i=0;i<size;i++){
            System.out.println(array[i]);
        }
    }
    /**
     * Retrieves, but does not remove, the head of this queue.
     */
    @Override
    public E element(){
        return array[0];
    }
}