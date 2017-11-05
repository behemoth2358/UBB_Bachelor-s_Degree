package com.company.Models;

import com.company.Models.Utils.MyIDictionary;

public abstract class Expression {

    public abstract int eval(MyIDictionary<String, Integer> symTable) throws Exception;

    @Override
    public abstract String toString();
}
