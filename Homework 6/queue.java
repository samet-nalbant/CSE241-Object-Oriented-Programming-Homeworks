/**
 * queue
 */
public interface queue<E> extends Collection<E>{

    public boolean add(E e);
    public E element();
    public void offer(E e);
    public E poll()throws Exception;
    
}