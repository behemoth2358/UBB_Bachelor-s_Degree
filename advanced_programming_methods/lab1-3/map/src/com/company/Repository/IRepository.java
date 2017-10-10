package com.company.Repository;

import com.company.Models.Exceptions.RepositoryException;
import com.company.Models.IAnimal;

public interface IRepository {

    void add(IAnimal obj) throws Exception;
    void remove(IAnimal obj);
    IAnimal[] getAnimals();
    void loadData();
    void saveData();
}
