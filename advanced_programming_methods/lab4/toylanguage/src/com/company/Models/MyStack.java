package com.company.Models;

import java.util.ArrayList;
import java.util.List;

public class MyStack<T> implements MyIStack<T> {

    MyList<T> stack;

    public MyStack() {
        stack = new MyList<T>();
    }

    @Override
    public void push(T element) {
        stack.add(element);
    }

    @Override
    public T top() {
        return stack.get(stack.size() - 1);
    }

    @Override
    public T pop() {
        T element = stack.get(stack.size() - 1);
        stack.remove(stack.size() - 1);

        return element;
    }

    @Override
    public boolean isEmpty() {
        return stack.size() == 0;
    }

    @Override
    public int size() {
        return stack.size();
    }

    @Override
    public String toString() {
        return "Stack " + this.stack.toString();
    }
}
