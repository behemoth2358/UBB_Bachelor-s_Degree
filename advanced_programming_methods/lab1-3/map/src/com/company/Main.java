package com.company;


//8. Intr-un acvariu traiesc pesti si broaste testoase.
//
//        Sa se afiseze toate vietuitoarele din acvariu care sunt
//
//        mai batrine de 1 an.

import com.company.Controller.Controller;
import com.company.Repository.IRepository;
import com.company.Repository.MemoryRepository;
import com.company.Views.View;

public class Main {

    private static void addTestData(Controller cont) {
        try {
            cont.add("Fish", 1);
            cont.add("Tortoise", 120);
            cont.add("Fish", 2);
            cont.add("Tortoise", 101);
        } catch(Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        IRepository repo = new MemoryRepository(5);
        Controller controller = new Controller(repo);
        View view = new View(controller);

        addTestData(controller);

        view.startApp();
    }
}
