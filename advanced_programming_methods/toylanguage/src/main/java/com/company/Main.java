package com.company;

import com.company.Controller.Controller;
import com.company.Models.*;
import com.company.Models.Expressions.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Models.Statements.*;
import com.company.Models.Tables.*;
import com.company.Utils.*;
import com.company.Repository.Repository;
import com.company.Views.Command;
import com.company.Views.Commands.*;
import com.company.Views.TextMenu;

import java.io.BufferedReader;
import java.util.List;
import java.util.ArrayList;


public class Main {

    public static void main(String[] args) {

        Repository repository = getRepository();

        Controller controller = new Controller(repository);

        TextMenu textMenu = new TextMenu();

        Command runProgramCommand = new RunProgramCommand("run", "Run the program", controller);
        Command exitCommand = new ExitCommand("exit", "Exit");

        textMenu.add(exitCommand);
        textMenu.add(runProgramCommand);

        textMenu.run();
    }

    private static Repository getRepository() {
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

        return new Repository(programs, "/home/bogdanboboc97/IdeaProjects/toylanguage/src/main/java/com/company/log.txt");
    }
}
