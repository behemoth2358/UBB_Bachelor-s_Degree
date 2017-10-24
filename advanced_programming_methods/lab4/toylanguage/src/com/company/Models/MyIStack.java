package com.company.Models;

public interface MyIStack<T> {

    void push(T element);
    T top();
    T pop();
    boolean isEmpty();
    int size();

}
