package com.company.Repository;

import com.company.Models.MyIList;

public interface IRepository<T> {
    MyIList<T> getData();
    void add(T element);
    void remove(T element);
}