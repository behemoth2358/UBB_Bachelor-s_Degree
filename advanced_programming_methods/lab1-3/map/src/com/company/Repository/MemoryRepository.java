package com.company.Repository;

import com.company.Models.ExceptionFactory;
import com.company.Models.Exceptions.RepositoryException;
import com.company.Models.IAnimal;

public class MemoryRepository implements IRepository {

    private IAnimal[] animals;
    private int capacity, size;

    public MemoryRepository(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.animals = new IAnimal[ this.capacity ];

        this.loadData();
    }

    @Override
    public void add(IAnimal animal) throws Exception {
        if (this.size >= this.capacity) {
            throw ExceptionFactory.create("repository", "Repository is full!");
        }

        this.animals[ this.size ] = animal;
        this.size++;
    }

    @Override
    public void remove(IAnimal animal) {

        IAnimal[] new_animals = new IAnimal[ this.capacity ];
        int new_size = 0;

        for(IAnimal animal_it: this.animals) {
            if (animal_it != null && !animal_it.equals(animal)) {
                new_animals[ new_size ] = animal_it;
                new_size++;
            }
        }

        this.animals = new_animals;
        this.size = new_size;
    }

    @Override
    public IAnimal[] getAnimals() {
        return this.animals;
    }

    @Override
    public void loadData() { }

    @Override
    public void saveData() { }
}
