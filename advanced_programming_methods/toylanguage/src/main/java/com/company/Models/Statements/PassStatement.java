package com.company.Models.Statements;

import com.company.Models.IStatement;
import com.company.Models.ProgramState.ProgramState;

public class PassStatement implements IStatement {
    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        return null;
    }

    @Override
    public String toString() {
        return "";
    }
}
