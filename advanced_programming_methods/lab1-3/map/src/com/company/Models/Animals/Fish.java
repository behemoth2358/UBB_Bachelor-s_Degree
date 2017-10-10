package com.company.Models.Animals;

import com.company.Models.IAnimal;

public class Fish implements IAnimal {

    private int age;

    public Fish(int age) {
        this.age = age;
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Fish " + this.age + " years old.";
    }

    public boolean equals(Object other) {
        if (other != null && other instanceof Fish) {
            Fish fish = (Fish)other;
            return fish.getAge() == this.age;
        }
        return false;
    }
}
