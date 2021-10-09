/**
 * Collection
 */
public interface Collection<E> {
    Iterator iterator();
    boolean add(E e);
    boolean addAll(Collection<E> c);
    void clear();
    boolean contains(E e);
    boolean containsAll(Collection<E> c);
    boolean isEmpty();
    boolean remove(E e);
    void removeAll(Collection<E> c);
    void retainAll(Collection<E> c);
    int size();
    void print();
}