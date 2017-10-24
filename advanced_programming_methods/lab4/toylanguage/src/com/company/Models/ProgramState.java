package com.company.Models;

public class ProgramState {

    private MyIDictionary<String, Integer> symTable;
    private MyIStack<IStatement> exeStack;
    private MyIList<Integer> output;

    public ProgramState(
            MyIDictionary<String, Integer> symTable,
            MyIStack<IStatement> exeStack,
            MyIList<Integer> output) {

        this.symTable = symTable;
        this.exeStack = exeStack;
        this.output = output;
    }

    public MyIDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public MyIStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public MyIList<Integer> getOutput() {
        return this.output;
    }

    @Override
    public String toString() {

        return this.symTable.toString() + "\n" +
                this. exeStack.toString() + "\n" +
                this.output.toString() + "\n";
    }
}
