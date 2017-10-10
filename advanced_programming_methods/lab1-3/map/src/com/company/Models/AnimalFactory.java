package com.company.Models;

import com.company.Models.Animals.Fish;
import com.company.Models.Animals.Tortoise;

public class AnimalFactory {

    public static IAnimal create(String name, int age) {

        if (name == null) {
            return null;
        }

        if (name.equalsIgnoreCase("tortoise")) {
            return new Tortoise(age);
        } else if( name.equalsIgnoreCase("fish")) {
            return new Fish(age);
        }

        return null;
    }
}
