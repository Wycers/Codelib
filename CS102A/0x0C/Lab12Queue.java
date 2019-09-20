package lab12;

import java.awt.ContainerOrderFocusTraversalPolicy;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Queue;

public class Lab12Queue<E> implements Queue<E> {

	private List<E> list;

	Lab12Queue(List<E> list) {
		this.list = list;
	}

	@Override
	public boolean add(E arg) {
		try {
			list.add(arg);
		} catch (Exception e) {
			throw new IllegalStateException();
		}
		return true;
	}

	@Override
	public boolean addAll(Collection<? extends E> arg) {
		return list.addAll(arg);
	}

	@Override
	public boolean contains(Object arg) {
		return list.contains(arg);
	}

	@Override
	public boolean containsAll(Collection<?> arg) {
		return list.containsAll(arg);
	}

	@Override
	public E remove() {
		if (!isEmpty()) {
			E e = list.get(0);
			list.remove(0);
			return e;
		} else {
			throw new NoSuchElementException();
		}
	}

	@Override
	public boolean remove(Object arg) {
		return list.remove(arg);
	}

	@Override
	public boolean removeAll(Collection<?> arg) {
		return list.removeAll(arg);
	}

	@Override
	public boolean retainAll(Collection<?> arg) {
		return list.retainAll(arg);
	}

	@Override
	public int size() {
		return list.size();
	}

	@Override
	public boolean isEmpty() {
		return list.isEmpty();
	}

	@Override
	public void clear() {
		list.clear();
	}

	@Override
	public Iterator<E> iterator() {
		return list.iterator();
	}

	@Override
	public Object[] toArray() {
		return list.toArray();
	}

	@Override
	public <T> T[] toArray(T[] arg) {
		return list.toArray(arg);
	}

	@Override
	public E element() {
		if (!isEmpty()) {
			E e = list.get(0);
			return e;

		} else {
			throw new NoSuchElementException();
		}

	}

	@Override
	public boolean offer(E arg) {
		list.add(arg);
		return true;
	}

	@Override
	public E peek() {
		if (!isEmpty()) {
			E e = list.get(0);
			return e;

		} else {
			return null;
		}
	}

	@Override
	public E poll() {
		if (!isEmpty()) {
			E e = list.get(0);
			list.remove(0);
			return e;
		} else {
			return null;
		}
	}
}
