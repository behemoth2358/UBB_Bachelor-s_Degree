package com.company.Views;

import com.company.Controller.Controller;
import com.company.Models.IAnimal;

import java.util.List;
import java.util.Scanner;

public class View {
    private Scanner scanner;
    private Controller controller;

    public View(Controller controller) {
        this.scanner = new Scanner(System.in);
        this.controller = controller;
    }

    public void startApp() {
        while (true) {
            System.out.print("\n" +
                            "Press 0 to exit.\n" +
                            "Press 1 to add an animal.\n" +
                            "Press 2 to remove an animal.\n" +
                            "Press 3 to see all animals.\n" +
                            "Press 4 to see all animals older than a given age.\n" +
                            "Command: "
            );

            int option = scanner.nextInt();
            String type;
            int age, minAge;
            switch (option) {
                case 0:
                    System.exit(0);
                case 1:
                    System.out.print("Animal type: ");
                    type = scanner.next();
                    System.out.print("Animal age: ");
                    age = scanner.nextInt();
                    try {
                        this.controller.add(type, age);
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    break;
                case 2:
                    System.out.print("Animal type: ");
                    type = scanner.next();
                    System.out.print("Animal age: ");
                    age = scanner.nextInt();

                    this.controller.remove(type, age);
                    break;
                case 3:
                    IAnimal[] animals = this.controller.getAllAnimals();

                    for(IAnimal animal: animals) {
                        if (animal != null) {
                            System.out.println(animal);
                        }
                    }
                    break;
                case 4:
                    System.out.print("Minimum age: ");
                    minAge = scanner.nextInt();
                    List<IAnimal> res = this.controller.getAnimalsOlderThan(minAge);
                    for(IAnimal animal: res) {
                        if (animal != null) {
                            System.out.println(animal);
                        }
                    }
                    break;
                default:
                    System.out.println("Invalid command!");
                    break;
            }
        }
    }

}
