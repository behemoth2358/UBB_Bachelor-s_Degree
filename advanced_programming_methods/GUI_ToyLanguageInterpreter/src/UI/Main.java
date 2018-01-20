package UI;

import Interpreter.Controller.Controller;
import Interpreter.Models.Expressions.ArithmeticExpression;
import Interpreter.Models.Expressions.ConstantExpression;
import Interpreter.Models.Expressions.ReadFromHeapExpression;
import Interpreter.Models.Expressions.VariableExpression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Statements.*;
import Interpreter.Models.Tables.FileTable;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Models.Tables.SymTable;
import Interpreter.Repository.Repository;
import Interpreter.Utils.*;
import UI.Controllers.StartUpController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Views/StartUpView.fxml"));
        Parent root = loader.load();
        primaryStage.setTitle("Toy Language Interpreter");

        StartUpController controller = loader.getController();
        controller.setPrograms(getExamples());

        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public List<Example> getExamples() {
        List<Example> examples = new ArrayList<>();

        examples.add(setUpExample(example1(), "example 1"));
        examples.add(setUpExample(example2(), "example 2"));

        return examples;
    }

    public Example setUpExample(List<ProgramState> statements, String exName) {
        Repository repo = new Repository(statements, "/home/bogdanboboc97/Projects/Github/UBB_Bachelor-s_Degree/advanced_programming_methods/GUI_ToyLanguageInterpreter/src/Interpreter/logs.data");
        return new Example(new Controller(repo), exName);
    }

    public List<ProgramState> example1() {
        List<ProgramState> programs = new ArrayList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        HeapTable heapTable = new HeapTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();

        IStatement firstStatement =
                new AssignmentStatement("n",
                        new ConstantExpression(10)
                );

        IStatement secondStatement =
                new ForkStatement(
                        new CompoundStatement(
                                new AssignmentStatement(
                                        "n",
                                        new ArithmeticExpression(
                                                new VariableExpression("n"),
                                                "+",
                                                new ConstantExpression(10)
                                        )
                                ),
                                new PrintStatement(new VariableExpression("n"))
                        )
                );

        IStatement thirdStatement = new AssignmentStatement(
                "n",
                new ArithmeticExpression(
                        new VariableExpression("n"),
                        "-",
                        new ConstantExpression(10)
                )
        );
        IStatement fourthStatement = new PrintStatement(new VariableExpression("n"));

        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, heapTable, stack, output);

        programs.add(program);

        return programs;
    }

    public List<ProgramState> example2() {
        List<ProgramState> programs = new ArrayList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        HeapTable heapTable = new HeapTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();

        IStatement firstStatement = new AddInHeapStatement(
                "x",
                new ArithmeticExpression(
                        new ConstantExpression(2),
                        "*",
                        new ConstantExpression(6)
                )
        );

        IStatement secondStatement = new WriteInHeapStatement(
                "x",
                new ArithmeticExpression(
                        new ReadFromHeapExpression("x"),
                        "+",
                        new ConstantExpression(2)
                )
        );


        IStatement thirdStatement = new AssignmentStatement(
                "x",
                new ConstantExpression(2)
        );

        IStatement fourthStatement = new PrintStatement(new VariableExpression("x"));

        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, heapTable, stack, output);

        programs.add(program);

        return programs;
    }

    public static void main(String[] args) {
        launch(args);
    }
}
