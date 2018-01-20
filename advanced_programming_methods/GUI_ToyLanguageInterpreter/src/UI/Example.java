package UI;

import Interpreter.Controller.Controller;

public class Example {
    private Controller controller;
    private String name;

    public Example(Controller controller, String name) {
        this.controller = controller;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public Controller getController() {
        return controller;
    }
}
