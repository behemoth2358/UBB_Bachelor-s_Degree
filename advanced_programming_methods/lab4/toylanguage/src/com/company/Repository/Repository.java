package com.company.Repository;

import com.company.Models.MyIList;
import com.company.Models.MyList;

public class Repository<T> implements IRepository<T> {
    private MyIList<T> data;

    public Repository() {
        this.data = new MyList<>();
    }

    public Repository(MyIList<T> data) {
        this.data = data;
    }

    @Override
    public MyIList<T> getData() {
        return this.data;
    }

    @Override
    public void add(T element) {
        this.data.add(element);
    }

    @Override
    public void remove(T element) {

    }

}
