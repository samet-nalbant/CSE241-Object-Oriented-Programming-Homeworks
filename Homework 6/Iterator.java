/**
 * iterator
 */
public class Iterator<E>{
    private int cursor,size;
    private E[] array;
    private Collection<E> col;
    Iterator(E[] otherArray,Collection<E> otherCol){
        cursor = 0;
        array = otherArray;
        size = otherArray.length;
        col = otherCol;
    }
    /**
     * Returns true if the iteration has more elements.
     */
    public boolean hasNext(){
        if(cursor < size){
            return true;
        }
        else{
            return false;
        }
    }
    /**
     * Returns the next element in the iteration and advances the iterator.
     */
    public E next(){
        return array[cursor++];
    }
    /*
    *Removes from the underlying collection the last element returned by this iterator.
    */
    public void remove()throws Exception{
        if(col instanceof queue){
            throw new Exception("It can not be done for queue");
        }
        else{
            col.remove(array[cursor]);
        }
    }
}