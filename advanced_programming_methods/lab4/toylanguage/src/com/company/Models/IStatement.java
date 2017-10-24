package com.company.Models;

public interface IStatement {
    ProgramState execute(ProgramState state) throws Exception;

    String toString();
}
