package com.company;

import com.company.Controller.Controller;
import com.company.Models.*;
import com.company.Models.Expressions.ArithmeticExpression;
import com.company.Models.Expressions.ConstantExpression;
import com.company.Models.Expressions.VariableExpression;
import com.company.Models.Statements.AssignmentStatement;
import com.company.Models.Statements.IfStatement;
import com.company.Models.Statements.PrintStatement;
import com.company.Repository.Repository;
import com.company.Views.View;

public class Main {

    public static void main(String[] args) {

        Repository<ProgramState> repository = getRepository();

        Controller controller = new Controller(repository);

        View view = new View(controller);

        view.startApp();
    }

    private static Repository<ProgramState> getRepository() {
        MyList<ProgramState> programs = new MyList<>();

        MyIDictionary<String, Integer> symTable = new SymTable<>();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();

        IStatement firstStatement =
                new AssignmentStatement("x",
                        new ArithmeticExpression(
                                new ConstantExpression(5),
                                new String("-"),
                                new ConstantExpression(5)
                        )
                );

        IStatement secondStatement = new IfStatement(
                        new VariableExpression("x"),
                        new AssignmentStatement(
                                "x",
                                new ConstantExpression(20)
                        ),
                        new AssignmentStatement(
                                "x",
                                new ArithmeticExpression(
                                        new VariableExpression("x"),
                                        "+",
                                        new ConstantExpression(1)
                                )
                        )
                );

        IStatement thirdStatement = new PrintStatement(
                new VariableExpression("x")
        );

        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, stack, output);

        programs.add(program);

        return new Repository<>(programs);
    }
}
