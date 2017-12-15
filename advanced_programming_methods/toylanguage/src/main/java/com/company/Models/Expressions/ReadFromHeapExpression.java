package com.company.Models.Expressions;

import com.company.Models.Expression;
import com.company.Models.ProgramState.ProgramState;
import com.company.Models.Tables.HeapTable;
import com.company.Utils.MyIDictionary;

public class ReadFromHeapExpression extends Expression {
    private String variableName;

    public ReadFromHeapExpression(String variableName){
        this.variableName = variableName;
    }

    @Override
    public int eval(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symTable = state.getSymTable();
        HeapTable heapTable = state.getHeapTable();

        int address = symTable.getValue(variableName);

        return heapTable.getValue(address);
    }

    @Override
    public String toString() {
        return "ReadFromHeap(" + variableName + ")";
    }
}
