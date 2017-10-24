package com.company.Models.Statements;

import com.company.Models.*;

public class PrintStatement implements IStatement {
    private Expression expression;

    public PrintStatement(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIList<Integer> output = state.getOutput();
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        int expressionOutput = this.expression.eval(symTable);

        System.out.println(expressionOutput);
        output.add(expressionOutput);

        return state;
    }

    @Override
    public String toString() {
        return "print (" + this.expression.toString() + ")";
    }
}
