package com.company.Views;

import com.company.Controller.Controller;

import java.util.Scanner;

public class View {
    private Controller controller;
    private Scanner scanner;

    public View(Controller controller) {
        this.controller = controller;
        this.scanner = new Scanner(System.in);
    }

    public void startApp() {

        System.out.print(
                "Press 1 to execute one instruction.\n" +
                        "Press 2 to execute all program.\n" +
                        "Press 3 to execute one instruction in debug mode.\n" +
                        "Press 4 to execute all program in debug mode.\n" +
                        "Your command: "
        );

        int command = this.scanner.nextInt();

        if (command == 1) {
            try {
                this.controller.executeOne();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        if (command == 2) {
            this.controller.executeAllProgram();
        }

        if (command == 3) {
            this.controller.DEBUG = true;

            try {
                this.controller.executeOne();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        if (command == 4) {
            this.controller.DEBUG = true;

            this.controller.executeAllProgram();
        }
    }
}
