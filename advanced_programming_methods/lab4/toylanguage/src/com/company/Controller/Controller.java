package com.company.Controller;

import com.company.Models.ExceptionFactory;
import com.company.Models.IStatement;
import com.company.Models.MyIStack;
import com.company.Models.ProgramState;
import com.company.Repository.Repository;

public class Controller {
    private Repository<ProgramState> repository;
    public boolean DEBUG = false;

    public Controller(Repository<ProgramState> repository) {
        this.repository = repository;
    }

    public ProgramState executeOneInstruction(ProgramState program) throws Exception {
        MyIStack<IStatement> stack = program.getExeStack();

        if (stack.isEmpty()) {
            throw ExceptionFactory.create("stack", "stack is empty!");
        }

        IStatement statement = stack.pop();

        if (DEBUG) {
            System.out.println(statement);
        }

        return statement.execute(program);
    }

    public void executeOne() {
        ProgramState program = this.repository.getData().get(0);

        try {
            executeOneInstruction(program);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void executeAllProgram() {
        ProgramState program = this.repository.getData().get(0);

        while(!program.getExeStack().isEmpty()) {

            try {
                executeOneInstruction(program);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

}
