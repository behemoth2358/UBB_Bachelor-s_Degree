package com.company.Repository;

import com.company.Models.Utils.MyIList;
import com.company.Models.ProgramState;

public interface IRepository {
    MyIList<ProgramState> getData();
    void add(ProgramState element);
    void remove(ProgramState element);
    void logProgramState() throws Exception;
}