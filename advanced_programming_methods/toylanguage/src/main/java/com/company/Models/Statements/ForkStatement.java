package com.company.Models.Statements;

import com.company.Models.IStatement;
import com.company.Models.ProgramState.ProgramState;
import com.company.Models.Tables.SymTable;
import com.company.Utils.*;

public class ForkStatement implements IStatement {
    IStatement statement;

    public ForkStatement(IStatement statement) {
        this.statement = statement;
    }
    @Override
    public ProgramState execute(ProgramState state) throws Exception {

        MyIStack<IStatement> newStack = new MyStack<>();
        newStack.push(statement);

        return new ProgramState(
                new SymTable((SymTable) state.getSymTable()),
                state.getFileTable(),
                state.getHeapTable(),
                newStack,
                state.getOutput()
        );
    }

    @Override
    public String toString() {
        return "Fork(\n" + statement + "\nn)";
    }
}
