package com.company.Models;

import com.company.Models.ProgramState.ProgramState;
import com.company.Utils.MyIDictionary;

public abstract class Expression {

    public abstract int eval(ProgramState state) throws Exception;

    @Override
    public abstract String toString();
}
