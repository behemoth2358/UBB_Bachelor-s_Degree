package com.company.Models.ProgramState;

import com.company.Models.ExceptionFactory;
import com.company.Models.IStatement;
import com.company.Models.Tables.HeapTable;
import com.company.Utils.MyIDictionary;
import com.company.Utils.MyIList;
import com.company.Utils.MyIStack;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.time.LocalTime;

public class ProgramState implements Cloneable {

    private MyIDictionary<String, Integer> symTable;
    private MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable;
    private HeapTable heapTable;
    private MyIStack<IStatement> exeStack;
    private MyIList<Integer> output;


    private static long countInstances;
    private long ID;

    public ProgramState(
            MyIDictionary<String, Integer> symTable,
            MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable,
            HeapTable heapTable,
            MyIStack<IStatement> exeStack,
            MyIList<Integer> output) {

        this.symTable = symTable;
        this.fileTable = fileTable;
        this.heapTable = heapTable;
        this.exeStack = exeStack;
        this.output = output;
        this.ID = ++this.countInstances;
    }

    public boolean isNotCompleted() {
        return (this.exeStack.size() > 0);
    }

    public ProgramState executeOneInstruction() throws Exception {

        if (this.exeStack.isEmpty()) {
            throw ExceptionFactory.create("stack", "stack is empty!");
        }

        IStatement statement = this.exeStack.pop();

        return statement.execute(this);
    }

    public MyIDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public MyIDictionary<Integer, Pair<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public HeapTable getHeapTable() {
        return this.heapTable;
    }

    public MyIStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public MyIList<Integer> getOutput() {
        return this.output;
    }

    @Override
    public String toString() {

        return "PROGRAM ID " + this.ID + "\n" +
                this.symTable.toString() + "\n" +
                this.fileTable.toString() + "\n" +
                this.heapTable.toString() + "\n" +
                this. exeStack.toString() + "\n" +
                this.output.toString() + "\n";
    }
}
