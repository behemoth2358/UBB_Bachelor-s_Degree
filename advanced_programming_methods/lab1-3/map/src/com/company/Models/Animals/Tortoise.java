package com.company.Models.Animals;

import com.company.Models.IAnimal;

public class Tortoise implements IAnimal {

    private int age;

    public Tortoise(int age) {
        this.age = age;
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Tortoise " + this.age + " years old.";
    }

    public boolean equals(Object other) {

        if (other != null && other instanceof Tortoise) {
            Tortoise tortoise = (Tortoise)other;
            return tortoise.getAge() == this.age;
        }

        return false;
    }
}
