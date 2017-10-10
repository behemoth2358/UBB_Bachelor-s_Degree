package com.company.Controller;

import com.company.Models.AnimalFactory;
import com.company.Models.IAnimal;
import com.company.Repository.IRepository;

import java.util.ArrayList;
import java.util.List;

public class Controller {

    private IRepository repository;

    public Controller(IRepository repository) {
        this.repository = repository;
    }

    public void add(String animalType, int animalAge) throws Exception {
        this.repository.add(AnimalFactory.create(animalType, animalAge));
    }

    public void remove(String animalType, int animalAge) {
        this.repository.remove(AnimalFactory.create(animalType, animalAge));
    }

    public IAnimal[] getAllAnimals() {
        return this.repository.getAnimals();
    }

    public List<IAnimal> getAnimalsOlderThan(int minAge) {

        List<IAnimal> res = new ArrayList<>();
        for(IAnimal animal: this.repository.getAnimals()) {
            if (animal != null && animal.getAge() >= minAge) {

                res.add(animal);
            }
        }

        return res;
    }
}
